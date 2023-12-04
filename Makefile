CC := gcc

CFLAGS := -Wall -std=gnu99

SRCS := src/main.c src/output.c src/input.c src/sort.c 

TARGET := cw

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(TARGET)