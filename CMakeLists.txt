
cmake_minimum_required(VERSION 3.28)
project(LomEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)
add_subdirectory(Source/Renderer EXCLUDE_FROM_ALL)

add_executable(LomEngine main.cpp)

target_link_libraries(LomEngine PRIVATE SDL3::SDL3)
target_link_libraries(LomEngine PRIVATE Renderer)


target_include_directories(LomEngine PUBLIC "libs/SDL/include")
