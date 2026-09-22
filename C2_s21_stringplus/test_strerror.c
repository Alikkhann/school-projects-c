#include "test.h"

START_TEST(basic) { ck_assert_str_eq(strerror(11), s21_strerror(11)); }
END_TEST

START_TEST(negative) { ck_assert_str_eq(strerror(-1), s21_strerror(-1)); }
END_TEST

START_TEST(overlap) { ck_assert_str_eq(strerror(999), s21_strerror(999)); }
END_TEST

START_TEST(zero_error) {
  int zero_error = 0;
  ck_assert_str_eq(strerror(zero_error), s21_strerror(zero_error));
}
END_TEST

Suite *suite_strerror() {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, negative);
  tcase_add_test(tc, overlap);
  tcase_add_test(tc, zero_error);

  suite_add_tcase(s, tc);

  return s;
}

int strerror_main() {
  int failed = 0;
  Suite *s = suite_strerror();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
