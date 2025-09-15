```makefile
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/app

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)

```
