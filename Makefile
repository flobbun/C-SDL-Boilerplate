CC=gcc

SOURCE_DIR=./src/*.c

EXECUTABLE=game

CFLAGS=-Wall -std=c99

LIBS=`sdl2-config --libs --cflags` -lm

# Runs all the commands
all: build run

# Compiles the source code
build:
	$(CC) $(CFLAGS) $(SOURCE_DIR) $(LIBS) -o $(EXECUTABLE)

# Runs the game
run:
	./$(EXECUTABLE)

# Cleans the build directory
clean:
	rm ./$(EXECUTABLE)