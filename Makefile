CC = cc

BIN_NAME := rot-solver

CFLAGS := -O2 -Wpedantic -Wswitch-enum -Wall -Wextra -Wconversion -std=c89 -g

src_files = decipher main memory_safety menu compare file_reading arguments take_input base64 safe_copy

SRC_PATH := $(addprefix src/, $(src_files))
SRCS := $(addsuffix .c, $(SRC_PATH))

.PHONY: all
all: 
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS) -Werror

.PHONY: warn
warn: 
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS)

.PHONY: clean
clean:
	rm $(BIN_NAME) *.o
