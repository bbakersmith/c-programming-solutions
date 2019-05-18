/**
 * @file 3.c
 *
 * @brief Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

bool is_factor(uint64_t candidate, uint64_t target) {
  return (target % candidate) == 0;
}

bool is_prime(uint64_t candidate) {
  if(!(candidate & 1) || (candidate % 3) == 0)
    return false;

  for(uint64_t i = 5; (i * i) <= candidate; i += 6) {
    if(is_factor(i, candidate) || (candidate % (i + 2)) == 0)
      return false;
  }

  return true;
}

uint8_t main(uint8_t argc, uint8_t *argv[]) {
  uint64_t number = atoi(argv[1]);

  uint64_t halfway = number / 2;

  for(uint64_t i = halfway; 2 < i; i--) {
    if(is_factor(i, number)) {
      if(is_prime(i)) {
        printf("Largest Prime Factor: %lu\n", i);
        return 0;
      }
    }
  }

  printf("No Prime Factors!\n");
  return 1;
}
