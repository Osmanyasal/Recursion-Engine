CXX := g++
CXX_FLAGS := -Wall -std=c++11 -ggdb -fopenmp -lGL -lglfw -lGLEW

BIN := bin
SRC := src
SANDBOX := sandbox
LIB := lib
INCLUDE := -I./src/core -I./src/utils -I./sandbox/proj1
EXECUTABLE := recursion.engine

all: $(BIN)/$(EXECUTABLE)

run: all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(shell find $(SRC) -type f -name "*.cc") $(shell find $(SANDBOX) -type f -name "*.cc")
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -L$(LIB) $^ -o ./$(BIN)/$(EXECUTABLE)

clean:
	@echo "🧹 Cleaning..."
	rm -rf $(BIN)/*