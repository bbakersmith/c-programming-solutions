#include "unity.h"
#include "unity_fixture.h"

#include "39.c"

TEST_GROUP(pe_39);

TEST_SETUP(pe_39) {}

TEST_TEAR_DOWN(pe_39) {}

TEST(pe_39, test_pe_39_right_triangle_a) {
  TEST_ASSERT_EQUAL_FLOAT(48.0, pe_39_right_triangle_a(120, 20));
  TEST_ASSERT_EQUAL_FLOAT(45.0, pe_39_right_triangle_a(120, 24));
  TEST_ASSERT_EQUAL_FLOAT(40.0, pe_39_right_triangle_a(120, 30));
  TEST_ASSERT((double) 47.0 != (double) pe_39_right_triangle_a(120, 21));
}

TEST(pe_39, test_pe_39_right_triangle) {
  TEST_ASSERT_TRUE(pe_39_right_triangle(120, 20));
  TEST_ASSERT_TRUE(pe_39_right_triangle(120, 24));
  TEST_ASSERT_TRUE(pe_39_right_triangle(120, 30));
  TEST_ASSERT_FALSE(pe_39_right_triangle(120, 21));
}

TEST(pe_39, test_pe_39_count_right_triangles) {
  TEST_ASSERT_EQUAL(3, pe_39_count_right_triangles(120));
}

TEST_GROUP_RUNNER(pe_39) {
  RUN_TEST_CASE(pe_39, test_pe_39_right_triangle_a);
  RUN_TEST_CASE(pe_39, test_pe_39_right_triangle);
  RUN_TEST_CASE(pe_39, test_pe_39_count_right_triangles);
}
