BOOST_ROOT?=~/boost_1_80_0

SRCS=$(wildcard *.cpp)
DEPS=$(SRCS:.cpp=.d)
OBJS=$(SRCS:.cpp=.o)
PROG=main

INPUTS=$(sort $(wildcard tests/in*))
SOLNS=$(INPUTS:tests/in%=tests/sol%)
OUTS=$(INPUTS:tests/in%=tests/out%)

CXX=g++
CXXFLAGS=-Wall -pedantic -O2 -std=c++17 -I $(BOOST_ROOT)
RM=rm -fv
DIFF=diff

COMPILE.cpp = $(CXX) $(CXXFLAGS)
OUTPUT_OPTION=-MMD -MP -c
LINK.o = $(CXX) $(LDFLAGS)

all: $(PROG)

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(PROG) : $(OBJS)
	$(LINK.o) $^ -o $@

.PHONY: clean run test

run: $(PROG)
	./$(PROG)

clean:
	$(RM) $(PROG) $(OBJS) $(DEPS) $(OUTS0) $(OUTS1) $(OUTS2)

test: $(OUTS)

tests/out%: tests/in% $(PROG)
	./$(PROG) < $< > $@

-include $(DEPS)
