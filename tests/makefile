CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=ball
DEPENDENCY2=paddle
DEPENDENCY3=level
DEPENDENCY4=brick

CPPFLAGS = -I $(INC_DIR) -I $(INL_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = ../src/
INC_DIR = ../inc/
INL_DIR= ../inc/inl/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o ${SRC_DIR}${DEPENDENCY3}.o ${SRC_DIR}${DEPENDENCY4}.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

vala: all
	valgrind --leak-check=yes --track-origins=yes -s ./$(TARGET)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}