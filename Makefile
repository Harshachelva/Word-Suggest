CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = build/suggest-words

SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Trie.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Trie.o

# Targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/Trie.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/Trie.o: $(SRC_DIR)/Trie.cpp $(SRC_DIR)/Trie.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Trie.cpp -o $(OBJ_DIR)/Trie.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BUILD_DIR)
