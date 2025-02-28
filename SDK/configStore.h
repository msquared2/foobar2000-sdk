#pragma once

#define FOOBAR2000_HAVE_CONFIGSTORE FOOBAR2020

#include <functional>
#include "commonObjects.h"

namespace fb2k {

class configStoreNotify {
public:
	virtual void onVarChange() = 0;
};

typedef void * configStoreNotifyHandle_t;

//! \since 2.0
//! Interface to access foobar2000's configuration store, backed by SQLite database. \n
//! get* methods can be called at any time. set*/delete* \n
//! set*/delete* methods will trigger immediate commit when invoked without a transaction scope. \n
//! Use commitBlocking() to commit synchronously to be sure that the data has been flushed before continuing execution.
class configStore : public service_base {
	FB2K_MAKE_SERVICE_COREAPI( configStore );
public:
    //! Causes multiple writes to be chained together. \n
    //! Use of this is no longer essential since late foobar2000 v2.0 betas, as delay-write cache is always used. \n
    //! You can still use it to guarantee that multiple updates are written together, that is either all or none are saved, should the system or application crash.
    virtual fb2k::objRef acquireTransactionScope() = 0;

    //! Synchronously flushes changes to disk. Doesn't return until changes have actually been written. \n
    //! Use of this is strongly recommended against.
    virtual void commitBlocking() = 0;
    
    virtual int64_t getConfigInt( const char * name, int64_t defVal = 0 ) = 0;
    virtual void setConfigInt( const char * name, int64_t val ) = 0;
    virtual void deleteConfigInt(const char * name) = 0;

    virtual fb2k::stringRef getConfigString( const char * name, fb2k::stringRef defaVal = fb2k::string::stringWithString("")) = 0;
    virtual void setConfigString( const char * name, const char * value ) = 0;
    virtual void deleteConfigString(const char * name) = 0;
    
    virtual fb2k::memBlockRef getConfigBlob( const char * name, fb2k::memBlockRef defVal = fb2k::memBlock::empty()) = 0;
    virtual void setConfigBlob(const char* name, const void* ptr, size_t bytes) = 0;
    virtual void setConfigBlob(const char* name, fb2k::memBlockRef val) = 0;
    virtual void deleteConfigBlob(const char * name) = 0;
    
    virtual double getConfigFloat( const char * name, double defVal = 0) = 0;
    virtual void setConfigFloat( const char * name, double val ) = 0;
    virtual void deleteConfigFloat( const char * name ) = 0;

	virtual void addNotify(const char * name, configStoreNotify * notify) = 0;
	virtual void removeNotify(const char * name, configStoreNotify * notify) = 0;

    //! Lists values of any type in the specified domain.
    //! For an example, calling with domain "foo" will return all foo.* keys, such as: foo.bar, foo.bar.2000, foo.asdf. Will not return "foobar".
    virtual fb2k::arrayRef listDomainValues(const char* domain, bool withSubdomains) = 0;

	objRef addNotify( const char * name, std::function<void () > f );
	void addPermanentNotify( const char * name, std::function<void () > f );
    
    //! Helper around getConfigInt.
    bool getConfigBool( const char * name, bool defVal = false );
    //! Helper around setConfigInt.
    void setConfigBool( const char * name, bool val );
    //! Helper around setConfigInt.
    bool toggleConfigBool (const char * name, bool defVal = false );
    //! Helper around deleteConfigInt.
    void deleteConfigBool( const char * name );
    
    //! Helper around getConfigString.
    GUID getConfigGUID(const char* name, const GUID& defVal = pfc::guid_null);
    //! Helper around setConfigString.
    void setConfigGUID(const char* name, const GUID& val);
    //! Helper around deleteConfigString.
    void deleteConfigGUID(const char* name);
    
	//! For internal core use, notifies everyone interested about off-process change to configuration data.
	virtual void callNotify(const char * name) = 0;

    fb2k::stringRef getConfigString( const char * name, const char * defVal ) { return getConfigString(name, defVal ? fb2k::makeString(defVal) : nullptr); }
    fb2k::stringRef getConfigString( const char * name, std::nullptr_t ) { return getConfigString(name, fb2k::stringRef ( nullptr ) ); }
};

struct configEventHandle_;
typedef configEventHandle_ * configEventHandle_t;

class configEvent {
public:
	configEvent(const char * name) : m_name(name) {}
	configEventHandle_t operator+=(std::function< void() >) const;
	void operator-=(configEventHandle_t) const;
private:
	const char * const m_name;
};

class configEventRef {
public:
    configEventRef() : m_name(), m_handle() {}
    ~configEventRef();
    configEventRef & operator<< ( const char * name );
    configEventRef & operator<< ( std::function<void () > f );
    void clear();
    void set( const char * name, std::function<void () > f );
    void setName( const char * name );
    void setFunction( std::function<void()> f);
    bool isActive() const { return m_handle != nullptr; }
private:
    pfc::string8 m_name;
    configEventHandle_t m_handle;
    
    configEventRef( const configEventRef & ) = delete;
    void operator=( const configEventRef & ) = delete;
};
/*
Usage example:
using namespace fb2k;
static_api_ptr_t<configStore> api;
stringRef val = api->getConfigString( "myComponent.foo", "defaultVal" );

 {
    auto scope = api->acquireTransactionScope();
    int64_t v = api->getConfigInt("myComponent.somevar" );
    v ++;
    api->setConfigInt("myComponent.somevar", v);
    api->setConfigString("myComponent.foo", "bar" );
    // commit is triggered when leaving scope
    
    // If you want to deterministically ensure that the data has been written before leaving scope,
    // for an example when another process is about to read it,
    // use api->commitBlocking()
 }
*/


//! \since 2.2
class configStore2 : public configStore {
    FB2K_MAKE_SERVICE_COREAPI_EXTENSION(configStore2, configStore);
public:
    // Use flagSuppressCache to prevent value from being cached. Prevents memory usage creep if querying lots of uniquely named variables.
    static constexpr uint32_t flagSuppressCache = 1;
    
    virtual int64_t getConfigInt2( const char * name, int64_t defVal = 0, uint32_t flags = 0 ) = 0;
    virtual void setConfigInt2( const char * name, int64_t val, uint32_t flags = 0 ) = 0;
    virtual void deleteConfigInt2(const char * name, uint32_t flags = 0) = 0;

    virtual fb2k::stringRef getConfigString2( const char * name, fb2k::stringRef defaVal = fb2k::string::stringWithString(""), uint32_t flags = 0) = 0;
    virtual void setConfigString2( const char * name, const char * value, uint32_t flags = 0 ) = 0;
    virtual void deleteConfigString2(const char * name, uint32_t flags = 0) = 0;
    
    virtual fb2k::memBlockRef getConfigBlob2( const char * name, fb2k::memBlockRef defVal = fb2k::memBlock::empty(), uint32_t flags = 0) = 0;
    virtual void setConfigBlob2(const char* name, const void* ptr, size_t bytes, uint32_t flags = 0) = 0;
    virtual void setConfigBlob2(const char* name, fb2k::memBlockRef val, uint32_t flags = 0) = 0;
    virtual void deleteConfigBlob2(const char * name, uint32_t flags = 0) = 0;
    
    virtual double getConfigFloat2( const char * name, double defVal = 0, uint32_t flags = 0) = 0;
    virtual void setConfigFloat2( const char * name, double val, uint32_t flags = 0) = 0;
    virtual void deleteConfigFloat2( const char * name, uint32_t flags = 0) = 0;
    
    
    int64_t getConfigInt( const char * name, int64_t defVal ) override final { return getConfigInt2(name, defVal); }
    void setConfigInt( const char * name, int64_t val ) override final { setConfigInt2(name, val); }
    void deleteConfigInt(const char * name) override final { deleteConfigInt2(name); }

    fb2k::stringRef getConfigString( const char * name, fb2k::stringRef defaVal) override final { return getConfigString2(name, defaVal); }
    void setConfigString( const char * name, const char * value ) override final { setConfigString2(name, value); }
    void deleteConfigString(const char * name) override final { deleteConfigString2(name); }
    
    fb2k::memBlockRef getConfigBlob( const char * name, fb2k::memBlockRef defVal ) override final { return getConfigBlob2(name, defVal); }
    void setConfigBlob(const char* name, const void* ptr, size_t bytes) override final { setConfigBlob2(name, ptr, bytes); }
    void setConfigBlob(const char* name, fb2k::memBlockRef val) override final { setConfigBlob2(name, val); }
    void deleteConfigBlob(const char * name) override final { deleteConfigBlob2(name); }
    
    double getConfigFloat( const char * name, double defVal ) override final { return getConfigFloat2(name, defVal); }
    void setConfigFloat( const char * name, double val ) override final { setConfigFloat2(name, val); }
    void deleteConfigFloat( const char * name ) override final { deleteConfigFloat2(name); }
};
} // namespace fb2k
