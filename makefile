CC=gcc
FLAG=-g -o

TARGET=demo
SOURCE=05-string.c

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) $(FLAG) $(TARGET) $(SOURCE)


clean:
	rm -f $(TARGET)
