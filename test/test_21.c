#include "unity.h"
#include "unity_fixture.h"

#include "21.c"

TEST_GROUP(pe_21);

TEST_SETUP(pe_21) {}

TEST_TEAR_DOWN(pe_21) {}

TEST(pe_21, test_pe_21_sum_of_divisors) {
  TEST_ASSERT_EQUAL(284, pe_21_sum_of_divisors(220));
  TEST_ASSERT_EQUAL(220, pe_21_sum_of_divisors(284));
}

TEST(pe_21, test_pe_21_sum_of_amicable_numbers) {
  TEST_ASSERT_EQUAL(31626, pe_21_sum_of_amicable_numbers(10000));
}

TEST_GROUP_RUNNER(pe_21) {
  RUN_TEST_CASE(pe_21, test_pe_21_sum_of_divisors);
  RUN_TEST_CASE(pe_21, test_pe_21_sum_of_amicable_numbers);
}
