CC = cc

BIN_NAME := rot-solver

src_files = decipher main memory_safety menu compare file_reading arguments take_input base64 safe_copy
CFLAGS := -O2 -Wpedantic -Wswitch-enum -Wall -Wextra -Wconversion -std=c89
SRC_PATH := $(addprefix src/, $(src_files))
SRCS := $(addsuffix .c, $(SRC_PATH))

.PHONY: all
all: 
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS) -Werror

.PHONY: clean
clean:
	rm $(BIN_NAME) *.o
