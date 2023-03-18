CXX = g++
CC = $(CXX)

CPPFLAGS = -MMD -MP
CPPFLAGS += -I$(INC_DIR) -I ../../inc

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


INC_DIR = ../../inc/stack_machine
SRC_DIR = ../../src/stack_machine

TARGET = utest
OBJS = utest.o $(SRC_DIR)/machine_vm.o $(SRC_DIR)/compiler.o $(SRC_DIR)/code_segment.o $(SRC_DIR)/operations.o $(SRC_DIR)/intermediate_op_classes.o $(SRC_DIR)/firmware.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

$(TARGET): $(OBJS)

vala: all
	valgrind ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

.PHONY: all check clean




DEPENDS = $(OBJS:%.o=%.d)

-include $(DEPENDS)

