$src = (Get-childItem -Path ./src/*.cpp).fullname

$rpk = (get-childItem -Path ./RadiPako/src/*.cpp).fullname

em++ -s FETCH main.cpp $src $rpk -L .\thirdParty\x86\lib\ -I .\thirdparty\x86\include\ -lSDL2main -lSDL2 -lSDL2_image -s USE_SDL=2 -s USE_LIBPNG=1 -s USE_SDL_IMAGE=2 -s ALLOW_MEMORY_GROWTH=1 --use-preload-plugins -s SDL2_IMAGE_FORMATS='["bmp","png"]' -s GL_UNSAFE_OPTS=0 -D EMSCRIPTEN -o ./build/ludkerno.html --preload-file Assets