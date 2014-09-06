cmake_minimum_required(VERSION 3.0)
project(server)
set(ROOTDIR ${PROJECT_SOURCE_DIR})
message(${ROOTDIR})

include_directories(${ROOTDIR})

if(MSVC)
##windows下面Debug模式exe文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOTDIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${ROOTDIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ROOTDIR}/exlib/lib)
include_directories(${ROOTDIR}/exlib/include)
else(MSVC)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOTDIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOTDIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOTDIR}/output)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
endif(MSVC)

add_subdirectory(${ROOTDIR}/libprotocol)
add_subdirectory(${ROOTDIR}/getway)
add_subdirectory(${ROOTDIR}/registersvr)