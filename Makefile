.PHONY: clean

BUILD_DIR=build
LIB_DIR=lib
SOURCE_DIR=src

SOURCES=$(wildcard $(SOURCE_DIR)/*.c)
OUTPUTS=$(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%, $(SOURCES))

CC ?= gcc
CFLAGS=-std=c11 -O3 -lm -I$(LIB_DIR) -Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op

all: $(OUTPUTS)

$(BUILD_DIR)/%: src/%.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm $(BUILD_DIR)/* 2>&1 || true
