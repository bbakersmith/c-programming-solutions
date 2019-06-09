#include "unity_fixture.h"

static void run_all_tests(void) {
  RUN_TEST_GROUP(pe_13);
  RUN_TEST_GROUP(pe_21);
  RUN_TEST_GROUP(pe_39);
  RUN_TEST_GROUP(pe_40);
  RUN_TEST_GROUP(pe_43);
  RUN_TEST_GROUP(permutations);
}

int main(int argc, const char * argv[]) {
  return UnityMain(argc, argv, run_all_tests);
}
