cmake_minimum_required (VERSION 2.6)
project (connector-qt-example)
include(local.cmake)

if (NOT QT_XML) 
	SET (QT_XML ${LINUX_LIB_BASE}/libQtXml.so CACHE STRING "QtXml")
endif()

FIND_PACKAGE(Qt4 REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QT_DONT_USE_QTGUI TRUE)
SET(QT_USE_QTNETWORK TRUE)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

if (NOT QJSON_LIB)
    SET (QJSON_LIB ${LINUX_LIB_BASE}/libqjson.so)
endif()

INCLUDE(${QT_USE_FILE})

enable_testing()

add_subdirectory (src) 

