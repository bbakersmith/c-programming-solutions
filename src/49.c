/**
 * @file 49.c
 *
 * @brief Prime permutations
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.c"

void get_digits(uint16_t num, uint8_t buffer[4]) {
  for(uint8_t i = 0; i < 4; i++) {
    buffer[i] = num % 10;
    num /= 10;
  }
}

int compare_digits(const void *a_void, const void *b_void) {
  uint8_t *a = (uint8_t *)a_void;
  uint8_t *b = (uint8_t *)b_void;
  return *a < *b;
}

bool are_permutations(uint16_t x, uint16_t y, uint16_t z) {
  uint8_t x_digits[4];
  get_digits(x, x_digits);

  uint8_t y_digits[4];
  get_digits(y, y_digits);

  uint8_t z_digits[4];
  get_digits(z, z_digits);

  qsort(x_digits, 4, 1, compare_digits);
  qsort(y_digits, 4, 1, compare_digits);
  qsort(z_digits, 4, 1, compare_digits);

  for(uint8_t i = 0; i < 4; i++) {
    if(x_digits[i] != y_digits[i] || y_digits[i] != z_digits[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  Sieve sieve = sieve_of_eratosthenes_2(9999);

  for(uint16_t ix = 0; ix < (sieve.primes_len - 2); ix++) {
    uint16_t x = sieve.primes[ix];

    if(x < 1000) continue;

    for(uint16_t iy = ix + 1; iy < (sieve.primes_len - 1); iy++) {
      uint16_t y = sieve.primes[iy];
      uint16_t diff = y - x;
      uint16_t z = y + diff;
      if(is_prime(&sieve, z)) {
        if(are_permutations(x, y, z)) {
          printf("%i %i %i (%i)\n", x, y, z, diff);
        }
      }
    }
  }
  return 0;
}
