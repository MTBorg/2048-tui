GXX = g++
CXXFLAGS = --std=c++17
CXXFLAGS_RELEASE = -O3
CXXFLAGS_DEBUG = -g
INCLUDES = -Iinclude
LIBS = -lncurses
SRC = src/*.cpp

2048: $(SRC)
	$(GXX) $(CXXFLAGS) $(CXXFLAGS_RELEASE) $(INCLUDES) $(LIBS) $?

debug: $(SRC)
	$(GXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $(INCLUDES) $(LIBS) $?
