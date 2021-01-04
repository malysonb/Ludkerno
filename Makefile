Debug_x86:
	mkdir -p ./Build/Debug_x86/Assets
	cp ./Assets/* ./Build/Debug_x86/Assets/
	i686-w64-mingw32-c++ -L./ThirdParty/x86/lib -DGCCcompiler -I./ThirdParty/x86/include main.cpp ./src/*.cpp -lRPK -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Debug_x86/main
	cp ./ThirdParty/x86/bin/SDL2.dll ./Build/Debug_x86/SDL2.dll
	cp ./ThirdParty/x86/bin/SDL2_image.dll ./Build/Debug_x86/SDL2_image.dll
	cp ./ThirdParty/x86/bin/libpng16-16.dll ./Build/Debug_x86/libpng16-16.dll
	cp ./ThirdParty/x86/bin/libRPK.dll ./Build/Debug_x86/libRPK.dll

Release_x86:
	mkdir -p ./Build/Release_x86/Assets
	./Toolchain/RadiPako ./Assets/* -o ./Build/Release_x86/Assets/Sprites.rpk
	./Toolchain/windres my.rc my.o
	i686-w64-mingw32-c++ -s -O2 -DGCCcompiler -I./ThirdParty/x86/include -DRelease=true -L./ThirdParty/x86/lib main.cpp ./src/*.cpp -lRPK -static -lsetupapi -lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lhid -lsetupapi -lversion -luuid -static-libgcc -lSDL2_image -o ./Build/Release_x86/main my.o
	cp ./ThirdParty/x86/bin/libpng16-16.dll ./Build/Release_x86/libpng16-16.dll

Checkup:
	