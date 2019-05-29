/**
 * @file 21.c
 *
 * @brief Amicable numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide
 * evenly into n).
 *
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and
 * b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 * therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

uint64_t pe_21_sum_of_divisors(uint16_t num) {
  uint64_t sum = 1;
  for(uint16_t i = 2; i < num; i++) {
    if(num % i == 0) sum += i;
  }
  return sum;
}

uint64_t pe_21_sum_of_amicable_numbers(uint16_t top) {
  uint64_t sum = 0;
  for(uint16_t i = 1; i < top; i++) {
    uint64_t candidate = pe_21_sum_of_divisors(i);
    if(i != candidate && candidate < top) {
      uint64_t candidate_sum = pe_21_sum_of_divisors(candidate);
      if(candidate_sum == i) {
        sum += candidate + i;
      }
    }
  }
  return sum / 2;
}

#ifndef _IS_TEST
int main(int argc, char *argv[]) {
  uint16_t top = atoi(argv[1]);
  uint64_t sum = pe_21_sum_of_amicable_numbers(top);
  printf("Sum: %lu\n", sum);
  return 0;
}
#endif
