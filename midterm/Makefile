#* Azizbek Umidjonov (ID: 20202043)
#^ Makefile for creating multiple executables
#! source StackOverflow https://stackoverflow.com/a/5191461/12095791

SANFLAGS = -fsanitize=address
 CXXFLAGS += -Wall -g -std=c++17 -pedantic $(SANFLAGS)
 LDFLAGS += $(SANFLAGS)

# COMMON_SOURCES = array.cpp
PART1_SOURCES = part1.cpp
PART2_SOURCES = part2.cpp
# COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
PART1_OBJECTS = $(PART1_SOURCES:.cpp=.o)
PART2_OBJECTS = $(PART2_SOURCES:.cpp=.o)
PART1_EXECUTABLE = part1.out
PART2_EXECUTABLE = part2.out

.PHONY: all part1 part2

all: part1 part2

part1: $(PART1_EXECUTABLE)

part2: $(PART2_EXECUTABLE)

$(PART1_EXECUTABLE): $(PART1_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(PART2_EXECUTABLE): $(PART2_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@