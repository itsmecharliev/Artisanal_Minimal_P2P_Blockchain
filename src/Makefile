# Compiler and flags
CXX      := g++
CXXFLAGS := -std=c++17 -pthread -Wall -Wextra -O2
LDFLAGS  := -pthread

# Project layout
SRC_DIRS := . core cryptography network
SRCS     := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJS     := $(SRCS:.cpp=.o)
DEPS     := $(OBJS:.o=.d)

TARGET   := TestChain

# Default target
.PHONY: all
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile with header dependency generation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Pull in auto-generated dependency files
-include $(DEPS)

# Clean build artifacts
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

# Clean and rebuild from scratch
.PHONY: rebuild
rebuild: clean all
