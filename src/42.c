/**
 * @file 42.c
 *
 * The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first
 * ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position
 * and adding these values we form a word value. For example, the word value for SKY is
 *
 * 19 + 11 + 25 = 55 = t10.
 *
 * If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing
 * nearly two-thousand common English words, how many are triangle words?
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PE_42_WORD_MAX_LEN 24
#define PE_42_LETTERS_LEN 26

typedef struct Triangles {
  uint8_t len;
  uint64_t items[200];
} Triangles;

Triangles pe_42_triangle_numbers(uint16_t max) {
  Triangles triangles = {
    .len = 0
  };

  for(uint16_t i = 1; i <= max; i++) {
    uint64_t value = ((i * (i + 1)) / 2);
    if(max < value) break;
    triangles.items[i - 1] = value;
    triangles.len++;
  }

  return triangles;
}

bool pe_42_is_triangle(Triangles *triangles, uint64_t candidate) {
  for(uint8_t i = 0; i < triangles->len; i++) {
    if(candidate == triangles->items[i]) return true;
    if(candidate < triangles->items[i]) break;
  }
  return false;
}

int main() {
  FILE *file = fopen("data/42.txt", "r");

  Triangles triangles = pe_42_triangle_numbers(PE_42_WORD_MAX_LEN * PE_42_LETTERS_LEN);

  uint16_t triangle_words = 0;
  bool in_name = false;
  uint64_t word_value = 0;
  char c;
  while(EOF != (c = fgetc(file))) {
    switch(c) {
      case '"':
        if(!in_name) {
          in_name = true;
          word_value = 0;
        } else {
          in_name = false;
          if(pe_42_is_triangle(&triangles, word_value)) {
            triangle_words++;
          }
        }
        break;
      case ',':
        break;
      default:
        word_value += (c - 'A' + 1);
        break;
    }
  }

  printf("Triangles: %i\n", triangle_words);

  return 0;
}
