CC=gcc
FLAG=-g -o

TARGET=demo
SOURCE=06-array.c

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) $(FLAG) $(TARGET) $(SOURCE)


clean:
	rm -f $(TARGET)
