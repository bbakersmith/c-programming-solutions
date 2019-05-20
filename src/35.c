/**
 * @file 35.c
 *
 * @brief Circular primes
 *
 * The number, 197, is called a circular prime because all rotations of the
 * digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

#include "primes.c"

// FIXME
typedef struct Variations {
  uint8_t digits[6];
  uint32_t initial;
  uint32_t items[6];
} Variations;

bool is_circular_prime(Sieve *sieve, uint32_t candidate) {
  // for each rotation
  // - is it prime?
  return true;
}

int main(int argc, char *argv[]) {
  uint32_t max = atoi(argv[1]);
  uint32_t circular_primes_count = 0;

  Sieve sieve = sieve_of_eratosthenes(max);

  for(uint32_t i = 0; i < sieve.primes_len; i++) {
    circular_primes_count += is_circular_prime(&sieve, sieve.primes[i]);
  }

  printf("Circular primes count: %i\n", circular_primes_count);
  return 0;
}
