/**
 * @file 14.c
 *
 * @brief Longest Collatz sequence
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10
 * terms. Although it has not been proved yet (Collatz Problem), it is thought that
 * all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

uint64_t count_chain(uint64_t value) {
  uint64_t len = 1;
  while(value != 1) {
    if(value & 1) {
      value = (value * 3) + 1;
    } else {
      value /= 2;
    }
    len++;
  }
  return len;
}

int main(int argc, char *argv[]) {
  uint32_t max_start = atoi(argv[1]);

  uint32_t longest_start = 0;
  uint32_t longest_len = 0;
  for(uint32_t s = 1; s < max_start; s++) {
    uint64_t len = count_chain(s);
    if(longest_len < len) {
      longest_len = len;
      longest_start = s;
    }
  }

  printf("Longest Start: %i\n", longest_start);
  printf("Longest Length: %i\n", longest_len);

  return 0;
}
