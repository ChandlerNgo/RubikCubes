CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

GLEW_INCLUDE = $(GLEW_DIR)/include
GLEW_LIB = $(GLEW_DIR)/lib
GLM_INCLUDE = $(GLM_INCLUDE_DIR)

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/RubikCube

LIBS = -lGLEW -lglfw -lGL -ldl -lpthread -lX11 -lXrandr -lXi

INCLUDES = -I$(GLEW_INCLUDE) -I$(GLM_INCLUDE)

LDFLAGS = -L$(GLEW_LIB)

all: $(TARGET)
	@./$(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -rf $(BUILD_DIR)
