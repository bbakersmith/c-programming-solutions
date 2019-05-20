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

typedef struct Rotations {
  uint32_t numbers[6];
  uint8_t numbers_len;
} Rotations;

void rotate_digits(uint8_t digits[6], uint8_t digits_len) {
  uint8_t first_digit = digits[0];
  for(uint8_t i = 0; i < digits_len - 1; i++) {
    digits[i] = digits[i + 1];
  }
  digits[digits_len - 1] = first_digit;
}

uint32_t digits_to_number(uint8_t digits[6], uint8_t digits_len) {
  uint32_t number = 0;
  for(uint8_t i = 0; i < digits_len; i++) {
    number += digits[i] * pow(10, i);
  }
  /* printf("Digits to number: %i\n", number); */
  return number;
}

Rotations rotations_new(uint32_t number) {
  /* printf("Rotating %i\n", number); */
  uint8_t digits[6];
  uint8_t digits_len = 0;

  uint32_t tmp_number = number;
  while(0 < tmp_number) {
    digits[digits_len] = tmp_number % 10;
    digits_len++;
    tmp_number /= 10;
  }

  Rotations rotations = {
    .numbers_len = digits_len
  };

  for(uint8_t i = 0; i < digits_len; i++) {
    rotate_digits(digits, digits_len);
    rotations.numbers[i] = digits_to_number(digits, digits_len);
  }

  return rotations;
}

bool is_prime(Sieve *sieve, uint32_t candidate) {
  for(uint32_t i = 0; i < sieve->primes_len; i++) {
    if(candidate == sieve->primes[i])
      return true;
  }
  return false;
}

bool is_circular_prime(Sieve *sieve, uint32_t candidate) {
  Rotations rotations = rotations_new(candidate);

  for(uint8_t i = 0; i < rotations.numbers_len; i++) {
    if(!is_prime(sieve, rotations.numbers[i]))
      return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  uint32_t max = atoi(argv[1]);
  uint32_t circular_primes_count = 0;

  Sieve sieve = sieve_of_eratosthenes(max);

  for(uint32_t i = 0; i < sieve.primes_len; i++) {
    circular_primes_count += is_circular_prime(&sieve, sieve.primes[i]);
  }

  // special case handling 2 because the sieve implementation doesn't include it
  circular_primes_count++;

  printf("Circular primes count: %i\n", circular_primes_count);
  return 0;
}
