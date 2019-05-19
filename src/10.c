/**
 * @file 10.c
 *
 * @brief Summation of primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

#include "primes.c"

int main() {
  Sieve sieve = sieve_of_eratosthenes(2000000);

  uint64_t total = 2;
  for(uint64_t i = 0; i < sieve.primes_len; i++) {
    total += sieve.primes[i];
  }

  printf("Summation of primes: %lu\n", total);
  return 0;
}
