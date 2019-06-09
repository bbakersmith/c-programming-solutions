#include "unity.h"
#include "unity_fixture.h"

#include "43.c"

TEST_GROUP(pe_43);

TEST_SETUP(pe_43) {}

TEST_TEAR_DOWN(pe_43) {}

TEST(pe_43, test_pe_43_num_from_digits) {
  char d1[3] = {1, 2, 3};
  TEST_ASSERT_EQUAL(123, pe_43_num_from_digits(d1, 3));

  char d2[5] = {5, 4, 1, 2, 3};
  TEST_ASSERT_EQUAL(54123, pe_43_num_from_digits(d2, 5));

  char d3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(123456789, pe_43_num_from_digits(d3, 10));
}

TEST(pe_43, test_pe_43_is_special) {
  char p1d[16] = {1, 4, 0, 6, 3, 5, 7, 2, 8, 9};
  Permutations p1 = permutations_new(p1d, 10);
  TEST_ASSERT_TRUE(pe_43_is_special(&p1));

  char p2d[16] = {1, 4, 0, 6, 3, 5, 7, 2, 9, 8};
  Permutations p2 = permutations_new(p2d, 10);
  TEST_ASSERT_FALSE(pe_43_is_special(&p2));

  char p3d[16] = {1, 4, 0, 6, 3, 5, 7, 8, 2, 9};
  Permutations p3 = permutations_new(p3d, 10);
  TEST_ASSERT_FALSE(pe_43_is_special(&p3));
}

TEST_GROUP_RUNNER(pe_43) {
  RUN_TEST_CASE(pe_43, test_pe_43_num_from_digits);
  RUN_TEST_CASE(pe_43, test_pe_43_is_special);
}
