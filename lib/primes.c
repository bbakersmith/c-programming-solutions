/**
 * @file primes.c
 *
 * @brief Library functions for finding prime numbers.
 */

#include "stdbool.h"
#include "stdint.h"

#include <math.h>

typedef struct Sieve {
  uint64_t primes[100000];
  uint64_t primes_len;
} Sieve;

Sieve sieve_of_eratosthenes(uint64_t max) {
  uint64_t sqrt_of_max = sqrtl(max);

  Sieve sieve = {
    .primes_len = 1
  };

  sieve.primes[0] = 3;

  // load up the odd numbers from largest prime to max
  for(uint64_t i = 4; i < max; i++) {
    bool is_prime = true;
    if(i & 1) {
      uint64_t pi = 0;
      while(
        is_prime
        && pi < sieve.primes_len
        && sieve.primes[pi] < sqrt_of_max
      ) {
        if(i % sieve.primes[pi] == 0) {
          is_prime = false;
        } else {
          pi++;
        }
      }
    } else {
      is_prime = false;
    }

    if(is_prime) {
      sieve.primes[sieve.primes_len] = i;
      sieve.primes_len++;
    }
  }

  return sieve;
}
