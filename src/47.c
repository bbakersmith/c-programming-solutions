/**
 * @file 47.c
 *
 * @brief Distinct prime factors
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.c"

int main() {
  Sieve sieve = sieve_of_eratosthenes_2(1000000);

  uint8_t consecutive = 0;
  for(uint32_t i = 100; i < 1000000; i++) {
    uint8_t prime_factors = 0;
    for(uint32_t f = 0; sieve.primes[f] < i && f < sieve.primes_len; f++) {
      if((i % sieve.primes[f]) == 0) {
        prime_factors++;
      }
    }

    if(prime_factors == 4) {
      consecutive++;
    } else {
      consecutive = 0;
    }

    if(consecutive == 4) {
      printf("%i is first of 4 consecutive\n", i-3);
      return 0;
    }
  }

  printf("Failed.\n");
  return 1;
}
