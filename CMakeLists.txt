cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(SMAKE_CXX_STANDARD_REQUIRED True)

project(agbdesk)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/deps/imgui)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/deps/imgui-sfml)

file(GLOB SRC_IMGUI "${IMGUI_DIR}/*.cpp")
file(GLOB SRC_SFML "${SFML_DIR}/*.cpp")

include_directories("${IMGUI_DIR}")
include_directories("${SFML_DIR}")

add_library(imgui STATIC ${SRC_IMGUI})
add_library(imgui-sfml STATIC ${SRC_SFML})
#add_subdirectory(${IMGUI_DIR})
#add_subdirectory(${SFML_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")

set(CPP_FLAGS "-g -O0 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_FLAGS}")

add_executable(agbdesk ${SRC})
#find_package(OpenGL REQUIRED)
target_link_libraries(agbdesk imgui imgui-sfml sfml-graphics sfml-window sfml-system -lGL )
#target_link_libraries(agbdesk sfml-graphics sfml-window sfml-system -lGL)