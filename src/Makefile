# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Environment variables
GLEW_INCLUDE = $(GLEW_DIR)/include
GLEW_LIB = $(GLEW_DIR)/lib
GLM_INCLUDE = $(GLM_INCLUDE_DIR)

# Automatically find all .cpp files in the folder
SRC = $(wildcard *.cpp)

# Target executable
TARGET = OpenGLCubes

# Libraries
LIBS = -lGLEW -lglfw -lGL -ldl -lpthread -lX11 -lXrandr -lXi

# Include paths
INCLUDES = -I$(GLEW_INCLUDE) -I$(GLM_INCLUDE)

# Linker flags
LDFLAGS = -L$(GLEW_LIB)

# Default target: build and run
all: $(TARGET)
	./$(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(INCLUDES) $(LDFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)
