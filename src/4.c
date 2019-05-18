/**
 * @file 4.c
 *
 * @brief Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct DigitCharArray {
  uint8_t characters[16];
  uint8_t count;
} DigitCharArray;

/**
 * @return Array of individual digit characters
 */
DigitCharArray digit_char_array_new(uint32_t value) {
  DigitCharArray arr = {
    .count = 0
  };

  uint32_t working_value = value;

  while(true) {
    if(0 < working_value) {
      arr.characters[arr.count] = working_value % 10;
      arr.count++;
      working_value /= 10;
    } else {
      break;
    }
  }

  return arr;
}

bool is_palindrome(DigitCharArray arr) {
  for(uint8_t i = 0; i < (arr.count / 2); i++) {
    uint8_t inverse_index = arr.count - 1 - i;

    if(arr.characters[i] != arr.characters[inverse_index])
      return false;
  }
  return true;
}

int products_compare(const void *a, const void *b) {
  return (*(uint32_t *) b) - (*(uint32_t *) a);
}

int main() {
  uint32_t products[1000000];
  uint32_t products_count;

  for(uint32_t i = 100; i < 1000; i++) {
    for(uint32_t x = 100; x < 1000; x++) {
      products[products_count] = i * x;
      products_count++;
    }
  }

  qsort(products, products_count, 4, &products_compare);

  for(uint32_t i = 0; i < products_count; i++) {
    uint32_t candidate = products[i];
    DigitCharArray arr = digit_char_array_new(candidate);
    if(is_palindrome(arr)) {
      printf("Largest Palindrome: %i\n", candidate);
      return 0;
    }
  }

  printf("No Palindrome found :(");
  return 1;
}
