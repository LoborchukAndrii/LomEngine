
cmake_minimum_required(VERSION 3.16)
project(LomEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23) # Or 20 if 23 isn't supported
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Add the SDL source folder
add_subdirectory(libs/SDL)

# 2. Define your executable
add_executable(LomEngine main.cpp)

# 3. Link against the SDL3 shared library target
# In SDL3, the standard target is usually 'SDL3-shared' or 'SDL3::SDL3'
target_link_libraries(LomEngine PRIVATE SDL3::SDL3-shared)

# 4. Include paths (Optional, usually handled by target_link_libraries)
target_include_directories(LomEngine PUBLIC "libs/SDL/include")

if(WIN32)
add_custom_command(TARGET LomEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3-shared>
        $<TARGET_FILE_DIR:LomEngine>)
endif()