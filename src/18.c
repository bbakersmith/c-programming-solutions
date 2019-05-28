/**
 * By starting at the top of the triangle below and moving to adjacent numbers on the row
 * below, the maximum total from top to bottom is 23.
 *
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRI_ROWS 15

char *strtok_r(char *str, const char *delim, char **saveptr);

void file_read_row(FILE *file, char row[TRI_ROWS]) {
  char row_raw[255];
  fgets(row_raw, sizeof(row_raw), file);

  char *token;
  char *rest = row_raw;
  uint8_t column = 0;

  while(true) {
    token = strtok_r(rest, " ", &rest);
    if(token == NULL) break;
    row[column] = atoi(token);
    column++;
  }
}

uint64_t subtree_sum(char pyramid[TRI_ROWS][TRI_ROWS], uint8_t row, uint8_t column) {
  uint64_t sum = 0;

  uint8_t depth = 0;
  while((row + depth) < TRI_ROWS) {
    for(uint8_t i = 0; i <= depth; i++) {
      /* printf("i: %i\n", i); */
      sum += pyramid[row + depth][column + i];
    }
    depth++;
  }

  return sum;
}

int main(int argc, char *argv[]) {
  char *filename = argv[1];

  FILE *file = fopen(filename, "r");

  if(file == NULL) {
    printf("Failed to open file.\n");
    exit(1);
  }

  char pyramid[TRI_ROWS][TRI_ROWS];
  for(uint8_t i = 0; i < TRI_ROWS; i++) {
    file_read_row(file, pyramid[i]);
  }

  /* printf("Row... "); */
  /* for(uint8_t i = 0; i < 3; i++) { */
  /*   printf("%i ", pyramid[2][i]); */
  /* } */
  /* printf("\n"); */

  // TODO

  uint8_t row = 0;
  uint8_t column = 0;
  uint64_t sum = 0;
  while(true) {
    printf("(%i, %i)\n", row, column);
    sum += pyramid[row][column];
    row++;
    if(TRI_ROWS <= row) break;
    uint64_t left_subtree_sum = subtree_sum(pyramid, row, column);
    uint64_t right_subtree_sum = subtree_sum(pyramid, row, column + 1);
    printf("%lu < %lu ?\n", left_subtree_sum, right_subtree_sum);
    if(left_subtree_sum < right_subtree_sum) column++;
  }

  printf("Sum: %lu\n", sum);
  return 0;
}
