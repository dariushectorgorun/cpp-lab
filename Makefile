CXX      ?= g++
STD      := -std=c++20
WARN     := -Wall -Wextra -Wpedantic
RELEASE  := $(STD) $(WARN) -O2
DEBUG    := $(STD) $(WARN) -g -O0
SANITIZE := $(STD) $(WARN) -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer

SRCS   := $(wildcard src/*.cpp)
TARGET := build/app
OBJS   := $(SRCS:src/%.cpp=build/obj/%.o)

.PHONY: all release debug run run-debug sanitize clean

all: release

release: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(RELEASE) -Iinclude -o $@ $(OBJS)

build/obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(RELEASE) -Iinclude -c -o $@ $<

# Unoptimized build with symbols, for debuggers.
debug:
	@mkdir -p build/debug
	$(CXX) $(DEBUG) -Iinclude -o build/debug/app $(SRCS)

# Build with AddressSanitizer + UndefinedBehaviorSanitizer, then run.
sanitize:
	@mkdir -p build/asan
	$(CXX) $(SANITIZE) -Iinclude -o build/asan/app $(SRCS)
	./build/asan/app

run: release
	./$(TARGET)

run-debug: debug
	./build/debug/app

clean:
	rm -rf build
