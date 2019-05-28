/**
 * @file 20.c
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char *argv[]) {
  uint8_t number = atoi(argv[1]);

  mpz_t total;
  mpz_init_set_ui(total, 1);

  for(uint8_t i = 1; i <= number; i++) {
    mpz_mul_ui(total, total, i);
  }

  char *total_str = mpz_get_str(NULL, 10, total);

  uint64_t sum = 0;
  for(uint32_t i = 0; total_str[i] != '\0'; i++) {
    sum += total_str[i] - '0';
  }

  printf("Total: %s\n", total_str);
  printf("Sum: %lu\n", sum);
  return 0;
}
