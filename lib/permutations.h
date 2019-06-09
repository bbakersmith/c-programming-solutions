/**
  * @file permutations.h
  */
#ifndef _PERMUTATIONS_H_
#define _PERMUTATIONS_H_

#include <stdbool.h>
#include <stdint.h>

#define PERMUTATION_MAX_VALUES 16

typedef struct Permutations {
  char current[PERMUTATION_MAX_VALUES];
  uint8_t state[PERMUTATION_MAX_VALUES];
  uint8_t i;
  uint8_t len;
  uint32_t count;
  uint32_t count_max;
  bool last;
} Permutations;

Permutations permutations_new(char start[16], uint8_t len);
void permutations_next(Permutations *p);
uint32_t permutations_digits_to_int(char digits[16], uint8_t len);

#endif
