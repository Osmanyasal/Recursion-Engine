SHELL := /bin/bash
CXX := g++
CXX_FLAGS := -g -Wall -std=c++11 -ggdb -fopenmp ## -lGL -lglfw -lGLEW

BIN := bin
SRC := src
SANDBOX := sandbox

DYNAMIC := -Llib/spdlog/build/ -lspdlog -Llib/glfw/src/ -lglfw3 -Llib/glew/lib/ -lGLEW -lGL
LIB_SPD_PATH :=./lib/spdlog
LIB_SPD := -I./lib/spdlog/include/  -I./lib/spdlog/include/spdlog 

LIB_GLEW_PATH := ./lib/glew
LIB_GLEW := -I./lib/glew/include/ -I./lib/spdlog/include/glew 

LIB_GLFW_PATH := ./lib/glfw
LIB_GLFW := -I./lib/glfw/include/ -I./lib/spdlog/include/glfw

INCLUDE := -I./src/core -I./src/core/events\
 						-I./src/core/window\
						-I./src/core/platforms\
						-I./src/core/platforms/linux\
						-I./src/core/platforms/linux/opengl\
						-I./src/core/platforms/linux/vulkan\
						-I./src/core/platforms/macos\
						-I./src/core/platforms/macos/vulkan\
						-I./src/core/platforms/windows\
						-I./src/core/platforms/macos/directx\
						-I./src/core/platforms/macos/vulkan\
						-I./src/utils\
						-I./sandbox/proj1\
					 	 $(LIB_SPD)\
						 $(LIB_GLEW)\
						 $(LIB_GLFW)
EXECUTABLE := recursion.engine

all: $(BIN)/$(EXECUTABLE) $(BIN)/recursion_engine.desktop $(LIB_GLEW_PATH)/include/GL/glew.h $(LIB_GLFW_PATH)/src/libglfw3.a
	
## check memory if there're any leaks.
mem_check:
	valgrind ./$(BIN)/$(EXECUTABLE)

## create a desktop file and move it to applications
$(BIN)/recursion_engine.desktop:
	echo -e "[Desktop Entry]\n\
Version=1.0\n\
Type=Application\n\
Terminal=true\n\
Name=Recursion Engine\n\
Path=$(shell pwd)/bin/\n\
Exec=$(shell pwd)/bin/recursion.engine\n\
Icon=$(shell pwd)/icon/icon.png\n" > $(BIN)/recursion_engine.desktop

	cp $(BIN)/recursion_engine.desktop ~/.local/share/applications

$(LIB_GLEW_PATH)/include/GL/glew.h:
	cd $(LIB_GLEW_PATH)/auto && make
	cd $(LIB_GLEW_PATH) && make && sudo make install && make clean

$(LIB_GLFW_PATH)/src/libglfw3.a:
	cd $(LIB_GLFW_PATH) && cmake . && make

run: all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(shell find $(SRC) -type f -name "*.cc") $(shell find $(SANDBOX) -type f -name "*.cc")
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $^ -o ./$(BIN)/$(EXECUTABLE) $(INCLUDE) $(DYNAMIC) 

clean:
	@echo "🧹 Cleaning..."
	rm -rf $(BIN)/*
	rm -r ~/.local/share/applications/recursion_engine.desktop ## remove dekstop icon

clean_all: clean
	rm $(LIB_GLEW_PATH)/include/GL/glew.h ## to reinstall glew to the system and create the header file.
	rm $(LIB_GLFW_PATH)/src/libglfw3.a