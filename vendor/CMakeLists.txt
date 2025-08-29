# Disable precompiled headers when using MinGW, because ASLR (an optional
# Windows Security feature) can interfere with PCH generation and cause the
# compiler to crash.
if(MINGW)
    set_directory_properties(PROPERTIES DISABLE_PRECOMPILE_HEADERS ON)
endif()

add_subdirectory(SDL EXCLUDE_FROM_ALL)

# Set SDLxyz_VENDORED to ON so that the corresponding SDL extension builds its
# own dependencies.

set(SDLTTF_VENDORED ON)
add_subdirectory(SDL_ttf EXCLUDE_FROM_ALL)

set(SDLIMAGE_VENDORED ON)
set(SDLIMAGE_AVIF OFF)
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_JPEG OFF)
set(SDLIMAGE_WEBP OFF)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

add_subdirectory(EnTT EXCLUDE_FROM_ALL)

# Fixes GH-9: Compilation fails due to "too many sections" error in harfbuzz.cc
# See https://github.com/acinis/RoundHell/issues/9
# See https://github.com/harfbuzz/harfbuzz/issues/5372
if(MSVC)
    target_compile_options(harfbuzz PRIVATE "/bigobj")
elseif(MINGW)
    target_compile_options(harfbuzz PRIVATE "-Wa,-mbig-obj")
endif()

# Link vendor libs to our executable.
# This also makes its include directory available to us.
add_library(vendor INTERFACE)
target_link_libraries(
    vendor INTERFACE
    EnTT::EnTT
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    SDL3::SDL3
)
