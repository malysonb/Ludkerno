# FindSDL2_image.cmake
# A CMake module to find SDL2_image
# This will work on both Linux and Windows

find_package(SDL2 REQUIRED)

set(SDL2_IMAGE_HINTS "")

if(WIN32)
    set(SDL2_IMAGE_HINTS "${SDL2_DIR}/lib")
endif()

find_path(SDL2_IMAGE_INCLUDE_DIR SDL2/SDL_image.h
    HINTS ${SDL2_IMAGE_HINTS}
    PATH_SUFFIXES include
)

find_library(SDL2_IMAGE_LIBRARY
    NAMES SDL2_image
    HINTS ${SDL2_IMAGE_HINTS}
    PATH_SUFFIXES lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2_image
    REQUIRED_VARS SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY
    FAIL_MESSAGE "Could not find SDL2_image"
)

if(SDL2_IMAGE_FOUND)
    set(SDL2_IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARY})
    set(SDL2_IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIR})
endif()

mark_as_advanced(SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY)