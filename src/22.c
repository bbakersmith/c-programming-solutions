/**
 * @file 22b.c
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include "stdbool.h"
#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Name {
  uint8_t len;
  char raw[16];
} Name;

Name the_names[10000];

int compare_names(const void *name1_void, const void *name2_void) {
  Name *name1 = (Name *) name1_void;
  Name *name2 = (Name *) name2_void;

  for(uint8_t i = 0; i < name1->len; i++) {
    if(name1->raw[i] < name2->raw[i]) {
      return -1;
    } else if(name2->raw[i] < name1->raw[i]) {
      return 1;
    }
  }

  if(name1->len < name2->len) {
    return -1;
  } else {
    return 1;
  }
}

uint32_t name_score(Name *name, uint32_t position) {
  uint32_t score = 0;
  for(uint8_t i = 0; i < name->len; i++) {
    score += (name->raw[i] - 'A' + 1);
  }
  return score * position;
}

void print_name(Name *name) {
  for(uint8_t i = 0; i < name->len; i++) {
    printf("%c", name->raw[name->len]);
  }
}

int main() {
  FILE *file = fopen("data/22.txt", "r");

  uint16_t the_names_len = 0;
  bool in_name = false;

  char c;
  while(EOF != (c = fgetc(file))) {
    Name *name;
    switch(c) {
      case '"':
        if(!in_name) {
          in_name = true;
        } else {
          in_name = false;
          the_names_len++;
        }
        break;
      case ',':
        break;
      default:
        name = &the_names[the_names_len];
        name->raw[name->len] = c;
        name->len++;
        break;
    }
  }

  qsort(&the_names, the_names_len, sizeof(Name), compare_names);

  uint64_t total = 0;
  for(uint16_t i = 0; i <= the_names_len; i++) {
    Name *name = &the_names[i];
    /* printf("%s\n", name->raw); */
    total += name_score(name, i + 1);
  }

  fclose(file);

  printf("938th Name: %s\n", the_names[937].raw);
  printf("938th Score: %i\n", name_score(&the_names[937], 938));
  printf("Len: %i\n", the_names_len);
  printf("Total: %llu\n", total);

  return 0;
}


