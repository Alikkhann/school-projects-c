#include "test.h"

START_TEST(found_at_middle) {
  const char *str = "Hello, world!";
  int c = 'o';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(found_at_beginning) {
  const char *str = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(found_at_end) {
  const char *str = "Hello, world!";
  int c = '!';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(not_found) {
  const char *str = "Hello, world!";
  int c = 'x';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(empty_str) {
  const char *str = "";
  int c = 'H';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(end_of_str) {
  const char *str = "Hello, world!";
  int c = '\0';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("tc_strchr");

  tcase_add_test(tc, found_at_middle);
  tcase_add_test(tc, found_at_beginning);
  tcase_add_test(tc, found_at_end);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, end_of_str);

  suite_add_tcase(s, tc);

  return s;
}

int strchr_main() {
  int failed = 0;
  Suite *s = suite_strchr();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
