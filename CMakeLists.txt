cmake_minimum_required(VERSION 3.0.0)
project(Ludkerno VERSION 0.6.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/thirdParty)

set(thirdparty ${CMAKE_SOURCE_DIR}/thirdparty)

find_package(RPK REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB implements "src/*.cpp")

add_definitions(-DGCCcompiler)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/RadiPako/include ${SDL2_INCLUDE_DIRS} ${thirdparty}/x86-64/include)
link_directories(${CMAKE_SOURCE_DIR}/thirdParty/x86-64/lib)
add_executable(Ludkerno main.cpp ${implements} ${RPK_SRC})
target_link_libraries(Ludkerno setupapi mingw32 SDL2main libSDL2.a m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 hid setupapi version uuid libSDL2_image.a libpng.a)

add_definitions(-DRelease=true)


