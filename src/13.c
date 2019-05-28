/**
 * @file 13.c
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *file = fopen("data/13.txt", "r");

  char c;
  while((c = getc(file)) != EOF) {
    printf("%i ", c);
    if(c == '\n') printf("\n");
  }

  // TODO do the addition directly in binary

  printf("\n");
  return 0;
}
