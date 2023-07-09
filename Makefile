SHELL := /bin/bash
CXX := g++
CXX_FLAGS := -g -Wall -std=c++11 -ggdb -fopenmp -lGL -lglfw -lGLEW

BIN := bin
SRC := src
SANDBOX := sandbox

DYNAMIC := -Llib/spdlog/build/ -lspdlog
LIB_SPD_PATH :=./lib/spdlog
LIB_SPD := -I./lib/spdlog/include/  -I./lib/spdlog/include/spdlog -I./lib/spdlog/include/glew -I./lib/spdlog/include/glfw

LIB_GLEW_PATH := ./lib/glew
LIB_GLEW := -I./lib/glew/include/GL
INCLUDE := -I./src/core -I./src/core/events -I./src/utils -I./sandbox/proj1 $(LIB_SPD) $(LIB_GLEW)
EXECUTABLE := recursion.engine

all: $(BIN)/$(EXECUTABLE) $(BIN)/recursion_engine.desktop $(LIB_GLEW_PATH)/include/GL/glew.h
	
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



run: all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(shell find $(SRC) -type f -name "*.cc") $(shell find $(SANDBOX) -type f -name "*.cc")
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $(DYNAMIC) $^ -o ./$(BIN)/$(EXECUTABLE)

clean:
	@echo "🧹 Cleaning..."
	rm -rf $(BIN)/*
	rm -r ~/.local/share/applications/recursion_engine.desktop ## remove dekstop icon
	rm $(LIB_GLEW_PATH)/include/GL/glew.h ## to reinstall glew to the system and create the header file.