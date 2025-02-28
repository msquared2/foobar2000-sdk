#pragma once

class preferences_state {
public:
    enum {
        changed = 1,
        needs_restart = 2,
        needs_restart_playback = 4,
        resettable = 8,

        //! \since 1.1
        //! Indicates that the dialog is currently busy and cannot be applied or cancelled. Do not use without a good reason! \n
        //! This flag was introduced in 1.1. It will not be respected in earlier foobar2000 versions. It is recommended not to use this flag unless you are absolutely sure that you need it and take appropriate precautions. \n
        //! Note that this has no power to entirely prevent your preferences page from being destroyed/cancelled as a result of app shutdown if the user dismisses the warnings, but you won't be getting an "apply" call while this is set.
        busy = 16,

        //! \since 1.4.1
        needs_rescan_library = 32,

        //! \since 2.0
        dark_mode_supported = 1 << 16,
    };
};

//! Implementing this service will generate a page in preferences dialog. Use preferences_page_factory_t template to register. \n
//! In 1.0 and newer you should always derive from preferences_page_v3 rather than from preferences_page directly.
class NOVTABLE preferences_page : public service_base {
public:
#ifdef _WIN32
	//! Obsolete.
	virtual fb2k::hwnd_t create(fb2k::hwnd_t p_parent) { (void)p_parent; uBugCheck(); }
#endif
    
#ifdef __APPLE__
    //! Returns fb2k::NSObjectWrapper holding your NSViewController
    virtual service_ptr instantiate( ) = 0;
#endif
    
	//! Retrieves name of the preferences page to be displayed in preferences tree (static string).
	virtual const char * get_name() = 0;
	//! Retrieves GUID of the page.
	virtual GUID get_guid() = 0;
	//! Retrieves GUID of parent page/branch of this page. See preferences_page::guid_* constants for list of standard parent GUIDs. Can also be a GUID of another page or a branch (see: preferences_branch).
	virtual GUID get_parent_guid() = 0;
#ifdef _WIN32
	//! Obsolete.
    virtual bool reset_query() { return false; }
	//! Obsolete.
    virtual void reset() {}
#endif
	//! Retrieves help URL. Without overriding it, it will redirect to foobar2000 wiki.
	virtual bool get_help_url(pfc::string_base & p_out);

	static void get_help_url_helper(pfc::string_base & out, const char * category, const GUID & id, const char * name);
	
	static const GUID guid_root, guid_hidden, guid_tools,guid_core,guid_display,guid_playback,guid_visualisations,guid_input,guid_tag_writing,guid_media_library, guid_tagging, guid_output, guid_advanced, guid_components, guid_dsp, guid_shell, guid_keyboard_shortcuts;
	//! \since 1.5
	static const GUID guid_input_info_filter;
    
    double get_sort_priority_();

	FB2K_MAKE_SERVICE_INTERFACE_ENTRYPOINT(preferences_page);
};

class NOVTABLE preferences_page_v2 : public preferences_page {
public:
	//! Allows custom sorting order of preferences pages. Return lower value for higher priority (lower resulting index in the list). When sorting priority of two items matches, alphabetic sorting is used. Return 0 to use default alphabetic sorting without overriding priority.
	virtual double get_sort_priority() {return 0;}

	FB2K_MAKE_SERVICE_INTERFACE(preferences_page_v2,preferences_page);
};

template<class T>
class preferences_page_factory_t : public service_factory_single_t<T> {};

//! Creates a preferences branch - an empty page that only serves as a parent for other pages and is hidden when no child pages exist. Instead of implementing this, simply use preferences_branch_factory class to declare a preferences branch with specified parameters.
class NOVTABLE preferences_branch : public service_base {
public:
	//! Retrieves name of the preferences branch.
	virtual const char * get_name() = 0;
	//! Retrieves GUID of the preferences branch. Use this GUID as parent GUID for pages/branches nested in this branch.
	virtual GUID get_guid() = 0;
	//! Retrieves GUID of parent page/branch of this branch. See preferences_page::guid_* constants for list of standard parent GUIDs. Can also be a GUID of another branch or a page.
	virtual GUID get_parent_guid() = 0;
	

	FB2K_MAKE_SERVICE_INTERFACE_ENTRYPOINT(preferences_branch);
};

class preferences_branch_v2 : public preferences_branch {
public:
	//! Allows custom sorting order of preferences pages. Return lower value for higher priority (lower resulting index in the list). When sorting priority of two items matches, alphabetic sorting is used. Return 0 to use default alphabetic sorting without overriding priority.
	virtual double get_sort_priority() {return 0;}

	FB2K_MAKE_SERVICE_INTERFACE(preferences_branch_v2,preferences_branch);
};

class preferences_branch_impl : public preferences_branch_v2 {
public:
	preferences_branch_impl(const GUID & p_guid,const GUID & p_parent,const char * p_name,double p_sort_priority = 0) : m_guid(p_guid), m_parent(p_parent), m_name(p_name), m_sort_priority(p_sort_priority) {}
	const char * get_name() {return m_name;}
	GUID get_guid() {return m_guid;}
	GUID get_parent_guid() {return m_parent;}
	double get_sort_priority() {return m_sort_priority;}
private:
	const GUID m_guid,m_parent;
	const pfc::string8 m_name;
	const double m_sort_priority;
};

typedef service_factory_single_t<preferences_branch_impl> _preferences_branch_factory;

//! Instantiating this class declares a preferences branch with specified parameters.\n
//! Usage: static preferences_branch_factory g_mybranch(mybranchguid,parentbranchguid,"name of my preferences branch goes here");
class preferences_branch_factory : public _preferences_branch_factory {
public:
	preferences_branch_factory(const GUID & p_guid,const GUID & p_parent,const char * p_name,double p_sort_priority = 0) : _preferences_branch_factory(p_guid,p_parent,p_name,p_sort_priority) {}
};


#ifdef _WIN32
class preferences_page_callback : public service_base {
	FB2K_MAKE_SERVICE_INTERFACE(preferences_page_callback, service_base)
public:
	virtual void on_state_changed() = 0;
};

//! \since 1.0
//! Implements a preferences page instance. \n
//! Instantiated through preferences_page_v3::instantiate(). \n
//! Note that the window will be destroyed by the caller before the last reference to the preferences_page_instance is released. \n
//! WARNING: misguided use of modal dialogs - or ANY windows APIs that might spawn such dialogs - may result in conditions when the owner dialog (along with your page) is destroyed somewhere inside your message handler, also releasing references to your object. \n
//! It is recommended to use window_service_impl_t<> from ATLHelpers to instantiate preferences_page_instances, or preferences_page_impl<> framework for your preferences_page code to cleanly workaround such cases.
class preferences_page_instance : public service_base {
	FB2K_MAKE_SERVICE_INTERFACE(preferences_page_instance, service_base)
public:
	//! @returns a combination of preferences_state constants.
	virtual t_uint32 get_state() = 0;
	//! @returns the window handle.
	virtual fb2k::hwnd_t get_wnd() = 0;
	//! Applies preferences changes.
	virtual void apply() = 0;
	//! Resets this page's content to the default values. Does not apply any changes - lets user preview the changes before hitting "apply".
	virtual void reset() = 0;
};
#endif

//! \since 1.0
//! Implements a preferences page.
class preferences_page_v3 : public preferences_page_v2 {
	FB2K_MAKE_SERVICE_INTERFACE(preferences_page_v3, preferences_page_v2)
public:
#ifdef _WIN32
	virtual preferences_page_instance::ptr instantiate(fb2k::hwnd_t parent, preferences_page_callback::ptr callback) = 0;
#endif
};

//! \since 1.5
class NOVTABLE preferences_page_v4 : public preferences_page_v3 {
	FB2K_MAKE_SERVICE_INTERFACE(preferences_page_v4, preferences_page_v3);
public:
    virtual bool is_hidden() { return false; }
};
