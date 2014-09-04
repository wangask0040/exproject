cmake_minimum_required(VERSION 2.8)
project(registersvr)
set(BIN registersvr)
aux_source_directory(. SRC)
add_definitions(-Wall 
-Werror 
-std=c++11
-Wno-unused)
add_executable(${BIN} ${SRC})
target_link_libraries(${BIN} -static -lzmq)
target_link_libraries(${BIN} -lpthread)