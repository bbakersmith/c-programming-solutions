/**
 * @file 6.c
 *
 * @brief Sums square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers
 * and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural
 * numbers and the square of the sum.
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

uint32_t sum_of_squares(uint16_t max) {
  uint32_t total = 0;
  for(uint16_t i = 1; i <= max; i++) {
    total += i * i;
  }
  return total;
}

uint32_t square_of_sums(uint16_t max) {
  uint32_t total = 0;
  for(uint16_t i = 1; i <= max; i++) {
    total += i;
  }
  return total * total;
}

int main(int argc, char *argv[]) {
  uint16_t max = atoi(argv[1]);

  uint32_t result = square_of_sums(max) - sum_of_squares(max);

  printf("Difference: %i\n", result);

  return 0;
}
