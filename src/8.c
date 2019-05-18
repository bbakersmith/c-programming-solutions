/**
 * @file 8.c
 *
 * The four adjacent digits in the 1000-digit number that have the greatest product are
 *
 *    9 × 9 × 8 × 9 = 5832.
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest
 * product. What is the value of this product?
 */

#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

typedef struct Buffer {
  char items[1000];
  char count;
  char head;
} Buffer;

Buffer buffer_new(char count) {
  Buffer buffer = {
    .count = count,
    .head = 0
  };
  return buffer;
}

uint64_t cycle_buffer(Buffer *buffer, char next) {
  buffer->items[buffer->head] = next;

  buffer->head++;
  if(buffer->count <= buffer->head)
    buffer->head = 0;

  uint64_t product = buffer->items[0];
  for(char i = 1; i < buffer->count; i++) {
    product *= buffer->items[i];
  }

  return product;
}

int main(int argc, char *argv[]) {
  char *filename = argv[1];
  char count = atoi(argv[2]);

  FILE *file = fopen(filename, "r");

  if(file == NULL) {
    printf("Failed to open file.\n");
    return 1;
  }

  uint64_t result = 0;
  Buffer buffer = buffer_new(count);

  char the_big_number[1024];
  fgets(the_big_number, 1024, file);

  for(int i = 0; i < 1000; i++) {
    char next = the_big_number[i] - '0';
    uint64_t product = cycle_buffer(&buffer, next);
    if(result < product)
      result = product;
  }

  fclose(file);

  printf("Largest product: %llu\n", result);

  return 0;
}


