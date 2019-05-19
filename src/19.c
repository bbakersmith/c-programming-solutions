/**
 * @file 19.c
 *
 * @brief Counting Sundays
 *
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 * - 1 Jan 1900 was a Monday.
 *
 * - Thirty days has September, April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 *
 * - A leap year occurs on any year evenly divisible by 4,
 *   but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth
 * century (1 Jan 1901 to 31 Dec 2000)?
 */

#include "stdint.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} DayOfWeek;

typedef enum {
  JANUARY,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
} MonthOfYear;

typedef struct CurrentDate {
  DayOfWeek day;
  MonthOfYear month;
  uint16_t year;
} CurrentDate;

uint8_t days_in_month_lookup[12] = {
  31, // jan
  28, // feb
  31, // mar
  30, // apr
  31, // may
  30, // jun
  31, // jul
  31, // aug
  30, // sep
  31, // oct
  30, // nov
  31  // dec
};

uint8_t get_days_in_month(CurrentDate *current_date) {
  MonthOfYear month = current_date->month;
  uint16_t year = current_date->year;
  uint8_t days = days_in_month_lookup[month];
  if(
    month == FEBRUARY
    && year % 4 == 0
    && (year % 100 != 0 || year % 400 == 0)
  ) {
    days++;
  }
  return days;
}

void advance_day(CurrentDate *current_date, uint8_t num) {
  for(uint8_t i = 0; i < num; i++) {
    if(current_date->day == SATURDAY) {
      current_date->day = SUNDAY;
    } else {
      current_date->day++;
    }
  }
}

void advance_month(CurrentDate *current_date) {
  uint8_t days_in_month = get_days_in_month(current_date) % 7;
  advance_day(current_date, days_in_month);

  if(current_date->month == DECEMBER) {
    current_date->month = JANUARY;
    current_date->year++;
  } else {
    current_date->month++;
  }
}

int main(int argc, char *argv[]) {
  uint16_t end_year = atoi(argv[1]);

  CurrentDate current_date = {
    .day = TUESDAY,
    .month = JANUARY,
    .year = 1901
  };

  uint16_t sunday_count = 0;
  while(current_date.year != end_year) {
    if(current_date.day == SUNDAY)
      sunday_count++;

    advance_month(&current_date);
  }

  printf("Sundays: %i\n", sunday_count);
  return 0;
}
