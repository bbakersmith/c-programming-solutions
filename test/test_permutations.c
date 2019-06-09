#include "unity.h"
#include "unity_fixture.h"

#include "permutations.h"

TEST_GROUP(permutations);

TEST_SETUP(permutations) {}

TEST_TEAR_DOWN(permutations) {}

#define TEST_PERMUTATIONS_HEAPS_ALGORITHM_COUNT 5

TEST(permutations, test_permutations_heaps_algorithm) {
  char dummy_start[16] = {1, 3, 2};

  Permutations result = permutations_new(dummy_start, 3);

  char expectations[TEST_PERMUTATIONS_HEAPS_ALGORITHM_COUNT][3] = {
    {3, 1, 2},
    {2, 1, 3},
    {1, 2, 3},
    {3, 2, 1},
    {2, 3, 1}
  };

  TEST_ASSERT_EQUAL(dummy_start[0], result.current[0]);
  TEST_ASSERT_EQUAL(dummy_start[1], result.current[1]);
  TEST_ASSERT_EQUAL(dummy_start[2], result.current[2]);

  char message[64];
  for(uint8_t x = 0; x < TEST_PERMUTATIONS_HEAPS_ALGORITHM_COUNT; x++) {
    permutations_next(&result);
    for(uint8_t y = 0; y < 3; y++) {
      sprintf(message, "Failed iteration %i, value %i", x, y);
      TEST_ASSERT_EQUAL_MESSAGE(
        expectations[x][y],
        result.current[y],
        message
      );
    }

    sprintf(message, "Failed iteration %i", x);
    if(x < (TEST_PERMUTATIONS_HEAPS_ALGORITHM_COUNT - 1)) {
      TEST_ASSERT_FALSE_MESSAGE(result.last, message);
    } else {
      TEST_ASSERT_TRUE_MESSAGE(result.last, message);
    }
  }
}

TEST_GROUP_RUNNER(permutations) {
  RUN_TEST_CASE(permutations, test_permutations_heaps_algorithm);
}
