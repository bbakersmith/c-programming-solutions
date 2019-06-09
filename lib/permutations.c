/**
  * @file permutations.c
  */
#include "permutations.h"

uint32_t permutations_count_max(uint8_t len) {
  uint32_t count_max = 1;
  for(uint8_t i = 2; i <= len; i++) {
    count_max *= i;
  }
  return count_max;
}

Permutations permutations_new(char start[16], uint8_t len) {
  uint32_t count_max = permutations_count_max(len);
  Permutations p = {
    .count = 1,
    .count_max = count_max,
    .i = 0,
    .last = false,
    .len = len
  };
  for(uint8_t i = 0; i < len; i++) {
    p.current[i] = start[i];
    p.state[i] = 0;
  }
  return p;
}

void permutations_swap(char *a, char *b) {
  char a_copy = *a;
  *a = *b;
  *b = a_copy;
}

/**
 * Find next permutation using heap's algorithm.
 *
 * https://en.wikipedia.org/wiki/Heap%27s_algorithm
 */
void permutations_next(Permutations *p) {
  if(p->state[p->i] < p->i) {
    if(p->i & 1) {
      permutations_swap(&p->current[p->state[p->i]], &p->current[p->i]);
    } else {
      permutations_swap(&p->current[0], &p->current[p->i]);
    }
    p->state[p->i]++;
    p->i = 0;
    p->count++;
    if(p->count_max <= p->count) {
      p->last = true;
    }
  } else {
    p->state[p->i] = 0;
    p->i++;
    permutations_next(p);
  }
}
