#include "test.h"

START_TEST(test_is_greater_or_equal_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_is_greater_or_equal_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_is_greater_or_equal_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_is_greater_or_equal_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 0;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_is_greater_or_equal_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *is_greater_or_equal_test_suite() {
  Suite *s = suite_create("is_greater_or_equal_test_suite");
  TCase *tc = tcase_create("is_greater_or_equal_test_tc");

  tcase_add_test(tc, test_is_greater_or_equal_1);
  tcase_add_test(tc, test_is_greater_or_equal_2);
  tcase_add_test(tc, test_is_greater_or_equal_3);
  tcase_add_test(tc, test_is_greater_or_equal_4);
  tcase_add_test(tc, test_is_greater_or_equal_5);

  suite_add_tcase(s, tc);

  return s;
}

int test_is_greater_or_equal() {
  int failed = 0;

  Suite *s = is_greater_or_equal_test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed ? 1 : 0;
}