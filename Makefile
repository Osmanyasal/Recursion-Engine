SHELL := /bin/bash
CXX := g++ 
CXX_VERSION = -std=c++11
CXX_DEBUG := -g
CXX_WARNINGS := -Wall
CXX_OPT_FLAGS := -O3 -flto
CXX_LIBS := -fopenmp
CXX_PGO_GENERATE := -fprofile-generate 
CXX_FLAGS :=  $(CXX_OPT_FLAGS) $(CXX_VERSION) $(CXX_DEBUG) $(CXX_PGO_GENERATE) $(CXX_WARNINGS) $(CXX_LIBS) 

BIN := ./bin
SRC := ./src
OBJ := $(BIN)/obj
SANDBOX := ./sandbox

# CORE Directories for source and header files
SRC_DIR := ./src
CORE_DIR := $(SRC_DIR)/core
EVENTS_DIR := $(CORE_DIR)/events
LAYER_DIR := $(CORE_DIR)/layer
WINDOW_DIR := $(CORE_DIR)/window
MATH_DIR := $(CORE_DIR)/math
RENDER_DIR := $(CORE_DIR)/render
PLATFORMS_DIR := $(SRC_DIR)/platforms
UTILS_DIR := $(SRC_DIR)/utils

LINUX_DIR := $(PLATFORMS_DIR)/linux
MACOS_DIR := $(PLATFORMS_DIR)/macos
WINDOWS_DIR := $(PLATFORMS_DIR)/windows
OPTIMIZATIONS_DIR := $(UTILS_DIR)/optimizations
SANDBOX_DIR := ./sandbox/proj1

RENDER_IMPL_DIR := $(PLATFORMS_DIR)/render
RENDER_OPENGL_DIR := $(RENDER_IMPL_DIR)/opengl
RENDER_VULKAN_DIR := $(RENDER_IMPL_DIR)/vulkan
RENDER_DIRECTX_DIR := $(RENDER_IMPL_DIR)/d3d
GUI := $(PLATFORMS_DIR)/gui
IMGUI_OPENGL_DIR := $(GUI)/imgui_opengl3_glfw

# LIB Directories for source and header files
LIB_SPD_PATH :=./lib/spdlog
LIB_SPD := -I./lib/spdlog/include/  -I./lib/spdlog/include/spdlog 

LIB_GLEW_PATH := ./lib/glew
LIB_GLEW := -I./lib/glew/include/ -I./lib/spdlog/include/glew 

LIB_GLFW_PATH := ./lib/glfw
LIB_GLFW := -I./lib/glfw/include/ -I./lib/spdlog/include/glfw

LIB_IMGUI_PATH := ./lib/imgui
LIB_IMGUI := -I./lib/imgui/ -I./lib/imgui/backends -I./lib/imgui/docs -I./lib/imgui/examples -I./lib/imgui/mics

LIB_GLM_PATH := ./lib/glm
LIB_GLM := -I./lib/glm/glm -I./lib/glm/glm/detail -I./lib/glm/glm/ext -I./lib/glm/glm/gtc -I./lib/glm/gtx -I./lib/glm/simd

DYNAMIC := -L$(LIB_SPD_PATH)/build/ -lspdlog -L$(LIB_GLFW_PATH)/build/src/ -lglfw3 -L$(LIB_GLEW_PATH)/lib/ -lGLEW -lGL

# Include directories
INCLUDE := -I$(SRC_DIR)\
           -I$(CORE_DIR)\
		   -I$(RENDER_DIR)\
           -I$(EVENTS_DIR)\
           -I$(WINDOW_DIR)\
           -I$(LAYER_DIR)\
		   -I$(MATH_DIR)\
           -I$(PLATFORMS_DIR)\
           -I$(IMGUI_OPENGL_DIR)\
           -I$(LINUX_DIR)\
           -I$(MACOS_DIR)\
           -I$(WINDOWS_DIR)\
           -I$(UTILS_DIR)\
           -I$(OPTIMIZATIONS_DIR)\
		   -I$(RENDER_IMPL_DIR)\
           -I$(RENDER_VULKAN_DIR)\
           -I$(RENDER_DIRECTX_DIR)\
           -I$(RENDER_OPENGL_DIR)\
           -I$(SANDBOX_DIR)\
			$(LIB_SPD)\
			$(LIB_GLEW)\
			$(LIB_GLFW)\
			$(LIB_IMGUI)\
			$(LIB_GLM)

EXECUTABLE := recursion.engine

SRC_FILES := $(shell find $(SRC) -type f -name "*.cc") $(shell find $(SANDBOX) -type f -name "*.cc")
OBJ_FILES := $(patsubst ./%.cc,$(OBJ)/%.o,$(SRC_FILES)) 
 
all: ${LIB_IMGUI_PATH}/build $(LIB_SPD_PATH)/build/libspdlog.a $(LIB_GLFW_PATH)/build/src/libglfw3.a $(LIB_GLEW_PATH)/lib/libGLEW.a $(BIN)/$(EXECUTABLE) $(BIN)/recursion_engine.desktop
	@if [ ! -d "$(BIN)/fonts" ]; then \
        mkdir -p "$(BIN)/fonts"; \
        cp -R ./lib/fonts/* "$(BIN)/fonts"; \
        echo "Fonts installed successfully!"; \
    else \
        echo "Fonts directory already exists. Skipping installation."; \
    fi
 
## check memory if there're any leaks.
mem_check:
	cd $(BIN) && valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

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

$(LIB_GLEW_PATH)/lib/libGLEW.a:
	cd $(LIB_GLEW_PATH) && ./install.sh
	
$(LIB_SPD_PATH)/build/libspdlog.a:
	cd $(LIB_SPD_PATH) && ./install.sh

$(LIB_GLFW_PATH)/build/src/libglfw3.a:
	cd $(LIB_GLFW_PATH) && ./install.sh

${LIB_IMGUI_PATH}/build:
	cd ${LIB_IMGUI_PATH} && ./install.sh

run: all
	@echo "🚀 Executing..."
	cd $(BIN); ./$(EXECUTABLE)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $^ -o ./$(BIN)/$(EXECUTABLE) ${LIB_IMGUI_PATH}/build/*.o $(INCLUDE) $(DYNAMIC)

$(OBJ)/%.o: ./%.cc
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(INCLUDE) 

clean:
	@echo "🧹 Cleaning..."
	rm -rf $(BIN)/*
	rm -rf ~/.local/share/applications/recursion_engine.desktop ## remove dekstop icon

clean_all: clean
	cd $(LIB_GLEW_PATH) && ./install.sh clean
	cd $(LIB_GLFW_PATH) && ./install.sh clean
	cd ${LIB_IMGUI_PATH} && ./install.sh clean
	cd $(LIB_SPD_PATH) && ./install.sh clean

## THESE ARE FOR MONITORING
CALL_STACK_METHOD := lbr
monitor_callstack: $(BIN)/$(EXECUTABLE)
	cd $(BIN);\
	sudo perf record --call-graph $(CALL_STACK_METHOD) ./$(EXECUTABLE);\ ## sampling
	sudo chmod a+rwx perf*;\
	sudo perf report;

tma_analysis:
	cd ./"$(BIN)";\
	sudo perf stat --topdown -a --td-level 0 -- taskset -c 0  ./$(EXECUTABLE); ## counting

