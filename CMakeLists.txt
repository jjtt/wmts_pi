##---------------------------------------------------------------------------
## Author:      Juho Törmä
## Copyright:
## License:     wxWidgets License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(WMTS_pi)

SET(PACKAGE_NAME WMTS_pi)
SET(VERBOSE_NAME WMTS)
SET(TITLE_NAME WMTS)
SET(CPACK_PACKAGE_CONTACT "Mike Rossiter")

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "1")

#SET(CMAKE_BUILD_TYPE Debug)
SET( wxWidgets_USE_DEBUG OFF)
SET( wxWidgets_USE_UNICODE ON)
SET( wxWidgets_USE_UNIVERSAL OFF)
SET( wxWidgets_USE_STATIC OFF)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_WMTS
        src/wmts_pi.h
        src/wmts_pi.cpp
        src/icons.h
        src/icons.cpp
        src/ocpn_plugin.h
	)


ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_WMTS})

ADD_DEFINITIONS(-DTIXML_USE_STL)

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
