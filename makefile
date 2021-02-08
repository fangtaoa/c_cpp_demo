CC=gcc
FLAG=-g -o

TARGET=demo
SOURCE=07-multi_pointer.c

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) $(FLAG) $(TARGET) $(SOURCE)


clean:
	rm -f $(TARGET)
