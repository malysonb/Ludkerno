CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g  $(shell pkg-config --cflags sdl2 sdl2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 sdl2_image)

SRC = main.cpp \
	./src/*.cpp\
	./RadiPako/src/*.cpp
OBJ = $(SRC:.cc=.o)
EXEC = ludkerno
INCLUDE = ./RadiPako/include

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS) -I$(INCLUDE) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(EXEC)

objectify:
	$(CXX) -c $(SRC=objects/%.o)