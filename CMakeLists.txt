cmake_minimum_required(VERSION 3.0.0)
project(Ludkerno VERSION 0.6.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/thirdParty)

set(thirdparty ${CMAKE_SOURCE_DIR}/thirdparty)

find_package(RPK REQUIRED)

set(SDL2_INCLUDE_DIRS ${thirdparty}/SDL2-2.0.16/include)
set(SDL2_SRC ${thirdparty}/SDL2-2.0.16/src)

set(SDL2_image_INCLUDE_DIRS ${thirdparty}/SDL2_image-2.0.5/)
set(SDL2_image_SRC ${thirdparty}/SDL2_image-2.0.5/)

file(GLOB implements "src/*.cpp")

add_definitions(-DGCCcompiler)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/RadiPako/include ${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS})
add_executable(Ludkerno main.cpp ${implements} ${RPK_SRC} ${SDL2_SRC} ${SDL2_image_SRC})
target_link_libraries(Ludkerno setupapi mingw32 SDL2main libSDL2 m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 hid setupapi version uuid SDL2_image)
link_directories(${CMAKE_SOURCE_DIR}/)

add_definitions(-DRelease=true)


