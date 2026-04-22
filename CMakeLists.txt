
cmake_minimum_required(VERSION 3.28)
project(LomEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_SOURCE_DIR}/Source/Renderer EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_SOURCE_DIR}/Source/Performance EXCLUDE_FROM_ALL)

add_executable(LomEngine main.cpp app.rc)

target_link_libraries(LomEngine PRIVATE SDL3::SDL3)
target_link_libraries(LomEngine PRIVATE Renderer)
target_link_libraries(LomEngine PRIVATE Performance)

add_custom_command(TARGET LomEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/Content
            $<TARGET_FILE_DIR:LomEngine>/Content
)

