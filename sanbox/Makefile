CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c utils/utils.c
OBJ = $(SRC:.c=.o)
TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

