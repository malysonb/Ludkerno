CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g  $(shell pkg-config --cflags sdl2 sdl2_image)
LDFLAGS = $(shell pkg-config --static --libs sdl2 sdl2_image)

SRC = $(wildcard *.cpp) $(wildcard src/*.cpp) $(wildcard RadiPako/src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = ludkerno
INCLUDE = ./RadiPako/include

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS) -I$(INCLUDE) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(EXEC)