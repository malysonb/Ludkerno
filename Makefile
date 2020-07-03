Debug:
	g++ main.cpp -Wall -Wextra ./Implement/*.cpp -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Debug/main
	cp SDL2.dll ./Build/Debug/SDL2.dll
	cp SDL2_image.dll ./Build/Debug/SDL2_image.dll
	./Build/Debug/main.exe

Release:
	g++ main.cpp -s ./Implement/*.cpp -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Release/main my.res
	cp SDL2.dll ./Build/Release/SDL2.dll
	cp SDL2_image.dll ./Build/Release/SDL2_image.dll
	./Build/Release/main