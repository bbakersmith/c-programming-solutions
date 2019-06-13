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

#define TRI_ROWS 100

char *strtok_r(char *str, const char *delim, char **saveptr);

void file_read_row(FILE *file, uint64_t row[TRI_ROWS]) {
  char row_raw[310];
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

int main(int argc, char *argv[]) {
  char *filename = argv[1];

  FILE *file = fopen(filename, "r");

  if(file == NULL) {
    printf("Failed to open file.\n");
    exit(1);
  }

  uint64_t pyramid[TRI_ROWS][TRI_ROWS];
  for(uint8_t i = 0; i < TRI_ROWS; i++) {
    file_read_row(file, pyramid[i]);
  }

  // TODO
  // - starting from 2nd to last row
  // - get largest of lower 2 values (n)(n + 1)
  // - add it to n

  uint8_t row = TRI_ROWS - 2;
  while(true) {
    for(uint8_t col = 0; col <= row; col++) {
      uint64_t a = pyramid[row + 1][col];
      uint64_t b = pyramid[row + 1][col + 1];
      if(b < a) {
        pyramid[row][col] += a;
      } else {
        pyramid[row][col] += b;
      }
    }
    if(row == 0) {
      break;
    } else {
      row--;
    }
  }

  printf("Sum: %lu\n", pyramid[0][0]);
  return 0;
}
