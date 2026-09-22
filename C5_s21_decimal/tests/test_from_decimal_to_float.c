#include "test.h"

START_TEST(test_from_decimal_to_float_1) {
  s21_decimal inp = {{4, 0, 0, 0x00000000}};
  float out;
  float res = 4.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_2) {
  s21_decimal inp = {{432152, 320, 344, 65536}};
  float out;
  float res = 634567996273047572277.6;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_3) {
  s21_decimal inp = {{432152, 320, 133, 655360}};
  float out;
  float res = 2.453417E+11;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_4) {
  s21_decimal inp = {{3, 3, 3, INT_MIN}};
  float out;
  float res = -55340232234013556739.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *from_decimal_to_float_test_suite() {
  Suite *s = suite_create("from_decimal_to_float_test_suite");
  TCase *tc = tcase_create("from_decimal_to_float_test_tc");

  tcase_add_test(tc, test_from_decimal_to_float_1);
  tcase_add_test(tc, test_from_decimal_to_float_2);
  tcase_add_test(tc, test_from_decimal_to_float_3);
  tcase_add_test(tc, test_from_decimal_to_float_4);

  suite_add_tcase(s, tc);
  return s;
}

int test_from_decimal_to_float() {
  int failed = 0;

  Suite *s = from_decimal_to_float_test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed ? 1 : 0;
}