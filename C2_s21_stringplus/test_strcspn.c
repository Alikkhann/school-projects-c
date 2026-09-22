#include "test.h"

START_TEST(basic) {
  char str1[20] = "hello world";
  char str2[10] = "world";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(no_match) {
  char str1[20] = "abcdef";
  char str2[10] = "xyz";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(at_beginning) {
  char str1[20] = "abcdef";
  char str2[10] = "a";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(at_end) {
  char str1[20] = "abcdef";
  char str2[10] = "f";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(empty_str2) {
  char str1[20] = "abcdef";
  char str2[10] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(empty_str1) {
  char str1[20] = "";
  char str2[10] = "abcdef";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(both_empty) {
  char str1[20] = "";
  char str2[10] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(no_match_until_end) {
  char str1[20] = "abcdef";
  char str2[10] = "ghijk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(special_chars) {
  char str1[20] = "hello, world!";
  char str2[10] = ",!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn() {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("tc_strcspn");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, no_match);
  tcase_add_test(tc, at_beginning);
  tcase_add_test(tc, at_end);
  tcase_add_test(tc, empty_str2);
  tcase_add_test(tc, empty_str1);
  tcase_add_test(tc, both_empty);
  tcase_add_test(tc, no_match_until_end);
  tcase_add_test(tc, special_chars);

  suite_add_tcase(s, tc);

  return s;
}

int strcspn_main() {
  int failed = 0;
  Suite *s = suite_strcspn();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}