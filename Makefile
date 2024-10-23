MAIN_NAME?=main.out

CXX=g++
CXXFLAGS=-g -Wall #-Werror

SRC_DIR?=./
INC_DIR?=./
SRCS=$(shell find $(abspath $(SRC_DIR)) -name "*.c" -or -name "*.cpp" -or -name "*.cc" -maxdepth 1)
HEADERS=$(shell find $(abspath $(INC_DIR)) -name "*.h" -maxdepth 1)

INC_FLAG=$(addprefix -I, $(INC_DIR))
CXXFLAGS+=$(INC_FLAG)

BUILD_DIR?=$(abspath ../build)
OBJ_DIR=$(abspath $(BUILD_DIR))/obj
BIN=$(abspath $(BUILD_DIR))/$(MAIN_NAME)
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)



all:${BIN}

${BIN}:${OBJS}
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -rf $(BUILD_DIR)
