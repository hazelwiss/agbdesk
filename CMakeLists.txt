cmake_minimum_required(VERSION 3.10)

project(agbdesk)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")

set(CPP_FLAGS "-g -O0 -Wall")
set(CPP_LINK "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CPP_LINK}")

add_executable(agbdesk ${SRC})

