#ifndef _UI_EXTENSION_LIBPNG_H_
#define _UI_EXTENSION_LIBPNG_H_

/**
* \file libpng.h
* not very useful libpng wrapper. probably easier to delay load
* \author musicmusic
*/

#define UI_EXTENSION_LIBPNG_SUPPORT_ENABLED
#ifdef UI_EXTENSION_LIBPNG_SUPPORT_ENABLED

#include "../lpng1234/png.h"

typedef pfc::refcounted_object_ptr_t<class libpng_handle> libpng_ptr;

#define UI_EXTENSION_LIBPNG_TYPEDEF(ret,name) \
	typedef ret (PNGAPI * t_##name##_proc)

#define UI_EXTENSION_LIBPNG_TYPEDEF_ARGS(arglist) arglist

#define UI_EXTENSION_LIBPNG_FUNCTION(ret,name) \
	private: \
	t_##name##_proc m_##name; \
	public: \
	ret name

#define UI_EXTENSION_LIBPNG_FUNCTION_ARGS(arglist) arglist

class libpng_handle : public pfc::refcounted_object_root
{
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_access_version_number) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((void));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sig_bytes) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int num_bytes));

#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_gAMA) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, double *file_gamma));
#endif
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_gAMA_fixed) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point *int_file_gamma));
#endif

#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_gAMA) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, double file_gamma));
#endif
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_gAMA_fixed) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point int_file_gamma));
#endif

#if defined(PNG_hIST_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_hIST) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_16p *hist));
#endif

#if defined(PNG_hIST_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_hIST) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_16p hist));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_IHDR) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 *width, png_uint_32 *height,
		int *bit_depth, int *color_type, int *interlace_method,
		int *compression_method, int *filter_method));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_IHDR) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth,
		int color_type, int interlace_method, int compression_method,
		int filter_method));

#if defined(PNG_oFFs_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_oFFs) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y,
		int *unit_type));
#endif

#if defined(PNG_oFFs_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_oFFs) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_int_32 offset_x, png_int_32 offset_y,
		int unit_type));
#endif

#if defined(PNG_pCAL_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_pCAL) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1,
		int *type, int *nparams, png_charp *units, png_charpp *params));
#endif

#if defined(PNG_pCAL_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_pCAL) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1,
		int type, int nparams, png_charp units, png_charpp params));
#endif

#if defined(PNG_pHYs_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_pHYs) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type));
#endif

#if defined(PNG_pHYs_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_pHYs) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_PLTE) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_colorp *palette, int *num_palette));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_PLTE) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_colorp palette, int num_palette));

#if defined(PNG_sBIT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_sBIT) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_8p *sig_bit));
#endif

#if defined(PNG_sBIT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sBIT) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_8p sig_bit));
#endif

#if defined(PNG_sRGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_sRGB) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *intent));
#endif

#if defined(PNG_sRGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sRGB) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int intent));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sRGB_gAMA_and_cHRM) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int intent));
#endif

#if defined(PNG_iCCP_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_iCCP) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charpp name, int *compression_type,
		png_charpp profile, png_uint_32 *proflen));
#endif

#if defined(PNG_iCCP_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_iCCP) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp name, int compression_type,
		png_charp profile, png_uint_32 proflen));
#endif

#if defined(PNG_sPLT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_sPLT) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_sPLT_tpp entries));
#endif

#if defined(PNG_sPLT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sPLT) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_sPLT_tp entries, int nentries));
#endif

#if defined(PNG_TEXT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_text) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_textp *text_ptr, int *num_text));
#endif

#if defined(PNG_TEXT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_text) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_textp text_ptr, int num_text));
#endif

#if defined(PNG_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_tIME) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_timep *mod_time));
#endif

#if defined(PNG_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_tIME) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_timep mod_time));
#endif

#if defined(PNG_tRNS_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_tRNS) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep *trans, int *num_trans,
		png_color_16p *trans_values));
#endif

#if defined(PNG_tRNS_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_tRNS) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep trans, int num_trans,
		png_color_16p trans_values));
#endif

#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_sCAL) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *unit, double *width, double *height));
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_sCAL_s) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *unit, png_charpp swidth, png_charpp sheight));
#endif
#endif
#endif /* PNG_sCAL_SUPPORTED */

#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sCAL) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int unit, double width, double height));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_sCAL_s) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int unit, png_charp swidth, png_charp sheight));
#endif
#endif /* PNG_sCAL_SUPPORTED || PNG_WRITE_sCAL_SUPPORTED */

#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_set_keep_unknown_chunks) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, int keep, png_bytep chunk_list, int num_chunks));
	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_set_unknown_chunks) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_unknown_chunkp unknowns, int num_unknowns));
	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_set_unknown_chunk_location)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_infop info_ptr, int chunk, int location));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_unknown_chunks) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr, png_unknown_chunkpp entries));
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_handle_as_unknown) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_bytep
		chunk_name));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_set_invalid) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int mask));

#if defined(PNG_INFO_IMAGE_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_read_png) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr,
		int transforms,
		png_voidp params));
	UI_EXTENSION_LIBPNG_TYPEDEF(void, png_write_png) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr,
		int transforms,
		png_voidp params));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_bytep,png_sig_bytes) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((void));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_charp,png_get_copyright) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_charp,png_get_header_ver) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_charp,png_get_header_version) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_charp,png_get_libpng_ver) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

#ifdef PNG_MNG_FEATURES_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_permit_mng_features) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_uint_32 mng_features_permitted));
#endif

#if defined(PNG_ASSEMBLER_CODE_SUPPORTED)
#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_mmx_flagmask)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((int flag_select, int *compilerID));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_asm_flagmask)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((int flag_select));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_asm_flags)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte,png_get_mmx_bitdepth_threshold)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_mmx_rowbytes_threshold)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_asm_flags)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_uint_32 asm_flags));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_mmx_thresholds)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_byte mmx_bitdepth_threshold,
		png_uint_32 mmx_rowbytes_threshold));

#endif /* PNG_1_0_X */
#endif /* PNG_ASSEMBLER_CODE_SUPPORTED */

#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_mmx_support) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((void));

#ifdef PNG_ERROR_NUMBERS_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_strip_error_numbers) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_uint_32 strip_mode));
#endif

#endif /* PNG_1_0_X */

#ifdef PNG_SET_USER_LIMITS_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_user_limits) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_user_width_max) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_user_height_max) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr));
#endif



	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_sig_cmp) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_bytep sig, png_size_t start,
		png_size_t num_to_check));

	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_check_sig) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_bytep sig, int num));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_structp,png_create_read_struct)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_structp,png_create_write_struct)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn));

#ifdef PNG_WRITE_SUPPORTED

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_compression_buffer_size)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_buffer_size)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_uint_32 size));

#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_reset_zstream) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

#ifdef PNG_USER_MEM_SUPPORTED

	UI_EXTENSION_LIBPNG_TYPEDEF(png_structp,png_create_read_struct_2)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
		png_malloc_ptr malloc_fn, png_free_ptr free_fn));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_structp,png_create_write_struct_2)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
		png_malloc_ptr malloc_fn, png_free_ptr free_fn));

#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_chunk) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep chunk_name, png_bytep data, png_size_t length));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_chunk_start) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep chunk_name, png_uint_32 length));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_chunk_data) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep data, png_size_t length));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_chunk_end) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_infop,png_create_info_struct)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_info_init) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_info_init_3) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_infopp info_ptr,
		png_size_t png_info_struct_size));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_info_before_PLTE) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_info) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_info) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));
#endif

#if defined(PNG_TIME_RFC1123_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_charp,png_convert_to_rfc1123)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_timep ptime));
#endif

#if !defined(_WIN32_WCE)
#if defined(PNG_WRITE_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_convert_from_struct_tm) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_timep ptime,
	struct tm FAR * ttime));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_convert_from_time_t) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_timep ptime,
		time_t ttime));
#endif /* PNG_WRITE_tIME_SUPPORTED */
#endif /* _WIN32_WCE */

#if defined(PNG_READ_EXPAND_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_expand) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_gray_1_2_4_to_8) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_palette_to_rgb) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_tRNS_to_alpha) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_bgr) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_GRAY_TO_RGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_gray_to_rgb) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_rgb_to_gray) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int error_action, double red, double green ));
#endif
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_rgb_to_gray_fixed) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int error_action, png_fixed_point red, png_fixed_point green ));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte,png_get_rgb_to_gray_status) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_build_grayscale_palette) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((int bit_depth,
		png_colorp palette));

#if defined(PNG_READ_STRIP_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_strip_alpha) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED) || \
	defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_swap_alpha) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED) || \
	defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_invert_alpha) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_filler) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_uint_32 filler, int flags));
#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_add_alpha) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_uint_32 filler, int flags));
#endif
#endif /* PNG_READ_FILLER_SUPPORTED || PNG_WRITE_FILLER_SUPPORTED */

#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_swap) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_PACK_SUPPORTED) || defined(PNG_WRITE_PACK_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_packing) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_PACKSWAP_SUPPORTED) || defined(PNG_WRITE_PACKSWAP_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_packswap) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_shift) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_color_8p true_bits));
#endif

#if defined(PNG_READ_INTERLACING_SUPPORTED) || \
	defined(PNG_WRITE_INTERLACING_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(int,png_set_interlace_handling) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_invert_mono) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_BACKGROUND_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_background) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_color_16p background_color, int background_gamma_code,
		int need_expand, double background_gamma));
#endif
#endif

#if defined(PNG_READ_16_TO_8_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_strip_16) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_DITHER_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_dither) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_colorp palette, int num_palette, int maximum_colors,
		png_uint_16p histogram, int full_dither));
#endif

#if defined(PNG_READ_GAMMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_gamma) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		double screen_gamma, double default_file_gamma));
#endif
#endif

#if defined(PNG_READ_EMPTY_PLTE_SUPPORTED) || \
	defined(PNG_WRITE_EMPTY_PLTE_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_permit_empty_plte) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int empty_plte_permitted));
#endif

#if defined(PNG_WRITE_FLUSH_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_flush) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, int nrows));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_flush) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_start_read_image) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_update_info) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_rows) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytepp row, png_bytepp display_row, png_uint_32 num_rows));
#endif

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_row) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep row,
		png_bytep display_row));
#endif

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_image) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytepp image));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_row) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep row));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_rows) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytepp row, png_uint_32 num_rows));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_image) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytepp image));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_write_end) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_read_end) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_destroy_info_struct) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infopp info_ptr_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_destroy_read_struct) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structpp
		png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_destroy_write_struct)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structpp png_ptr_ptr, png_infopp info_ptr_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_crc_action) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int crit_action, int ancil_action));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_filter) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, int method,
		int filters));

#if defined(PNG_WRITE_WEIGHTED_FILTER_SUPPORTED) /* EXPERIMENTAL */
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_filter_heuristics) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int heuristic_method, int num_weights, png_doublep filter_weights,
		png_doublep filter_costs));
#endif
#endif /*  PNG_WRITE_WEIGHTED_FILTER_SUPPORTED */

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_level) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int level));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_mem_level)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, int mem_level));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_strategy)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, int strategy));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_window_bits)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, int window_bits));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_compression_method) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		int method));

#if !defined(PNG_NO_STDIO)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_init_io) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_FILE_p fp));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_error_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_error_ptr) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_write_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_read_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp io_ptr, png_rw_ptr read_data_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_io_ptr) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_read_status_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_read_status_ptr read_row_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_write_status_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_write_status_ptr write_row_fn));

#ifdef PNG_USER_MEM_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_mem_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_mem_ptr) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_read_user_transform_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_user_transform_ptr read_user_transform_fn));
#endif

#if defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_write_user_transform_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_user_transform_ptr write_user_transform_fn));
#endif

#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_user_transform_info) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_voidp user_transform_ptr, int user_transform_depth,
		int user_transform_channels));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_user_transform_ptr)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));
#endif

#ifdef PNG_USER_CHUNKS_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_read_user_chunk_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_user_chunk_ptr) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr));
#endif

#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_progressive_read_fn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp progressive_ptr,
		png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn,
		png_progressive_end_ptr end_fn));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_get_progressive_ptr)
		UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_process_data) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep buffer, png_size_t buffer_size));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_progressive_combine_row) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_bytep old_row, png_bytep new_row));
#endif /* PNG_PROGRESSIVE_READ_SUPPORTED */

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_malloc) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_uint_32 size));

#if defined(PNG_1_0_X)
#  define png_malloc_warn png_malloc
#else
	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_malloc_warn) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_uint_32 size));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_free) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr, png_voidp ptr));

#if defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_TYPEDEF(voidpf,png_zalloc) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((voidpf png_ptr, uInt items,
		uInt size));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_zfree) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((voidpf png_ptr, voidpf ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_free_data) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 free_me, int num));
#ifdef PNG_FREE_ME_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_data_freer) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, int freer, png_uint_32 mask));
#endif

#ifdef PNG_USER_MEM_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_malloc_default) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_uint_32 size));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_free_default) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_memcpy_check) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp s1, png_voidp s2, png_uint_32 size));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_voidp,png_memset_check) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_voidp s1, int value, png_uint_32 size));

#if defined(USE_FAR_KEYWORD)
	extern void *png_far_to_near UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,png_voidp ptr,
		int check));
#endif /* USE_FAR_KEYWORD */

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_error) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_const_charp error_message));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_chunk_error) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_const_charp error_message));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_warning) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_const_charp warning_message));

	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_chunk_warning) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_const_charp warning_message));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_valid) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 flag));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_rowbytes) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#if defined(PNG_INFO_IMAGE_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_bytepp,png_get_rows) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_rows) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytepp row_pointers));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte,png_get_channels) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifdef PNG_EASY_ACCESS_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32, png_get_image_width) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32, png_get_image_height) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte, png_get_bit_depth) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte, png_get_color_type) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte, png_get_filter_type) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte, png_get_interlace_type) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_byte, png_get_compression_type) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32, png_get_pixels_per_meter) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32, png_get_x_pixels_per_meter) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32, png_get_y_pixels_per_meter) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(float, png_get_pixel_aspect_ratio) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
#endif

	UI_EXTENSION_LIBPNG_TYPEDEF(png_int_32, png_get_x_offset_pixels) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_int_32, png_get_y_offset_pixels) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_int_32, png_get_x_offset_microns) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_TYPEDEF(png_int_32, png_get_y_offset_microns) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp
		png_ptr, png_infop info_ptr));

#endif /* PNG_EASY_ACCESS_SUPPORTED */

	UI_EXTENSION_LIBPNG_TYPEDEF(png_bytep,png_get_signature) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#if defined(PNG_bKGD_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_bKGD) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_16p *background));
#endif

#if defined(PNG_bKGD_SUPPORTED)
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_bKGD) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_16p background));
#endif

#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_cHRM) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, double *white_x, double *white_y, double *red_x,
		double *red_y, double *green_x, double *green_y, double *blue_x,
		double *blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(png_uint_32,png_get_cHRM_fixed) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point
		*int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y,
		png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point
		*int_blue_x, png_fixed_point *int_blue_y));
#endif
#endif

#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_cHRM) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, double white_x, double white_y, double red_x,
		double red_y, double green_x, double green_y, double blue_x, double blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_TYPEDEF(void,png_set_cHRM_fixed) UI_EXTENSION_LIBPNG_TYPEDEF_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y,
		png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point
		int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x,
		png_fixed_point int_blue_y));
#endif
#endif





	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_access_version_number) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((void));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sig_bytes) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int num_bytes));

	UI_EXTENSION_LIBPNG_FUNCTION(int,png_sig_cmp) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_bytep sig, png_size_t start,
		png_size_t num_to_check));

	UI_EXTENSION_LIBPNG_FUNCTION(int,png_check_sig) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_bytep sig, int num));

	UI_EXTENSION_LIBPNG_FUNCTION(png_structp,png_create_read_struct)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(png_structp,png_create_write_struct)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn));

#ifdef PNG_WRITE_SUPPORTED

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_compression_buffer_size)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_buffer_size)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_uint_32 size));

#endif

	UI_EXTENSION_LIBPNG_FUNCTION(int,png_reset_zstream) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

#ifdef PNG_USER_MEM_SUPPORTED

	UI_EXTENSION_LIBPNG_FUNCTION(png_structp,png_create_read_struct_2)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
		png_malloc_ptr malloc_fn, png_free_ptr free_fn));
	UI_EXTENSION_LIBPNG_FUNCTION(png_structp,png_create_write_struct_2)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_const_charp user_png_ver, png_voidp error_ptr,
		png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
		png_malloc_ptr malloc_fn, png_free_ptr free_fn));

#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_chunk) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep chunk_name, png_bytep data, png_size_t length));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_chunk_start) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep chunk_name, png_uint_32 length));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_chunk_data) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep data, png_size_t length));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_chunk_end) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_infop,png_create_info_struct)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_info_init) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_info_init_3) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_infopp info_ptr,
		png_size_t png_info_struct_size));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_info_before_PLTE) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_info) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_info) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));
#endif

#if defined(PNG_TIME_RFC1123_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_charp,png_convert_to_rfc1123)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_timep ptime));
#endif

#if !defined(_WIN32_WCE)
#if defined(PNG_WRITE_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_convert_from_struct_tm) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_timep ptime,
	struct tm FAR * ttime));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_convert_from_time_t) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_timep ptime,
		time_t ttime));
#endif /* PNG_WRITE_tIME_SUPPORTED */
#endif /* _WIN32_WCE */

#if defined(PNG_READ_EXPAND_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_expand) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_gray_1_2_4_to_8) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_palette_to_rgb) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_tRNS_to_alpha) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_bgr) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_GRAY_TO_RGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_gray_to_rgb) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_rgb_to_gray) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int error_action, double red, double green ));
#endif
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_rgb_to_gray_fixed) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int error_action, png_fixed_point red, png_fixed_point green ));
	UI_EXTENSION_LIBPNG_FUNCTION(png_byte,png_get_rgb_to_gray_status) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_build_grayscale_palette) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((int bit_depth,
		png_colorp palette));

#if defined(PNG_READ_STRIP_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_strip_alpha) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED) || \
	defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_swap_alpha) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED) || \
	defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_invert_alpha) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_filler) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_uint_32 filler, int flags));
#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_add_alpha) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_uint_32 filler, int flags));
#endif
#endif /* PNG_READ_FILLER_SUPPORTED || PNG_WRITE_FILLER_SUPPORTED */

#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_swap) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_PACK_SUPPORTED) || defined(PNG_WRITE_PACK_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_packing) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_PACKSWAP_SUPPORTED) || defined(PNG_WRITE_PACKSWAP_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_packswap) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_shift) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_color_8p true_bits));
#endif

#if defined(PNG_READ_INTERLACING_SUPPORTED) || \
	defined(PNG_WRITE_INTERLACING_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(int,png_set_interlace_handling) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_invert_mono) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_BACKGROUND_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_background) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_color_16p background_color, int background_gamma_code,
		int need_expand, double background_gamma));
#endif
#endif

#if defined(PNG_READ_16_TO_8_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_strip_16) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_DITHER_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_dither) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_colorp palette, int num_palette, int maximum_colors,
		png_uint_16p histogram, int full_dither));
#endif

#if defined(PNG_READ_GAMMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_gamma) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		double screen_gamma, double default_file_gamma));
#endif
#endif

#if defined(PNG_READ_EMPTY_PLTE_SUPPORTED) || \
	defined(PNG_WRITE_EMPTY_PLTE_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_permit_empty_plte) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int empty_plte_permitted));
#endif

#if defined(PNG_WRITE_FLUSH_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_flush) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, int nrows));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_flush) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_start_read_image) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_update_info) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_rows) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytepp row, png_bytepp display_row, png_uint_32 num_rows));
#endif

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_row) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep row,
		png_bytep display_row));
#endif

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_image) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytepp image));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_row) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep row));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_rows) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytepp row, png_uint_32 num_rows));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_image) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytepp image));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_write_end) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_read_end) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_destroy_info_struct) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infopp info_ptr_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_destroy_read_struct) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structpp
		png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_destroy_write_struct)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structpp png_ptr_ptr, png_infopp info_ptr_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_crc_action) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int crit_action, int ancil_action));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_filter) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, int method,
		int filters));

#if defined(PNG_WRITE_WEIGHTED_FILTER_SUPPORTED) /* EXPERIMENTAL */
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_filter_heuristics) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int heuristic_method, int num_weights, png_doublep filter_weights,
		png_doublep filter_costs));
#endif
#endif /*  PNG_WRITE_WEIGHTED_FILTER_SUPPORTED */

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_level) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int level));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_mem_level)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, int mem_level));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_strategy)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, int strategy));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_window_bits)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, int window_bits));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_compression_method) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		int method));

#if !defined(PNG_NO_STDIO)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_init_io) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_FILE_p fp));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_error_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_error_ptr) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_write_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_read_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp io_ptr, png_rw_ptr read_data_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_io_ptr) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_read_status_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_read_status_ptr read_row_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_write_status_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_write_status_ptr write_row_fn));

#ifdef PNG_USER_MEM_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_mem_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn));
	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_mem_ptr) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_read_user_transform_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_user_transform_ptr read_user_transform_fn));
#endif

#if defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_write_user_transform_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_user_transform_ptr write_user_transform_fn));
#endif

#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
	defined(PNG_LEGACY_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_user_transform_info) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_voidp user_transform_ptr, int user_transform_depth,
		int user_transform_channels));
	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_user_transform_ptr)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
#endif

#ifdef PNG_USER_CHUNKS_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_read_user_chunk_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn));
	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_user_chunk_ptr) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr));
#endif

#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_progressive_read_fn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp progressive_ptr,
		png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn,
		png_progressive_end_ptr end_fn));

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_get_progressive_ptr)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_process_data) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep buffer, png_size_t buffer_size));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_progressive_combine_row) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_bytep old_row, png_bytep new_row));
#endif /* PNG_PROGRESSIVE_READ_SUPPORTED */

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_malloc) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_uint_32 size));

#if defined(PNG_1_0_X)
#  define png_malloc_warn png_malloc
#else
	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_malloc_warn) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_uint_32 size));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_free) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_voidp ptr));

#if defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_FUNCTION(voidpf,png_zalloc) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((voidpf png_ptr, uInt items,
		uInt size));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_zfree) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((voidpf png_ptr, voidpf ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_free_data) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 free_me, int num));
#ifdef PNG_FREE_ME_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_data_freer) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int freer, png_uint_32 mask));
#endif

#ifdef PNG_USER_MEM_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_malloc_default) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_uint_32 size));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_free_default) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_memcpy_check) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp s1, png_voidp s2, png_uint_32 size));

	UI_EXTENSION_LIBPNG_FUNCTION(png_voidp,png_memset_check) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_voidp s1, int value, png_uint_32 size));

#if defined(USE_FAR_KEYWORD)
	extern void *png_far_to_near UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,png_voidp ptr,
		int check));
#endif /* USE_FAR_KEYWORD */

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_error) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_const_charp error_message));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_chunk_error) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_const_charp error_message));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_warning) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_const_charp warning_message));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_chunk_warning) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_const_charp warning_message));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_valid) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 flag));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_rowbytes) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#if defined(PNG_INFO_IMAGE_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_bytepp,png_get_rows) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_rows) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytepp row_pointers));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte,png_get_channels) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#ifdef PNG_EASY_ACCESS_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32, png_get_image_width) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32, png_get_image_height) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte, png_get_bit_depth) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte, png_get_color_type) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte, png_get_filter_type) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte, png_get_interlace_type) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte, png_get_compression_type) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32, png_get_pixels_per_meter) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32, png_get_x_pixels_per_meter) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32, png_get_y_pixels_per_meter) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(float, png_get_pixel_aspect_ratio) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_int_32, png_get_x_offset_pixels) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_int_32, png_get_y_offset_pixels) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_int_32, png_get_x_offset_microns) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_int_32, png_get_y_offset_microns) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr));

#endif /* PNG_EASY_ACCESS_SUPPORTED */

	UI_EXTENSION_LIBPNG_FUNCTION(png_bytep,png_get_signature) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr));

#if defined(PNG_bKGD_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_bKGD) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_16p *background));
#endif

#if defined(PNG_bKGD_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_bKGD) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_16p background));
#endif

#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_cHRM) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, double *white_x, double *white_y, double *red_x,
		double *red_y, double *green_x, double *green_y, double *blue_x,
		double *blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_cHRM_fixed) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point
		*int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y,
		png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point
		*int_blue_x, png_fixed_point *int_blue_y));
#endif
#endif

#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_cHRM) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, double white_x, double white_y, double red_x,
		double red_y, double green_x, double green_y, double blue_x, double blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_cHRM_fixed) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y,
		png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point
		int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x,
		png_fixed_point int_blue_y));
#endif
#endif

#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_gAMA) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, double *file_gamma));
#endif
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_gAMA_fixed) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point *int_file_gamma));
#endif

#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_gAMA) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, double file_gamma));
#endif
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_gAMA_fixed) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_fixed_point int_file_gamma));
#endif

#if defined(PNG_hIST_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_hIST) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_16p *hist));
#endif

#if defined(PNG_hIST_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_hIST) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_16p hist));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_IHDR) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 *width, png_uint_32 *height,
		int *bit_depth, int *color_type, int *interlace_method,
		int *compression_method, int *filter_method));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_IHDR) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth,
		int color_type, int interlace_method, int compression_method,
		int filter_method));

#if defined(PNG_oFFs_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_oFFs) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y,
		int *unit_type));
#endif

#if defined(PNG_oFFs_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_oFFs) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_int_32 offset_x, png_int_32 offset_y,
		int unit_type));
#endif

#if defined(PNG_pCAL_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_pCAL) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1,
		int *type, int *nparams, png_charp *units, png_charpp *params));
#endif

#if defined(PNG_pCAL_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_pCAL) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1,
		int type, int nparams, png_charp units, png_charpp params));
#endif

#if defined(PNG_pHYs_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_pHYs) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type));
#endif

#if defined(PNG_pHYs_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_pHYs) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_PLTE) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_colorp *palette, int *num_palette));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_PLTE) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_colorp palette, int num_palette));

#if defined(PNG_sBIT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_sBIT) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_8p *sig_bit));
#endif

#if defined(PNG_sBIT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sBIT) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_color_8p sig_bit));
#endif

#if defined(PNG_sRGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_sRGB) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *intent));
#endif

#if defined(PNG_sRGB_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sRGB) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int intent));
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sRGB_gAMA_and_cHRM) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int intent));
#endif

#if defined(PNG_iCCP_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_iCCP) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charpp name, int *compression_type,
		png_charpp profile, png_uint_32 *proflen));
#endif

#if defined(PNG_iCCP_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_iCCP) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_charp name, int compression_type,
		png_charp profile, png_uint_32 proflen));
#endif

#if defined(PNG_sPLT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_sPLT) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_sPLT_tpp entries));
#endif

#if defined(PNG_sPLT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sPLT) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_sPLT_tp entries, int nentries));
#endif

#if defined(PNG_TEXT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_text) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_textp *text_ptr, int *num_text));
#endif

#if defined(PNG_TEXT_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_text) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_textp text_ptr, int num_text));
#endif

#if defined(PNG_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_tIME) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_timep *mod_time));
#endif

#if defined(PNG_tIME_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_tIME) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_timep mod_time));
#endif

#if defined(PNG_tRNS_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_tRNS) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep *trans, int *num_trans,
		png_color_16p *trans_values));
#endif

#if defined(PNG_tRNS_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_tRNS) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_bytep trans, int num_trans,
		png_color_16p trans_values));
#endif

#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_sCAL) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *unit, double *width, double *height));
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_sCAL_s) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int *unit, png_charpp swidth, png_charpp sheight));
#endif
#endif
#endif /* PNG_sCAL_SUPPORTED */

#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sCAL) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int unit, double width, double height));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_sCAL_s) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int unit, png_charp swidth, png_charp sheight));
#endif
#endif /* PNG_sCAL_SUPPORTED || PNG_WRITE_sCAL_SUPPORTED */

#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void, png_set_keep_unknown_chunks) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, int keep, png_bytep chunk_list, int num_chunks));
	UI_EXTENSION_LIBPNG_FUNCTION(void, png_set_unknown_chunks) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, png_unknown_chunkp unknowns, int num_unknowns));
	UI_EXTENSION_LIBPNG_FUNCTION(void, png_set_unknown_chunk_location)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_infop info_ptr, int chunk, int location));
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_unknown_chunks) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_infop info_ptr, png_unknown_chunkpp entries));
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(int,png_handle_as_unknown) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_bytep
		chunk_name));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(void, png_set_invalid) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr, int mask));

#if defined(PNG_INFO_IMAGE_SUPPORTED)
	UI_EXTENSION_LIBPNG_FUNCTION(void, png_read_png) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr,
		int transforms,
		png_voidp params));
	UI_EXTENSION_LIBPNG_FUNCTION(void, png_write_png) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr,
		png_infop info_ptr,
		int transforms,
		png_voidp params));
#endif

	UI_EXTENSION_LIBPNG_FUNCTION(png_bytep,png_sig_bytes) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((void));

	UI_EXTENSION_LIBPNG_FUNCTION(png_charp,png_get_copyright) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_charp,png_get_header_ver) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_charp,png_get_header_version) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_charp,png_get_libpng_ver) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

#ifdef PNG_MNG_FEATURES_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_permit_mng_features) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_uint_32 mng_features_permitted));
#endif

#if defined(PNG_ASSEMBLER_CODE_SUPPORTED)
#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_mmx_flagmask)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((int flag_select, int *compilerID));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_asm_flagmask)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((int flag_select));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_asm_flags)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_byte,png_get_mmx_bitdepth_threshold)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_mmx_rowbytes_threshold)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_asm_flags)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_uint_32 asm_flags));

	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_mmx_thresholds)
		UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp png_ptr, png_byte mmx_bitdepth_threshold,
		png_uint_32 mmx_rowbytes_threshold));

#endif /* PNG_1_0_X */
#endif /* PNG_ASSEMBLER_CODE_SUPPORTED */

#if !defined(PNG_1_0_X)
	UI_EXTENSION_LIBPNG_FUNCTION(int,png_mmx_support) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((void));

#ifdef PNG_ERROR_NUMBERS_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_strip_error_numbers) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_uint_32 strip_mode));
#endif

#endif /* PNG_1_0_X */

#ifdef PNG_SET_USER_LIMITS_SUPPORTED
	UI_EXTENSION_LIBPNG_FUNCTION(void,png_set_user_limits) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max));
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_user_width_max) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr));
	UI_EXTENSION_LIBPNG_FUNCTION(png_uint_32,png_get_user_height_max) UI_EXTENSION_LIBPNG_FUNCTION_ARGS((png_structp
		png_ptr));
#endif
	public:
		static bool g_create(libpng_ptr & p_out);
	protected:
		libpng_handle(HINSTANCE);
		~libpng_handle();
		HINSTANCE m_inst;


};
#endif
#endif
