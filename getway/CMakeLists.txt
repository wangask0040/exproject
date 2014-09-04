cmake_minimum_required(VERSION 2.8)
project(getway)
set(BIN getway)
aux_source_directory(. SRC)
add_definitions(-Wall 
-Werror 
-std=c++11
-Wno-unused)
add_executable(${BIN} ${SRC})
target_link_libraries(${BIN} -levent)
target_link_libraries(${BIN} -levent_core)
target_link_libraries(${BIN} -levent_extra)
target_link_libraries(${BIN} -lzmq)
target_link_libraries(${BIN} -lpthread)
target_link_libraries(${BIN} -lprotobuf)
target_link_libraries(${BIN} -lprotocol)