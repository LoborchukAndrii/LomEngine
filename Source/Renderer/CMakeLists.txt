add_library(Renderer STATIC)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

target_include_directories(Renderer PUBLIC "${CMAKE_SOURCE_DIR}/libs/SDL/include")

target_link_libraries(Renderer PRIVATE Performance)

target_sources(Renderer
    PUBLIC
        FILE_SET CXX_MODULES FILES
            Renderer.ixx
            Renderer_Core.ixx
)

target_compile_features(Renderer PUBLIC cxx_std_23)
