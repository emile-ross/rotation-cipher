CC = cc

BIN_NAME := rot-solver

CFLAGS := -O2 -Wpedantic -Wswitch-enum -Wall -Wextra -Wconversion -g -O3 -march=native
src_files = arguments base64 compare encoding file_reading main memory_safety menu safe_copy take_input

SRC_PATH := $(addprefix src/, $(src_files))
SRCS := $(addsuffix .c, $(SRC_PATH))

time = $(shell date --iso-8601='date')

.PHONY: all
all: 
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS) -std=c89 -Werror

.PHONY: warn
warn: 
	@# this simply compiles while ignoring the warnings
	@# only use this for testing
	$(CC) $(SRCS) -o $(BIN_NAME) $(CFLAGS)

.PHONY: clean
clean:
	rm *.o $(BIN_NAME)

test:
	valgrind --leak-check=full --log-file=$(time)-valgrind.log --show-leak-kinds=all -s ./rot-solver 'SGVsbG8gd29ybGQ='

.PHONY: install
install:
	./root_check.sh
	# install the package
	cp $(BIN_NAME) /usr/bin/$(BIN_NAME)
