.PHONY: clean

BUILD_DIR=build
LIB_DIR=lib
SOURCE_DIR=src
TEST_DIR=test
UNITY_DIR=Unity

SOURCES=$(wildcard $(SOURCE_DIR)/*.c)
OUTPUTS=$(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%, $(SOURCES))

CC ?= gcc
CFLAGS=-std=c11 -O3 -lm -lgmp -I$(SOURCE_DIR) -I$(LIB_DIR) -Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op

TEST_SOURCE_FILES=\
  $(UNITY_DIR)/src/unity.c \
  $(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
	test/test_21.c \
	test/test_39.c \
	test/test_40.c \
	test/run_tests.c

TEST_FLAGS=-Itest -I$(UNITY_DIR)/src -I$(UNITY_DIR)/extras/fixture/src -D_IS_TEST

TEST_TARGET=$(BUILD_DIR)/run_tests.o

all: $(OUTPUTS)

$(BUILD_DIR)/%: src/%.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm $(BUILD_DIR)/* 2>&1 || true

test: $(TEST_TARGET)

$(TEST_TARGET): clean
	$(CC) $(CFLAGS) $(TEST_FLAGS) $(TEST_SOURCE_FILES) -o $(TEST_TARGET)
	$(TEST_TARGET) -v
