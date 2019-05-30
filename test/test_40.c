#include "unity.h"
#include "unity_fixture.h"

#include "40.c"

TEST_GROUP(pe_40);

TEST_SETUP(pe_40) {}

TEST_TEAR_DOWN(pe_40) {}

TEST(pe_40, test_pe_40_calculate_champernowne_constant) {
  TEST_ASSERT_EQUAL(1, pe_40_calculate_champernowne_constant(12));
  TEST_ASSERT_EQUAL(1, pe_40_calculate_champernowne_constant(13));
  TEST_ASSERT_EQUAL(1, pe_40_calculate_champernowne_constant(14));
  TEST_ASSERT_EQUAL(2, pe_40_calculate_champernowne_constant(15));
  TEST_ASSERT_EQUAL(1, pe_40_calculate_champernowne_constant(16));
  TEST_ASSERT_EQUAL(3, pe_40_calculate_champernowne_constant(17));
  TEST_ASSERT_EQUAL(1, pe_40_calculate_champernowne_constant(18));
  TEST_ASSERT_EQUAL(4, pe_40_calculate_champernowne_constant(19));
}

TEST_GROUP_RUNNER(pe_40) {
  RUN_TEST_CASE(pe_40, test_pe_40_calculate_champernowne_constant);
}
