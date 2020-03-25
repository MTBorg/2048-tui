GXX = g++
CXXFLAGS = --std=c++17
CXXFLAGS_RELEASE = -O3
CXXFLAGS_DEBUG = -g
INCLUDES = -Iinclude
LIBS = -lncurses
SRC = src/*.cpp
OUT = 2048

$(OUT): $(SRC)
	$(GXX) $(CXXFLAGS) $(CXXFLAGS_RELEASE) $(INCLUDES) $(LIBS) $? -o $@

debug: $(SRC)
	$(GXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $(INCLUDES) $(LIBS) $?
	
.PHONY: install
install: $(SRC)
	$(GXX) $(CXXFLAGS) $(CXXFLAGS_RELEASE) $(INCLUDES) $(LIBS) $? -o $(OUT)
	cp $(OUT) /usr/bin

uninstall:
	rm -f /usr/bin/$(OUT)
