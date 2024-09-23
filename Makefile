# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror

# Executable name
TARGET = bank_program

# Source files
SRCS = main.cpp BankFunctions.cpp LinkedList.cpp Utils.cpp  # Ensure Utils.cpp is included here

# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Header files (used for dependency tracking)
DEPS = BankFunctions.h LinkedList.h Node.h Utils.h

# Default rule to compile and link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each .cpp file into an object file
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated object files and the executable
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
