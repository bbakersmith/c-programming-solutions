/**
 * @file 24.c
 *
 * @brief Lexographic permutations
 *
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits
 * 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

uint64_t permutations[3630000];
uint32_t permutations_len = 0;

uint64_t pow_of_ten(uint8_t power) {
  uint64_t result = 1;
  for(uint8_t i = 0; i < power; i++) {
    result *= 10;
  }
  return result;
}

uint64_t digits_to_int(uint8_t digits[], uint8_t len) {
  uint64_t result = 0;
  for(uint8_t i = 0; i < len; i++) {
    result += digits[i] * pow_of_ten(i);
  }
  return result;
}

bool is_not_in_digits(uint8_t digits[10], uint8_t len, uint8_t value) {
  for(uint8_t i = 0; i < len; i++) {
    if(digits[i] == value) return false;
  }
  return true;
}

void calculate_permutations(uint8_t digits[10], uint8_t len, uint8_t max) {
  if(len < max) {
    for(uint8_t d = 0; d < max; d++) {
      if(is_not_in_digits(digits, len, d)) {
        digits[len] = d;
        calculate_permutations(digits, len + 1, max);
      }
    }
  } else {
    permutations[permutations_len] = digits_to_int(digits, len);
    permutations_len++;
  }
}

int compare_permuations(const void *a_ptr, const void *b_ptr) {
  uint64_t *a = (uint64_t *) a_ptr;
  uint64_t *b = (uint64_t *) b_ptr;
  return *a > *b;
}

int main(int argc, char *argv[]) {
  uint32_t max = atoi(argv[1]);
  uint32_t index = atoi(argv[2]);

  uint8_t digits[10];
  calculate_permutations(digits, 0, max);

  qsort(permutations, permutations_len, 8, &compare_permuations);

  printf("Permutations len: %i\n", permutations_len);
  printf("Permutation #%i: %lu\n", index, permutations[index - 1]);

  return 0;
}
