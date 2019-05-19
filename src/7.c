/**
 * @file 7.c
 *
 * @brief 10,001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

#include "primes.c"

int main(int argc, char *argv[]) {
  uint32_t number = atol(argv[1]);
  Sieve sieve = sieve_of_eratosthenes(1000000);

  printf("Primes found: %lu\n", sieve.primes_len);
  printf("Prime %i: %lu\n", number, sieve.primes[number - 2]);
  return 0;
}
