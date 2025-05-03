cmake_minimum_required(VERSION 3.5)
project(Ludkerno VERSION 0.6.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/thirdParty)

set(thirdparty ${CMAKE_SOURCE_DIR}/thirdparty)

find_package(RPK REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB implements "src/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/RadiPako/include)

add_executable(Ludkerno main.cpp ${implements} ${RPK_SRC})
if(WIN32)
    # Configurações específicas para Windows
    add_definitions(-DGCCcompiler -Dmain=SDL_main -mwindows)
    link_directories(${CMAKE_SOURCE_DIR}/thirdParty/x86-64/lib)
    target_link_libraries(Ludkerno mingw32 SDL2_ttf SDL2main SDL2 SDL2_image dinput8 shell32 setupapi advapi32 uuid version oleaut32 ole32 imm32 winmm gdi32 user32 m)
elseif(UNIX)
    # Configurações específicas para Linux
    add_definitions(-DLINUX)
    target_link_libraries(Ludkerno SDL2_ttf SDL2main SDL2 SDL2_image pthread dl)
endif()


add_definitions(-DRelease=true)


