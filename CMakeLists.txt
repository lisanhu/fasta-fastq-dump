cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES dumain.cc dump.cc global.cc my_time.cc)

add_executable(dump ${SOURCES})