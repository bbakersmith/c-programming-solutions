/**
 * @file 28.c
 *
 * @brief Number spiral diagonals
 *
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  RIGHT,
  BOTTOM,
  LEFT,
  TOP
} Side;

Side next_side(Side current_side) {
  if(current_side == TOP) {
    return RIGHT;
  } else {
    return current_side + 1;
  }
}

int main(int argc, char *argv[]) {
  uint16_t size = atoi(argv[1]);

  uint8_t side = RIGHT;
  uint16_t ring_index = 0;
  uint16_t side_index = 0;
  uint16_t side_spacer = 1;
  uint64_t diagonal_sum = 1;
  for(uint32_t i = 2; i <= (size * size); i++) {
    if(side_index == side_spacer) {
      diagonal_sum += i;
      side_index = 0;
      side = next_side(side);
      if(side == RIGHT) {
        ring_index++;
        side_spacer = (2 * ring_index) + 1;
      }
    } else {
      side_index++;
    }
  }

  printf("\nSum: %lu\n", diagonal_sum);

  return 0;
}
