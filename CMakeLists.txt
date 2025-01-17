cmake_minimum_required(VERSION 3.14..3.18)

# Build:
#   cmake .
#   make
#
# Install without cpack:
#
#   sudo make install
#
# Install with cpack (generates deb package):
#
#   cpack
#   sudo dpkg -i libmbfl_*.deb

# Included for CMAKE_INSTALL_PREFIX and other variables.
include(GNUInstallDirs)

project(libmbfl
        VERSION 1.0.0
        DESCRIPTION "libmbfl"
        HOMEPAGE_URL "https://github.com/andreylzmw/libmbfl")

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(OBJS_DIR "${BASE_DIR}/objs")
set(CMAKE_OSX_DEPLOYMENT_TARGET 11.0)

# add_custom_target(libmbfl-includecopy ALL DEPENDS 
# 	include/kphp/libmbfl/mbfilter.h)
# add_custom_command(
#     OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/mbfilter.h
#     COMMAND mkdir -p ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/ && cp ${CMAKE_CURRENT_SOURCE_DIR}/libmbfl/mbfilter.h ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/mbfilter.h
#     DEPENDS libmbfl/mbfilter.h
# )

# add_custom_target(libmbfl-includecopy ALL)

add_custom_command(
        COMMAND cp -R
                ${CMAKE_CURRENT_SOURCE_DIR}/mbfl
                ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/mbfl)

add_custom_command(
        COMMAND cp -R
                ${CMAKE_CURRENT_SOURCE_DIR}/filters
                ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/filters)

add_custom_command(
        COMMAND cp -R
                ${CMAKE_CURRENT_SOURCE_DIR}/nls
                ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/include/kphp/libmbfl/nls)

add_custom_target(libmbfl-includecopy ALL DEPENDS 
	include/kphp/libmbfl/mbfl/mbfilter.h)

set(libmbfl_ALL_SOURCES
    filters/mbfilter_iso2022_jp_ms.c
	filters/mbfilter_iso8859_14.c
	filters/mbfilter_iso8859_6.c
	filters/mbfilter_sjis_mobile.c
	filters/mbfilter_koi8r.c
	filters/mbfilter_cp850.c
	filters/mbfilter_euc_jp.c
	filters/mbfilter_sjis_open.c
	filters/mbfilter_ascii.c
	filters/mbfilter_euc_cn.c
	filters/mbfilter_iso8859_10.c
	filters/mbfilter_utf7.c
	filters/mbfilter_iso8859_2.c
	filters/mbfilter_htmlent.c
	filters/mbfilter_iso8859_8.c
	filters/mbfilter_uhc.c
	filters/mbfilter_armscii8.c
	filters/mbfilter_uuencode.c
	filters/mbfilter_cp1254.c
	filters/mbfilter_iso8859_5.c
	filters/mbfilter_cp932.c
	filters/mbfilter_iso8859_13.c
	filters/mbfilter_cp936.c
	filters/mbfilter_iso8859_1.c
	filters/mbfilter_koi8u.c
	filters/mbfilter_byte2.c
	filters/mbfilter_iso2022jp_2004.c
	filters/mbfilter_sjis.c
	filters/mbfilter_euc_jp_2004.c
	filters/mbfilter_jis.c
	filters/mbfilter_utf16.c
	filters/mbfilter_ucs2.c
	filters/mbfilter_hz.c
	filters/mbfilter_cp866.c
	filters/mbfilter_iso8859_4.c
	filters/mbfilter_base64.c
	filters/mbfilter_iso8859_16.c
	filters/mbfilter_utf7imap.c
	filters/mbfilter_tl_jisx0201_jisx0208.c
	filters/mbfilter_iso2022_kr.c
	filters/mbfilter_euc_tw.c
	filters/mbfilter_euc_jp_win.c
	filters/mbfilter_qprint.c
	filters/html_entities.c
	filters/mbfilter_sjis_2004.c
	filters/mbfilter_cp1252.c
	filters/mbfilter_euc_kr.c
	filters/mbfilter_big5.c
	filters/mbfilter_cp51932.c
	filters/mbfilter_utf32.c
	filters/mbfilter_7bit.c
	filters/mbfilter_iso8859_7.c
	filters/mbfilter_iso8859_15.c
	filters/mbfilter_utf8.c
	filters/mbfilter_sjis_mac.c
	filters/mbfilter_iso8859_9.c
	filters/mbfilter_iso8859_3.c
	filters/mbfilter_cp1251.c
	filters/mbfilter_utf8_mobile.c
	filters/mbfilter_gb18030.c
	filters/mbfilter_ucs4.c
	filters/mbfilter_iso2022jp_mobile.c
	filters/mbfilter_byte4.c
	filters/mbfilter_cp5022x.c
	nls/nls_tr.c
	nls/nls_ja.c
	nls/nls_neutral.c
	nls/nls_de.c
	nls/nls_en.c
	nls/nls_uni.c
	nls/nls_ru.c
	nls/nls_ua.c
	nls/nls_hy.c
	nls/nls_kr.c
	nls/nls_zh.c
	mbfl/mbfl_allocators.c
	mbfl/mbfilter.c
	mbfl/mbfilter_wchar.c
	mbfl/mbfilter_8bit.c
	mbfl/mbfl_filter_output.c
	mbfl/mbfl_string.c
	mbfl/mbfilter_pass.c
	mbfl/mbfl_encoding.c
	mbfl/mbfl_convert.c
	mbfl/mbfl_ident.c
	mbfl/mbfl_language.c
	mbfl/mbfl_memory_device.c)

add_library(libmbfl STATIC ${libmbfl_ALL_SOURCES})
add_library(vk::libmbfl ALIAS libmbfl)

target_compile_options(libmbfl PRIVATE
    -std=gnu11
    -O3
    -Wno-unused-parameter -Wno-unused-variable -Wno-return-type -Wno-incompatible-pointer-types -Wno-unused-function
    -DHAVE_STRING_H -DHAVE_STDLIB_H
)
if (APPLE)
	target_compile_options(libmbfl PRIVATE -Wno-logical-op-parentheses)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(libmbfl PRIVATE -Wmaybe-uninitialized -Wno-parentheses)
  if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "7.0.0")
    message("GCC >= 7, adding extra compile options")
    target_compile_options(libmbfl PRIVATE -Wno-implicit-fallthrough)
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(libmbfl PRIVATE -Wuninitialized)
endif()

set_target_properties(libmbfl PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OBJS_DIR})

target_link_libraries(libmbfl m)

set_target_properties(libmbfl PROPERTIES PUBLIC_HEADER "libmbfl/mbfilter.h")

add_dependencies(libmbfl libmbfl-includecopy)

install(TARGETS libmbfl
        COMPONENT KPHP
        LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/kphp/liblibmbfl")

set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_COMPONENTS_GROUPING "IGNORE")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "KPHP Team")
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_PACKAGE_HOMEPAGE_URL ${CMAKE_PROJECT_HOMEPAGE_URL})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${CMAKE_PROJECT_DESCRIPTION}")

include(CPack)