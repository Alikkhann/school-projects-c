#include "test.h"

START_TEST(basic) {
  char haystack[] = "hello, world!";
  char needle[] = "world";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(not_found) {
  char haystack[] = "hello, world!";
  char needle[] = "planet";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "hello, world!";
  char needle[] = "";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "hello";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(both_empty) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(needle_at_beginning) {
  char haystack[] = "hello, world!";
  char needle[] = "hello";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(needle_at_end) {
  char haystack[] = "hello, world!";
  char needle[] = "world!";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(needle_in_middle) {
  char haystack[] = "hello, world!";
  char needle[] = "lo, wo";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(repeated_chars) {
  char haystack[] = "aaaabaaa";
  char needle[] = "aab";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr() {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("tc_strstr");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, empty_needle);
  tcase_add_test(tc, empty_haystack);
  tcase_add_test(tc, both_empty);
  tcase_add_test(tc, needle_at_beginning);
  tcase_add_test(tc, needle_at_end);
  tcase_add_test(tc, needle_in_middle);
  tcase_add_test(tc, repeated_chars);
  suite_add_tcase(s, tc);

  return s;
}

int strstr_main() {
  int failed = 0;
  Suite *s = suite_strstr();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
