# Define variables
# Compile
CC = gcc 

# Shows all warnings
CFLAGS = -Wall 

# Optimization level
LDFLAGS = -lm

# Define target executable
# TARGET = test
TARGET = ./app

# Define source file , this can be a list of files e.g main.c, file1.c, file2.c, to capture all the source files under the current directory, you can use wildcard e.g. *.c
# SRC = l23_common_headers.c
SRC = $(wildcard *.c)

# Build target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean build files
clean:
	rm -f $(TARGET)

# Run the program
#To run the program, you can use the following command:
# type make run or just make
