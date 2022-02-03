CC=gcc
CXX=g++
CFLAGS= 
OPENMP=
SOURCES:=$(shell find $(.) -name '*.c')
SOURCESCXX:=$(shell find $(.) -name '*.cpp')
LIB=-lm
OBJS=$(SOURCES:%.c=%)
OBJS+=$(SOURCESCXX:%.cpp=%)
DEBUG=-g


all : $(OBJS)
	@echo $(SOURCES) $(SOURCESCXX)
	@echo "编译完成"
	@echo $(OBJS)
	if [ ! -d "build"  ]; then mkdir build; fi
	mv $(OBJS) build

%: %.c
	$(CC) $(DEBUG) $(CFLAGS) $(OPENMP) $< $(LIB) -o $@

%: %.cpp
	$(CXX) $(DEBUG) $(OPENMP) $< $(LIB) -o $@

.PHONY: clean showVariable

showVariable:
	@echo $(SOURCES)

clean: 
	rm -rf build
