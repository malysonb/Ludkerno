# FindSDL2.cmake
# A CMake module to locate the SDL2 library and headers
# Works on both Windows and Linux

find_package(PkgConfig QUIET)

if (PKG_CONFIG_FOUND)
    pkg_check_modules(SDL2_PKG sdl2)
endif()

if (SDL2_PKG_FOUND)
    set(SDL2_FOUND TRUE)
    set(SDL2_INCLUDE_DIRS ${SDL2_PKG_INCLUDE_DIRS})
    set(SDL2_LIBRARIES ${SDL2_PKG_LIBRARIES})
else()
    find_path(SDL2_INCLUDE_DIR SDL.h
        HINTS
            $ENV{SDL2DIR}
            ${SDL2DIR}
        PATH_SUFFIXES include/SDL2 include
    )

    find_library(SDL2_LIBRARY
        NAMES SDL2 SDL2-2.0
        HINTS
            $ENV{SDL2DIR}
            ${SDL2DIR}
        PATH_SUFFIXES lib
    )

    if (SDL2_INCLUDE_DIR AND SDL2_LIBRARY)
        set(SDL2_FOUND TRUE)
        set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
        set(SDL2_LIBRARIES ${SDL2_LIBRARY})
    else()
        set(SDL2_FOUND FALSE)
    endif()
endif()

if (SDL2_FOUND)
    message(STATUS "Found SDL2: ${SDL2_LIBRARIES}")
else()
    message(WARNING "SDL2 not found")
endif()

mark_as_advanced(SDL2_INCLUDE_DIRS SDL2_LIBRARIES)