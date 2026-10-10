CC = cc

BIN_NAME := rot-solve

CFLAGS := -O2 -Wpedantic -Wswitch-enum -Wall -Wextra -Wconversion -std=c89

src_files = main memory_safety decipher
SRC_PATH := $(addprefix src/, $(src_files))
SRCS := $(addsuffix .c, $(SRC_PATH))

.PHONY: all
all: 
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS) -Werror

.PHONY: clean
clean:
	rm $(BIN_NAME) *.o
