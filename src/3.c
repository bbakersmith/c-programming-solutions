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

#include "primes.c"

bool is_factor(uint64_t candidate, uint64_t target) {
  return (target % candidate) == 0;
}

int main(int argc, char *argv[]) {
  uint64_t number = atol(argv[1]);
  uint64_t half_number = number / 2;
  uint64_t sqrt_half_number = sqrtl(half_number);

  Sieve sqrt_half_sieve = sieve_of_eratosthenes(sqrt_half_number);
  printf("Primes calculated: %lu\n", sqrt_half_sieve.primes_len);

  for(uint64_t i = 2; i < half_number; i++) {
    if((i & 1) && (number % i) == 0) {
      fprintf(stderr, ".");
      uint64_t factor = number / i;
      bool is_largest_prime_factor = true;
      uint64_t pi = 0;
      while(is_largest_prime_factor && pi < sqrt_half_sieve.primes_len) {
        uint64_t known_prime = sqrt_half_sieve.primes[pi];
        if(factor == known_prime) {
          printf("\nLargest prime factor: %lu\n", factor);
          exit(0);
        } else if((factor % known_prime) == 0) {
          is_largest_prime_factor = false;
          // fprintf(stderr, "(%lu, %lu)", factor, sqrt_half_sieve.primes[pi]);
        } else {
          pi++;
        }
      }
      if(is_largest_prime_factor) {
        printf("\nLargest prime factor: %lu\n", factor);
        exit(0);
        break;
      }
    }
  }

  printf("\nNot found...\n");
  return 1;
}
