cmake_minimum_required(VERSION 3.0)
project(getway)
set(BIN getway)
aux_source_directory(. SRC)

if(MSVC)
##windows下面.h文件放入HFILES变量
file(GLOB HFILES "*.h")
link_directories(${ROOTDIR}/exlib/lib)
add_executable(${BIN} ${SRC} ${HFILES})
target_link_libraries(${BIN} libevent_core.lib)
target_link_libraries(${BIN} libzmq.lib)
target_link_libraries(${BIN} libprotobuf.lib)
target_link_libraries(${BIN} protocol.lib)
target_link_libraries(${BIN} Advapi32.lib)
target_link_libraries(${BIN} ws2_32.lib)
target_link_libraries(${BIN} wsock32.lib)
else(MSVC)
add_executable(${BIN} ${SRC})
add_definitions(-Wall -Werror -std=c++11 -Wno-unused)
target_link_libraries(${BIN} -levent_core)
target_link_libraries(${BIN} -lzmq)
target_link_libraries(${BIN} -lpthread)
target_link_libraries(${BIN} -lprotobuf)
target_link_libraries(${BIN} -lprotocol)
endif(MSVC)
