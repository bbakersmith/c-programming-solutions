/**
 * @file 17.c
 *
 * @brief Number letter counts
 *
 * If the numbers 1 to 5 are written out in words:
 * one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive
 * were written out in words, how many letters would be used?
 */

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

#include <stdio.h>

uint8_t count_ones[10] = {
  0, //
  3, // one
  3, // two
  5, // three
  4, // four
  4, // five
  3, // six
  5, // seven
  5, // eight
  4  // nine
};

uint8_t count_teens[10] = {
  3, // ten
  6, // eleven
  6, // twelve
  8, // thirteen
  8, // fourteen
  7, // fifteen
  7, // sixteen
  9, // seventeen
  8, // eighteen
  8  // nineteen
};

uint8_t count_tens[10] = {
  0, //
  3, // ten
  6, // twenty
  6, // thirty
  5, // forty
  5, // fifty
  5, // sixty
  7, // seventy
  6, // eighty
  6  // ninety
};

uint8_t count_hundred = 7;
uint8_t count_and = 3;
uint8_t count_thousand = 8;

typedef struct Digits {
  uint16_t num;
  uint8_t arr[4];
  uint8_t len;
} Digits;

Digits parse_digits(uint16_t num) {
  Digits digits = {
    .len = 0,
    .num = num
  };

  while(0 < num) {
    digits.arr[digits.len] = num % 10;
    digits.len++;
    num /= 10;
  }

  return digits;
}

uint8_t count_letters(Digits *digits) {
  uint8_t count = 0;
  for(uint8_t i = 0; i < digits->len; i++) {
    switch(i) {
      case 0:
        if(1 < digits->len && digits->arr[1] == 1) {
          continue;
        } else {
          count += count_ones[digits->arr[0]];
        }
        break;
      case 1:
        if(digits->arr[1] == 1) {
          count += count_teens[digits->arr[0]];
        } else {
          count += count_tens[digits->arr[1]];
        }
        break;
      case 2:
        if(digits->arr[2] == 0) {
          continue;
        } else {
          count += count_ones[digits->arr[2]] + count_hundred;
        }
        break;
      case 3:
        count += count_ones[digits->arr[3]] + count_thousand;
        break;
      default:
        break;
    }
  }

  if(2 < digits->len && !(digits->arr[0] == 0 && digits->arr[1] == 0)) {
    count += count_and;
  }

  return count;
}

int main(int argc, char *argv[]) {
  uint16_t num = atoi(argv[1]);

  uint64_t total = 0;
  for(uint16_t i = 1; i <= num; i++) {
    Digits digits = parse_digits(i);
    total += count_letters(&digits);
  }

  printf("Total: %lu\n", total);
  return 0;
}
