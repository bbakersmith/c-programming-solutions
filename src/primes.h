#ifndef _PRIMES_H_
#define _PRIMES_H_

#include "stdbool.h"
#include "stdint.h"

#include <math.h>

typedef struct Sieve {
  uint64_t primes[100000];
  uint64_t primes_len;
} Sieve;

typedef struct SieveFlex {
  uint64_t *primes;
  uint64_t primes_len;
} SieveFlex;

Sieve sieve_of_eratosthenes(uint64_t max);
Sieve sieve_of_eratosthenes_2(uint64_t max);
SieveFlex sieve_of_eratosthenes_2_flex(uint64_t max, uint64_t *primes);
bool is_prime(Sieve *sieve, uint32_t candidate);
bool is_prime_flex(SieveFlex *sieve, uint32_t candidate);

#endif
