/**
 * @file primes.c
 *
 * @brief Library functions for finding prime numbers.
 */

#include "primes.h"

Sieve sieve_of_eratosthenes(uint64_t max) {
  uint64_t sqrt_of_max = sqrtl(max) + 1;

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

/**
 * Includes the prime number 2.
 */
Sieve sieve_of_eratosthenes_2(uint64_t max) {
  uint64_t sqrt_of_max = sqrtl(max) + 1;

  Sieve sieve = {
    .primes_len = 1
  };

  sieve.primes[0] = 2;

  // load up the odd numbers from largest prime to max
  for(uint64_t i = 3; i < max; i++) {
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

SieveFlex sieve_of_eratosthenes_2_flex(uint64_t max, uint64_t *primes) {
  uint64_t sqrt_of_max = sqrtl(max) + 1;

  SieveFlex sieve = {
    .primes_len = 1,
    .primes = primes
  };

  sieve.primes[0] = 2;

  // load up the odd numbers from largest prime to max
  for(uint64_t i = 3; i < max; i++) {
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

bool is_prime(Sieve *sieve, uint32_t candidate) {
  for(uint32_t i = 0; i < sieve->primes_len; i++) {
    if(candidate == sieve->primes[i])
      return true;
  }
  return false;
}

bool is_prime_flex(SieveFlex *sieve, uint32_t candidate) {
  for(uint32_t i = 0; i < sieve->primes_len; i++) {
    if(candidate == sieve->primes[i])
      return true;
  }
  return false;
}
