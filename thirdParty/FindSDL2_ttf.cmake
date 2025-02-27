if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SDL2_LIBRARIES ${thirdparty}/x86/lib/libSDL2_ttf.a)
    set(SDL2_INCLUDE_DIRS ${thirdparty}/x86/include/SDL2)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_LIBRARIES ${thirdparty}/x86-64/lib/libSDL2_ttf.a)
    set(SDL2_INCLUDE_DIRS ${thirdparty}/x86-64/include/SDL2)
endif()