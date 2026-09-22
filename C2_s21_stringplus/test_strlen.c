#include "test.h"

START_TEST(basic) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(str_empty) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(single_char) {
  char str[] = "A";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(spaces) {
  char str[] = "   ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(special_chars) {
  char str[] = "\n\t\r";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(long_str) {
  char str[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
      "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(end_of_str) {
  char str[] = "Hello\0world";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *s;
  s = suite_create("suite_strlen");

  TCase *tc = tcase_create("tc_strlen");
  tcase_add_test(tc, basic);
  tcase_add_test(tc, str_empty);
  tcase_add_test(tc, single_char);
  tcase_add_test(tc, spaces);
  tcase_add_test(tc, special_chars);
  tcase_add_test(tc, long_str);
  tcase_add_test(tc, end_of_str);
  suite_add_tcase(s, tc);
  return s;
}

int strlen_main() {
  int failed = 0;
  Suite *s;
  SRunner *runner;
  s = suite_strlen();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
