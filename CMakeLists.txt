cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(SMAKE_CXX_STANDARD_REQUIRED True)

project(agbdesk)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/deps/imgui)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/deps/imgui-sfml)

file(GLOB_RECURSE SRC_IMGUI "${IMGUI_DIR}/*.cpp")
file(GLOB_RECURSE SRC_SFML "${SFML_DIR}/*.cpp")

include_directories("${IMGUI_DIR}")
include_directories("${SFML_DIR}")

add_library(imgui STATIC ${SRC_IMGUI})
add_library(imgui-sfml STATIC ${SRC_SFML})

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src")

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")

set(CPP_FLAGS "-g -O0 -Wall -ftemplate-depth=70000 -fconstexpr-depth=70000 -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_FLAGS}")

add_executable(agbdesk ${SRC})
#find_package(OpenGL REQUIRED)
target_link_libraries(imgui-sfml imgui)
target_link_libraries(agbdesk imgui imgui-sfml sfml-graphics sfml-window sfml-system -lGL -pthread)