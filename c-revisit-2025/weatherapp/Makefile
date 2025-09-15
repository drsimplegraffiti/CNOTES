CC = gcc
CFLAGS = -Wall -lcurl -lcjson

TARGET = weather_app

all: $(TARGET)

$(TARGET): main.c
	$(CC) main.c -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)

