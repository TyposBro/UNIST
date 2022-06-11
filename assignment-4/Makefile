#* Azizbek Umidjonov (ID: 20202043)
#^ Makefile for creating two separate executables
#! source StackOverflow https://stackoverflow.com/a/5191461/12095791

SANFLAGS = -fsanitize=address
 CXXFLAGS += -Wall -g -std=c++17 -pedantic $(SANFLAGS)
 LDFLAGS += $(SANFLAGS)

COMMON_SOURCES = random-gen.cpp
TARGET_SOURCES = main.cpp
# TEST_SOURCES = check.cpp
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS = $(TARGET_SOURCES:.cpp=.o)
# TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
EXECUTABLE = main
# TEST_EXECUTABLE = check

.PHONY: all target test

all: target test

target: $(EXECUTABLE)

test: $(TEST_EXECUTABLE)

$(EXECUTABLE): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@