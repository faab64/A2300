##############################################################
# Project setup
##############################################################

cmake_minimum_required(VERSION 2.6)
set(PROJECT_NAME A2300)
project(${PROJECT_NAME} CXX C)
enable_testing()

#select the release build type by default to get optimization flags

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

# Set the version information here

set(VERSION_MAJOR 0)
set(VERSION_API_COMPAT    1)
set(VERSION_MINOR 0)
set(VERSION_MAINT git)

set(${PROJECT_NAME}_VERSION_FULL
	${VERSION_MAJOR}.${VERSION_API_COMPAT}.${VERSION_MINOR}
)
set(${PROJECT_NAME}_VERSION_PATCH
	${VERSION_MAJOR}.${VERSION_API_COMPAT}
)

##############################################################
# Compiler specific setup
##############################################################

if(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
    # http://gcc.gnu.org/wiki/Visibility
    add_definitions(-fvisibility=hidden)
endif()

##############################################################
# Find boost
##############################################################

if(UNIX AND EXISTS "/usr/lib64")
    list(APPEND BOOST_LIBRARYDIR "/usr/lib64") #fedora 64-bit fix
endif(UNIX AND EXISTS "/usr/lib64")
set(Boost_ADDITIONAL_VERSIONS
    "1.35.0" "1.35" "1.36.0" "1.36" "1.37.0" "1.37" "1.38.0" "1.38" "1.39.0" "1.39"
    "1.40.0" "1.40" "1.41.0" "1.41" "1.42.0" "1.42" "1.43.0" "1.43" "1.44.0" "1.44"
    "1.45.0" "1.45" "1.46.0" "1.46" "1.47.0" "1.47" "1.48.0" "1.48" "1.49.0" "1.49"
    "1.50.0" "1.50" "1.51.0" "1.51" "1.52.0" "1.52" "1.53.0" "1.53" "1.54.0" "1.54"
    "1.55.0" "1.55" "1.56.0" "1.56" "1.57.0" "1.57" "1.58.0" "1.58" "1.59.0" "1.59"
    "1.60.0" "1.60" "1.61.0" "1.61" "1.62.0" "1.62" "1.63.0" "1.63" "1.64.0" "1.64"
    "1.65.0" "1.65" "1.66.0" "1.66" "1.67.0" "1.67" "1.68.0" "1.68" "1.69.0" "1.69"
)
find_package(Boost "1.35" COMPONENTS system thread)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost required to compile a2300_uhd")
endif()

add_definitions(-DBOOST_ALL_DYN_LINK)

##############################################################
# Setup common include and linker paths
##############################################################

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/host/include
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

##############################################################
# Add subdirectories
##############################################################

add_subdirectory(common)
add_subdirectory(host)