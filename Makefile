Debug:
	g++ main.cpp -Wall -Wextra ./Implement/*.cpp -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Debug/main
	cp -r ./Assets/* ./Build/Debug/Assets/
	cp ./ThirdParty/x64/bin/SDL2.dll ./Build/Debug/SDL2.dll
	cp ./ThirdParty/x64/bin/SDL2_image.dll ./Build/Debug/SDL2_image.dll
	cp ./ThirdParty/x64/bin/libpng16-16.dll ./Build/Release/libpng16-16.dll

Release:
	windres my.rc my.o
	g++ main.cpp -s ./Implement/*.cpp -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Release/main my.o
	cp -r ./Assets/* ./Build/Release/Assets
	cp ./ThirdParty/x64/bin/SDL2.dll ./Build/Release/SDL2.dll
	cp ./ThirdParty/x64/bin/SDL2_image.dll ./Build/Release/SDL2_image.dll
	cp ./ThirdParty/x64/bin/libpng16-16.dll ./Build/Release/libpng16-16.dll

Debug_w64_x86:
	i686-w64-mingw32-c++ main.cpp -Wall -Wextra ./Implement/*.cpp -L./ThirdParty/x86/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Debug_x86/main
	cp -r ./Assets/* ./Build/Debug_x86/Assets/
	cp ./ThirdParty/x86/bin/SDL2.dll ./Build/Debug_x86/SDL2.dll
	cp ./ThirdParty/x86/bin/SDL2_image.dll ./Build/Debug_x86/SDL2_image.dll
	cp ./ThirdParty/x86/bin/libpng16-16.dll ./Build/Release_x86/libpng16-16.dll

Release_w64_x86:
	mkdir -p ./Build/Release_x86/Assets
	tar -a -c -f ./Build/Release_x86/Assets/Sprites.zip Assets/*.png
	mv ./Build/Release_x86/Assets/Sprites.zip ./Build/Release_x86/Assets/Sprites.rpk
	./Toolchain/windres my.rc my.o
	i686-w64-mingw32-c++ -mwindows -s -DRelease=true main.cpp ./Implement/*.cpp -L./ThirdParty/x86/lib -lminizip -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Release_x86/main my.o
	cp ./ThirdParty/x86/bin/SDL2.dll ./Build/Release_x86/SDL2.dll
	cp ./ThirdParty/x86/bin/SDL2_image.dll ./Build/Release_x86/SDL2_image.dll
	cp ./ThirdParty/x86/bin/libpng16-16.dll ./Build/Release_x86/libpng16-16.dll
	cp ./ThirdParty/x86/bin/libminizip-1.dll ./Build/Release_x86/libminizip-1.dll