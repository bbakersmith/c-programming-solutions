/**
 * @file 1.c
 *
 * @brief Multiples of 3 and 5
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

bool is_multiple(uint16_t value, uint16_t target) {
  return (value % target) == 0;
}

/**
 * @param value The potential multiple
 * @return      Value of multiple, or zero if not multiple of 3 or 5
 */
uint16_t get_multiple_value(uint16_t value) {
  return (is_multiple(value, 3) || is_multiple(value, 5)) ? value : 0;
}

int main(int argc, char *argv[]) {
  uint16_t max_value = atoi(argv[1]);

  uint64_t total = 0;
  for(uint16_t i = 0; i < max_value; i++) {
    total += get_multiple_value(i);
  }

  printf("Total: %lu\n", total);

  return 0;
}
