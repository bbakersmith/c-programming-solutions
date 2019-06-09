/**
 * @file 13.c
 */
#include <gmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_DIGITS 50
#define INPUT_COUNT 100
#define OUTPUT_DIGITS 10

/**
 * Parse the next input number from a row of a file, truncate to desired
 * number of digits.
 */
uint64_t pe_13_parse_input(FILE *file) {
  char line[255];
  fgets(line, sizeof(line), file);
  return atol(line);
}

uint64_t pe_13_truncate_num(uint64_t num) {
  char buffer[11];
  for(uint8_t i = 0; i < 10; i++) {
    if(0 < num) {
      buffer[9 - i] = (num % 10) + '0';
      num /= 10;
    } else {
      buffer[9 - i] = '0';
    }
  }

  buffer[10] = '\0';

  return atol(buffer);
}

#ifndef _IS_TEST
int main() {
  mpz_t next;
  mpz_t result;
  mpz_init_set_ui(result, 0);

  FILE *file = fopen("data/13.txt", "r");

  for(uint32_t i = 0; i < INPUT_COUNT; i++) {
    char line[255];
    fgets(line, sizeof(line), file);

    mpz_set_str(next, line, 10);
    mpz_add(result, result, next);
  }

  printf("Result: %s\n", mpz_get_str(NULL, 10, result));
  return 0;
}
#endif
