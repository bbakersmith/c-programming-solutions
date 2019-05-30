/**
 * @file 39.c
 */

#include "stdbool.h"
#include "stdint.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float pe_39_right_triangle_a(uint16_t p, uint16_t b) {
  float x = (p - (b * 2.0));
  float y = (2.0 * (p - b));
  float result = p * (x / y);
  return result;
}

bool pe_39_right_triangle(uint16_t p, uint16_t b) {
  float a = pe_39_right_triangle_a(p, b);
  if(0 < a && a < p && (double) a == ceil(a)) {
    /* printf("p %i | a: %f, b: %i, c: %i\n", p, (double) a, b, (int) (p - a - b)); */
    return true;
  } else {
    return false;
  }
}

uint16_t pe_39_count_right_triangles(uint16_t p) {
  uint16_t count = 0;
  for(uint16_t b = 3; b <= p; b++) {
    count += pe_39_right_triangle(p, b);
  }
  return count / 2;
}

#ifndef _IS_TEST
int main(int argc, char *argv[]) {
  uint16_t max = atoi(argv[1]);

  uint16_t highest_count = 0;
  uint16_t highest_p = 1;
  for(uint16_t p = 1; p <= max; p++) {
    uint16_t count = pe_39_count_right_triangles(p);
    if(highest_count < count) {
      highest_count = count;
      highest_p = p;
    }
  }

  printf("P: %i\n", highest_p);
  printf("Count: %i\n", highest_count);
  return 0;
}
#endif
