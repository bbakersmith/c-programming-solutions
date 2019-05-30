/**
 * @file 40.c
 *
 * @brief Champernowne's constant
 *
 * An irrational decimal fraction is created by concatenating the positive integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the following
 * expression.
 *
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include "stdint.h"

#include <stdio.h>

typedef struct Buffer {
  char digits[16];
  uint8_t len;
} Buffer;

void pe_40_load_buffer(Buffer *buffer, uint32_t num) {
  uint8_t count = 0;
  buffer->len = 0;
  while(0 < num) {
    count++;
    buffer->digits[buffer->len] = num % 10;
    buffer->len++;
    num /= 10;
  }
}

char pe_40_calculate_champernowne_constant(uint32_t num) {
  uint32_t current_number = 1;
  Buffer buffer = {
    .digits = {1},
    .len = 1
  };
  for(uint32_t i = 1; i < num; i++) {
    /* printf("%i: %i\n", i, buffer.digits[buffer.len - 1]); */
    if(1 < buffer.len) {
      buffer.len--;
    } else {
      current_number++;
      pe_40_load_buffer(&buffer, current_number);
    }
  }
  return buffer.digits[buffer.len - 1];;
}

#ifndef _IS_TEST
int main(int argc, char *argv[]) {
  uint64_t result = pe_40_calculate_champernowne_constant(1)
    * pe_40_calculate_champernowne_constant(10)
    * pe_40_calculate_champernowne_constant(100)
    * pe_40_calculate_champernowne_constant(1000)
    * pe_40_calculate_champernowne_constant(10000)
    * pe_40_calculate_champernowne_constant(100000)
    * pe_40_calculate_champernowne_constant(1000000);

  printf("Result: %lu\n", result);
  return 0;
}
#endif
