/**
 * @file 11.c
 *
 * @brief Largest product in a grid
 *
 * In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
 *
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 *
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_COLUMNS 20
#define GRID_ROWS 20
#define ADJACENT_NUMBERS 4

typedef struct Grid {
  uint8_t rows[GRID_ROWS][GRID_COLUMNS];
  uint8_t pos_x;
  uint8_t pos_y;
} Grid;

void print_grid(Grid *grid) {
  for(uint8_t y = 0; y < GRID_ROWS; y++) {
    for(uint8_t x = 0; x < GRID_COLUMNS; x++) {
      printf("%i ", grid->rows[y][x]);
    }
    printf("\n");
  }
}

void load_row(FILE *file, uint8_t row[GRID_COLUMNS]) {
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

Grid new_grid(char *filename) {
  Grid grid = {
    .pos_x = 0,
    .pos_y = 0
  };

  FILE *file = fopen(filename, "r");

  if(file == NULL) {
    printf("Failed to open file.\n");
    exit(1);
  }

  for(uint8_t i = 0; i < GRID_ROWS; i ++) {
    load_row(file, grid.rows[i]);
  }

  return grid;
}

bool in_bounds_left(Grid *grid) {
  return (ADJACENT_NUMBERS <= grid->pos_x + 1);
}

bool in_bounds_right(Grid *grid) {
  return grid->pos_x <= (GRID_COLUMNS - ADJACENT_NUMBERS);
}

bool in_bounds_down(Grid *grid) {
  return grid->pos_y <= (GRID_ROWS - ADJACENT_NUMBERS);
}

bool in_bounds_diagonal_left(Grid *grid) {
  return in_bounds_left(grid) && in_bounds_down(grid);
}

bool in_bounds_diagonal_right(Grid *grid) {
  return in_bounds_right(grid) && in_bounds_down(grid);
}

uint8_t current_value(Grid *grid) {
  return grid->rows[grid->pos_y][grid->pos_x];
}

uint64_t product_right(Grid *grid) {
  if(!in_bounds_right(grid))
    return 0;

  uint64_t product = current_value(grid);

  for(uint8_t i = 1; i < ADJACENT_NUMBERS; i++) {
    product *= grid->rows[grid->pos_y][grid->pos_x + i];
  }

  return product;
}

uint64_t product_down(Grid *grid) {
  if(!in_bounds_down(grid))
    return 0;

  uint64_t product = current_value(grid);

  for(uint8_t i = 1; i < ADJACENT_NUMBERS; i++) {
    product *= grid->rows[grid->pos_y + i][grid->pos_x];
  }

  return product;
}

uint64_t product_diagonal_left(Grid *grid) {
  if(!in_bounds_diagonal_left(grid))
    return 0;

  uint64_t product = current_value(grid);

  for(uint8_t i = 1; i < ADJACENT_NUMBERS; i++) {
    product *= grid->rows[grid->pos_y + i][grid->pos_x - i];
  }

  return product;
}

uint64_t product_diagonal_right(Grid *grid) {
  if(!in_bounds_diagonal_right(grid))
    return 0;

  uint64_t product = current_value(grid);

  for(uint8_t i = 1; i < ADJACENT_NUMBERS; i++) {
    product *= grid->rows[grid->pos_y + i][grid->pos_x + i];
  }

  return product;
}

int main() {
  Grid grid = new_grid("data/11.txt");

  uint64_t largest_product = 0;

  for(uint8_t y = 0; y < GRID_ROWS; y++) {
    grid.pos_y = y;
    for(uint8_t x = 0; x < GRID_COLUMNS; x++) {
      grid.pos_x = x;

      uint64_t candidate = 0;

      candidate = product_right(&grid);
      if(largest_product < candidate) largest_product = candidate;

      candidate = product_down(&grid);
      if(largest_product < candidate) largest_product = candidate;

      candidate = product_diagonal_right(&grid);
      if(largest_product < candidate) largest_product = candidate;

      candidate = product_diagonal_left(&grid);
      if(largest_product < candidate) largest_product = candidate;
    }
  }

  printf("Largest product: %lu\n", largest_product);

  // print_grid(&grid);
}
