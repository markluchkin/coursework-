CC := gcc

CFLAGS := -Wall -std=gnu99 -g

SRCS := src/main.c src/output.c src/input.c src/sort.c src/sortByWordsLength.c 

TARGET := cw

all: cw

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(TARGET)