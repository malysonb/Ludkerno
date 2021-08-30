CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g  -lSDLmain -lSDL2 -lSDL_image
LDFLAGS = 

SRC = main.cpp \
	./src/*.cpp\
	./RadiPako/src/*.cpp
OBJ = $(SRC:.cc=.o)
EXEC = ludkerno
INCLUDE = ./RadiPako/include

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS) -I$(INCLUDE)

clean:
	rm -rf $(OBJ) $(EXEC)