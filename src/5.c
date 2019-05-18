/**
 * @file 5.c
 *
 * @brief Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10
 * without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers
 * from 1 to 20?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

bool is_smallest_multiple(char max, uint64_t candidate) {
  if(candidate & 1)
    return false;

  for(char i = 3; i <= max; i++) {
    if(candidate % i)
      return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  char max = atoi(argv[1]);

  for(uint64_t i = max; i < UINT64_MAX; i++) {
    if(is_smallest_multiple(max, i)) {
      printf("Smallest multiple: %lu\n", i);
      return 0;
    }
  }

  printf("No smallest multiple found :(\n");
  return 1;
}
