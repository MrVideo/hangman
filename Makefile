CC = clang++
CFLAGS = -Wall -Wextra -std=c++11
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# List all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Create object file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# The executable name
TARGET = $(BIN_DIR)/hangman

# Build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
