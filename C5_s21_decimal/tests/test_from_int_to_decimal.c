#include "test.h"

START_TEST(test_from_int_to_decimal_1) {
  int inp = INT_MAX;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{2147483647, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  int inp = 1027557455;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1027557455, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  int inp = -1056545713;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{1056545713, 0x00000000, 0x00000000, 2147483648U}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  int inp = 99999;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{99999, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_5) {
  int inp = 0;
  s21_decimal out = {{0x00011B7E, 0x00014CC3, 0x0000BDF8, 0x00009B31}};
  int error = s21_from_int_to_decimal(inp, &out);
  s21_decimal res = {{0, 0x00000000, 0x00000000, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *from_int_to_decimal_test_suite() {
  Suite *s = suite_create("from_int_to_decimal_test_suite");
  TCase *tc = tcase_create("from_int_to_decimal_test_tc");

  tcase_add_test(tc, test_from_int_to_decimal_1);
  tcase_add_test(tc, test_from_int_to_decimal_2);
  tcase_add_test(tc, test_from_int_to_decimal_3);
  tcase_add_test(tc, test_from_int_to_decimal_4);
  tcase_add_test(tc, test_from_int_to_decimal_5);

  suite_add_tcase(s, tc);
  return s;
}

int test_from_int_to_decimal() {
  int failed = 0;

  Suite *s = from_int_to_decimal_test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed ? 1 : 0;
}