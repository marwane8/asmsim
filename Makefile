# Compiler
CC = gcc

# Directories
SRC = src
OBJ = obj
BIN = out

OBJS = \
	$(OBJ)/asim.o

# Flags - include
CFLAGS = -g -Wall -I $(OBJ)

# Target executable
TARGET = $(BIN)/asim



all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS) $(OBJ)/main.o
	$(CC) -o $(TARGET) $(OBJS) $(OBJ)/main.o

# Make all object files in obj directory
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean rule to remove object files and the executable
clean:
	rm -rf $(OBJ)/* $(BIN)/asim
