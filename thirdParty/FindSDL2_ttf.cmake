# FindSDL2_ttf.cmake
# A CMake module to find SDL2_ttf
# This will work on both Linux and Windows

find_package(SDL2 REQUIRED)

set(SDL2_TTF_HINTS "")

if(WIN32)
    set(SDL2_TTF_HINTS "${SDL2_DIR}/lib")
endif()

find_path(SDL2_TTF_INCLUDE_DIR SDL2/SDL_ttf.h
    HINTS ${SDL2_TTF_HINTS}
    PATH_SUFFIXES include
)

find_library(SDL2_TTF_LIBRARY
    NAMES SDL2_ttf
    HINTS ${SDL2_TTF_HINTS}
    PATH_SUFFIXES lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2_ttf
    REQUIRED_VARS SDL2_TTF_INCLUDE_DIR SDL2_TTF_LIBRARY
    FAIL_MESSAGE "Could not find SDL2_ttf"
)

if(SDL2_TTF_FOUND)
    set(SDL2_TTF_LIBRARIES ${SDL2_TTF_LIBRARY})
    set(SDL2_TTF_INCLUDE_DIRS ${SDL2_TTF_INCLUDE_DIR})
endif()

mark_as_advanced(SDL2_TTF_INCLUDE_DIR SDL2_TTF_LIBRARY)
