.PHONY: clean

BUILD_DIR=build
SOURCE_DIR=src

SOURCES=$(wildcard $(SOURCE_DIR)/*.c)
OUTPUTS=$(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%, $(SOURCES))

CC=gcc
CFLAGS=-Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op

all: $(OUTPUTS)

$(BUILD_DIR)/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(BUILD_DIR)/* 2>&1 || true
