#* Azizbek Umidjonov (ID: 20202043)
#^ Makefile for creating multiple executables
#! source StackOverflow https://stackoverflow.com/a/5191461/12095791

SANFLAGS = -fsanitize=address
 CXXFLAGS += -Wall -g -std=c++17 -pedantic $(SANFLAGS)
 LDFLAGS += $(SANFLAGS)

# COMMON_SOURCES = array.cpp
TARGET_SOURCES = main.cpp

# COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS = $(TARGET_SOURCES:.cpp=.o)
EXECUTABLE = main


.PHONY: all target

all: target

target: $(EXECUTABLE)


$(EXECUTABLE): $(TARGET_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@