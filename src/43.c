/**
 * @file 43.c
 *
 * @brief Sub-string divisibility
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the
 * digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility
 * property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "permutations.h"

uint32_t pe_43_num_from_digits(char digits[16], uint8_t len) {
  uint32_t value = 0;
  uint8_t i = len - 1;
  uint32_t multiplier = 1;
  while(true) {
    value += (digits[i] * multiplier);
    if(i == 0) {
      return value;
    } else {
      multiplier *= 10;
      i--;
    }
  }
}

bool pe_43_is_special(Permutations *p) {
  uint8_t divisor[7] = {2, 3, 5, 7, 11, 13, 17};
  for(uint8_t i = 0; i < 7; i++) {
    uint16_t val = pe_43_num_from_digits(&p->current[(i + 1)], 3);
    if((val % divisor[i]) != 0) {
      return false;
    }
  }
  return true;
}

#ifndef _IS_TEST
int main() {

  // how to generate pandigital numbers? there are a lot, like 3265920

  char start[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Permutations permutations = permutations_new(start, 10);

  uint64_t sum = 0;
  while(!permutations.last) {
    permutations_next(&permutations);
    if(pe_43_is_special(&permutations)) {
      sum += pe_43_num_from_digits(permutations.current, 10);
    }
  }

  printf("Sum: %lu\n", sum);
  return 0;
}
#endif
