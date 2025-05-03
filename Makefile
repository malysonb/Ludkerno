CXX = g++
CXXFLAGS = -DRelease -Wall -Werror -Wextra -pedantic -std=c++17 -g $(shell pkg-config --cflags sdl2 SDL2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)

SRC = $(wildcard *.cpp) $(wildcard src/*.cpp) $(wildcard RadiPako/src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = ludkerno
INCLUDE = ./RadiPako/include

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) -I$(INCLUDE) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(EXEC)