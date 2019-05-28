/**
 * @file 16.c
 *
 * @brief Power digit sum
 *
 * 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 21000?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char *argv[]) {
  uint64_t power = atoi(argv[1]);

  mpz_t base;
  mpz_init_set_ui(base, 2);

  mpz_t result;
  mpz_init_set_ui(result, 0);
  mpz_pow_ui(result, base, power);

  char *digits = mpz_get_str(NULL, 10, result);

  uint32_t sum = 0;
  uint16_t i = 0;
  while(true) {
    char d = digits[i];
    if(d == '\0') break;
    printf("D: %c\n", d);
    sum += (d - '0');
    i++;
  }

  printf("Print: %s\n", digits);
  printf("Sum: %i\n", sum);

  return 0;
}
