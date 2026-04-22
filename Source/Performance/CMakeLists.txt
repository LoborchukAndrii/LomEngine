add_library(Performance STATIC)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

target_include_directories(Performance PUBLIC "${CMAKE_SOURCE_DIR}/libs/SDL/include")

target_sources(Performance
    PUBLIC
        FILE_SET CXX_MODULES FILES
            Performance.ixx
            Performance_Core.ixx
)

target_compile_features(Performance PUBLIC cxx_std_23)
