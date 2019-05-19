/**
 * @file 15.c
 *
 * @brief Lattice paths
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right
 * corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

/*
 * 1x1 (2)
 * . .
 * . .
 * 2, 1, (1)
 *
 * 2x2 (6)
 * . . .
 * . . .
 * . . .
 * 2, 2, 2, 1, (1)
 *
 * 3x3 (20?)
 * . . . .
 * . . . .
 * . . . .
 * . . . .
 * 2, 3, 6, 3, 2, (1)
 * 2, 2, [2, 2], 2, 1, (1)
 */

#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  RIGHT,
  DOWN
} Direction;

typedef struct Maze {
  uint64_t branches;
  uint8_t size;
} Maze;

void move_rat(Maze *maze, uint8_t x, uint8_t y, Direction direction) {
  switch(direction) {
    case RIGHT:
      x++;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }

  /* if(rat->pos_x == rat->maze_size && rat->pos_y == rat->maze_size) */
  /*   return; */

  if(x != maze->size && y != maze->size)
    maze->branches++;

  /* printf("Move %i to (%i, %i) [%lu]\n", direction, x, y, maze->branches); */

  if(x != maze->size)
    move_rat(maze, x, y, RIGHT);

  if(y != maze->size)
    move_rat(maze, x, y, DOWN);
}

int main(int argc, char *argv[]) {
  uint8_t maze_size = atoi(argv[1]);

  Maze maze = {
    .branches = 2,
    .size = maze_size
  };

  move_rat(&maze, 0, 0, RIGHT);
  move_rat(&maze, 0, 0, DOWN);

  printf("Branches: %lu\n", maze.branches);
  return 0;
}
