CC=gcc
CXX=g++
CFLAGS= 
OPENMP=
SOURCES:=$(shell find $(.) -name '*.c')
# SOURCESCXX:=$(shell find $(.) -name '*.cpp')
SOURCESCXX:=$(shell find . -type f \( -name "*.cpp" -not -name "tsjCommonFunc.cpp" \) -print)
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

tsjCommonFunc.o:tsjCommonFunc.cpp 
	$(CXX) $(DEBUG) $(OPENMP) $(LIB) -c $<

%: %.c tsjCommonFunc.o
	$(CC) $(DEBUG) $(CFLAGS) $(OPENMP) $< tsjCommonFunc.o $(LIB) -o $@

%: %.cpp tsjCommonFunc.o
	$(CXX) $(DEBUG) $(OPENMP) $< tsjCommonFunc.o $(LIB) -o $@

.PHONY: clean showVariable

showVariable:
	@echo $(SOURCES)

clean: 
	rm -rf build
