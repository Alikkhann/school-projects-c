#include "test.h"

START_TEST(basic) {
  char dest[20] = "Hello";
  const char *src = " World";
  char s21_dest[20] = "Hello";
  const char *s21_src = " World";
  ck_assert_str_eq(strncat(dest, src, 6), s21_strncat(s21_dest, s21_src, 6));
}
END_TEST

START_TEST(empty_src) {
  char dest[10] = "Hello";
  const char *src = "";
  char s21_dest[10] = "Hello";
  const char *s21_src = "";
  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(s21_dest, s21_src, 5));
}
END_TEST

START_TEST(empty_dest) {
  char dest[10] = "";
  const char *src = "Hello";
  char s21_dest[10] = "";
  const char *s21_src = "Hello";
  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(s21_dest, s21_src, 5));
}
END_TEST

START_TEST(small_range_n) {
  char dest[10] = "Hello";
  const char *src = " World";
  char s21_dest[10] = "Hello";
  const char *s21_src = " World";
  ck_assert_str_eq(strncat(dest, src, 3), s21_strncat(s21_dest, s21_src, 3));
}
END_TEST

START_TEST(zero_n) {
  char dest[10] = "Hello";
  const char *src = "World";
  char s21_dest[10] = "Hello";
  const char *s21_src = "World";
  ck_assert_str_eq(strncat(dest, src, 0), s21_strncat(s21_dest, s21_src, 0));
}
END_TEST

Suite *suite_strncat() {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("tc_strncat");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, empty_dest);
  tcase_add_test(tc, small_range_n);
  tcase_add_test(tc, zero_n);

  suite_add_tcase(s, tc);

  return s;
}

int strncat_main() {
  int failed = 0;
  Suite *s = suite_strncat();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
