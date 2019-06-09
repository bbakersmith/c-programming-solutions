#include "unity.h"
#include "unity_fixture.h"

#include "13.c"

TEST_GROUP(pe_13);

TEST_SETUP(pe_13) {}

TEST_TEAR_DOWN(pe_13) {}

TEST(pe_13, test_pe_13_truncate_num) {
  TEST_ASSERT_EQUAL_UINT64(2233445566, pe_13_truncate_num(112233445566));
  TEST_ASSERT_EQUAL_UINT64(4567654321, pe_13_truncate_num(1234567654321));
  TEST_ASSERT_EQUAL_UINT64(3212345678, pe_13_truncate_num(876543212345678));
}

TEST_GROUP_RUNNER(pe_13) {
  RUN_TEST_CASE(pe_13, test_pe_13_truncate_num);
}
