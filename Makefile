CC=g++

SOURCE_DIR=src/*.cpp

EXECUTABLE=game

CFLAGS=-Wall -Wextra -std=c++11

LIBS=`sdl2-config --libs --cflags` -lm

INCLUDES=src/includes/**/**/*.cpp

# Runs all the commands
all: build run

# Compiles the source code
build:
	$(CC) $(CFLAGS) $(LIBS) -o $(EXECUTABLE) $(SOURCE_DIR) $(INCLUDES)

# Runs the game
run:
	./$(EXECUTABLE)

# Cleans the build directory
clean:
	rm ./$(EXECUTABLE)