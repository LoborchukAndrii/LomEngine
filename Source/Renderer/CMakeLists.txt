add_library(Renderer STATIC)

target_include_directories(Renderer PUBLIC "${CMAKE_SOURCE_DIR}/libs/SDL/include")

target_sources(Renderer
    PUBLIC
        FILE_SET CXX_MODULES FILES
            Renderer.ixx
            Renderer_Core.ixx
)

target_compile_features(Renderer PUBLIC cxx_std_23)
