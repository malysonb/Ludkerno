Debug:
	g++ main.cpp -Wall -Wextra ./Implement/* -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Debug/main
	./Build/Debug/main.exe

Release:
	g++ main.cpp -Wall -Wextra ./Implement/* -L./ThirdParty/x64/lib -lSDL2main -lSDL2 -lSDL2_image -o ./Build/Release/main
	./Build/Release/main.exe