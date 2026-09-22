#include "test.h"

START_TEST(basic) {
  char str[] = "hello, world!";
  int ch = 'o';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(not_found) {
  char str[] = "hello, world!";
  int ch = 'z';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(at_beginning) {
  char str[] = "hello, world!";
  int ch = 'h';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(at_end) {
  char str[] = "hello, world!";
  int ch = '!';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(end_of_str) {
  char str[] = "hello, world!";
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(str_empty) {
  char str[] = "";
  int ch = 'a';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(multiple_occurrences) {
  char str[] = "banana";
  int ch = 'a';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *suite_strrchr() {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("tc_strrchr");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, at_beginning);
  tcase_add_test(tc, at_end);
  tcase_add_test(tc, end_of_str);
  tcase_add_test(tc, str_empty);
  tcase_add_test(tc, multiple_occurrences);

  suite_add_tcase(s, tc);

  return s;
}

int strrchr_main() {
  int failed = 0;
  Suite *s = suite_strrchr();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
