#include "test.h"

START_TEST(basic) {
  char str1[] = "hello";
  char str2[] = "world";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(no_match) {
  char str1[] = "abcdef";
  char str2[] = "xyz";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(at_beginning) {
  char str1[] = "abcdef";
  char str2[] = "a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(at_end) {
  char str1[] = "abcdef";
  char str2[] = "f";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(str2_empty) {
  char str1[] = "abcdef";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(str1_empty) {
  char str1[] = "";
  char str2[] = "abcdef";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(both_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(special_chars) {
  char str1[] = "hello, world!";
  char str2[] = ",!";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(end_of_str) {
  char str1[] = "hello\0world";
  char str2[] = "w";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, no_match);
  tcase_add_test(tc, at_beginning);
  tcase_add_test(tc, at_end);
  tcase_add_test(tc, str2_empty);
  tcase_add_test(tc, str1_empty);
  tcase_add_test(tc, both_empty);
  tcase_add_test(tc, special_chars);
  tcase_add_test(tc, end_of_str);

  suite_add_tcase(s, tc);

  return s;
}

int strpbrk_main() {
  int failed = 0;
  Suite *s = suite_strpbrk();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
