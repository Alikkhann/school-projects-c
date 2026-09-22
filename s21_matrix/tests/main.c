#include "test_matrix.h"

int main(void) {
  int number_failed;

  Suite *s1;
  SRunner *sr;

  s1 = s21_matrix_suite_tests();

  sr = srunner_create(s1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}