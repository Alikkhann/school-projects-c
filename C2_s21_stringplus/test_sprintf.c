#include "test.h"

START_TEST(d_basic) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "12%d3", 9);
  int check = sprintf(str2, "12%d3", 9);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_short) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "12%hd3", 9);
  int check = sprintf(str2, "12%hd3", 9);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_width) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "12%5d3", 9);
  int check = sprintf(str2, "12%5d3", 9);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_negative) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%d", -42);
  int check = sprintf(str2, "%d", -42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_plus_flag) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%+d", 42);
  int check = sprintf(str2, "%+d", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_precision) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%.5d", 42);
  int check = sprintf(str2, "%.5d", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_minus_flag) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%-5d", 42);
  int check = sprintf(str2, "%-5d", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(d_space_flag) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "% d", 42);
  int check = sprintf(str2, "% d", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(c_basic) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "12%c3", 'A');
  int check = sprintf(str2, "12%c3", 'A');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(c_minus_flag) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%-3c", 'A');
  int check = sprintf(str2, "%-3c", 'A');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(u_basic) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%u", 1234567890U);
  int check = sprintf(str2, "%u", 1234567890U);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(u_long_) {
  char str1[20];
  char str2[20];
  unsigned long num = 123456789012345UL;
  int s21_check = s21_sprintf(str1, "%lu", num);
  int check = sprintf(str2, "%lu", num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(u_precision) {
  char str1[20];
  char str2[20];
  unsigned int num = 123;
  int s21_check = s21_sprintf(str1, "%.5u", num);
  int check = sprintf(str2, "%.5u", num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_basic) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%f", 3.14);
  int check = sprintf(str2, "%f", 3.14);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_precision) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%.2f", 3.14159);
  int check = sprintf(str2, "%.2f", 3.14159);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_round) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%f", 3.9999996);
  int check = sprintf(str2, "%f", 3.9999996);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_plus_flag) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%+f", 3.14);
  int check = sprintf(str2, "%+f", 3.14);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_space_flag) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "% f", 3.14);
  int check = sprintf(str2, "% f", 3.14);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(f_minus_flag) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%-8.2f", 3.14);
  int check = sprintf(str2, "%-8.2f", 3.14);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(s_basic) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%s", "Hello");
  int check = sprintf(str2, "%s", "Hello");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(s_precision) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%.3s", "Hello");
  int check = sprintf(str2, "%.3s", "Hello");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(s_minus_flag) {
  char str1[20];
  char str2[20];
  int s21_check = s21_sprintf(str1, "%-10s", "Hello");
  int check = sprintf(str2, "%-10s", "Hello");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(s_wchar_precision) {
  char str1[50];
  char str2[50];
  wchar_t wstr[] = L"Hello, 世界";
  int s21_check =
      s21_sprintf(str1, "%.5ls", wstr);  // Truncate to first 5 wide characters
  int check = sprintf(str2, "%.5ls", wstr);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(percent_symbol) {
  char str1[10];
  char str2[10];
  int s21_check = s21_sprintf(str1, "%%");
  int check = sprintf(str2, "%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(check, s21_check);
}
END_TEST

Suite *suite_sprintf() {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("tc_sprintf");
  tcase_add_test(tc, d_basic);
  tcase_add_test(tc, d_short);
  tcase_add_test(tc, d_width);
  tcase_add_test(tc, d_negative);
  tcase_add_test(tc, d_plus_flag);
  tcase_add_test(tc, d_precision);
  tcase_add_test(tc, d_minus_flag);
  tcase_add_test(tc, d_space_flag);
  tcase_add_test(tc, c_basic);
  tcase_add_test(tc, c_minus_flag);
  tcase_add_test(tc, u_basic);
  tcase_add_test(tc, u_long_);
  tcase_add_test(tc, u_precision);
  tcase_add_test(tc, f_basic);
  tcase_add_test(tc, f_precision);
  tcase_add_test(tc, f_round);
  tcase_add_test(tc, f_plus_flag);
  tcase_add_test(tc, f_space_flag);
  tcase_add_test(tc, f_minus_flag);
  tcase_add_test(tc, s_basic);
  tcase_add_test(tc, s_precision);
  tcase_add_test(tc, s_minus_flag);
  tcase_add_test(tc, s_wchar_precision);
  tcase_add_test(tc, percent_symbol);
  suite_add_tcase(s, tc);

  return s;
}

int sprintf_main() {
  int failed = 0;
  Suite *s = suite_sprintf();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
