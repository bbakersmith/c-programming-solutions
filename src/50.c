/**
 * @file 50.c
 *
 * @brief Consecutive prime sum
 *
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 *     41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime,
 * contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive
 * primes?
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

#include "primes.c"

int main(int argc, char *argv[]) {
  uint32_t max = atoi(argv[1]);

  Sieve sieve = sieve_of_eratosthenes_2(max);

  uint32_t largest_sum_of_consecutive_primes = 0;
  uint32_t largest_consecutive_primes_count = 0;
  for(uint32_t i = 0; i < sieve.primes_len && sieve.primes[i] < (max / 2); i++) {
    uint32_t consecutive_primes_count = 0;
    uint32_t sum_of_primes = 0;
    uint32_t prime_index = i;

    while(sum_of_primes < max) {
      consecutive_primes_count++;
      sum_of_primes += sieve.primes[prime_index];
      if(is_prime(&sieve, sum_of_primes)) {
        if(largest_consecutive_primes_count < consecutive_primes_count) {
          largest_sum_of_consecutive_primes = sum_of_primes;
          largest_consecutive_primes_count = consecutive_primes_count;
        }
      }
      prime_index++;
    }
  }

  printf("Largest sum of consecutive primes: %i\n", largest_sum_of_consecutive_primes);
  printf("Largest consecutive primes count: %i\n", largest_consecutive_primes_count);

  return 0;
}
