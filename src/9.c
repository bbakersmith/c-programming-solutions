/**
 * @file 9.c
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c,
 * for which, a2 + b2 = c2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  uint16_t target = atoi(argv[1]);

  for(uint16_t a = 2; a < 1000; a++) {
    for(uint16_t b = 2; b < 1000; b++) {
      for(uint16_t c = 2; c < 1000; c++) {
        if(c < a || c < b) continue;
        if((a * a) + (b * b) == (c * c)) {
          if((a + b + c) == target) {
            printf("Product (%i %i %i): %i\n", a, b, c, (a * b * c));
            return 0;
          }
        }
      }
    }
  }

  printf("No target found for %i.\n", target);
  return 1;
}
