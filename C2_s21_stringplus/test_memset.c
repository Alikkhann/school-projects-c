#include "test.h"

START_TEST(basic) {
  // Arrange
  char str[] = "abcdef";
  // Assert
  ck_assert_ptr_eq(memset(str, 'z', 3), s21_memset(str, 'z', 3));
}
END_TEST

START_TEST(full_buffer) {
  // Arrange
  char str1[10];
  char str2[10];
  int c = 'Z';
  // Act
  memset(str1, c, 10);
  s21_memset(str2, c, 10);
  // Assert
  ck_assert_mem_eq(str2, str1, 10);
}
END_TEST

START_TEST(large_buffer) {
  // Arrange
  char str1[1000];
  char str2[1000];
  int c = 'Z';
  s21_size_t n = 1000;
  // Act
  memset(str1, c, n);
  s21_memset(str2, c, n);
  // Assert
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(zero_n) {
  // Arrange
  char str[] = "XYZ";
  int c = 90;
  s21_size_t n = 0;
  // Assert
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(small_range_n) {
  // Arrange
  char str[] = "HJK";
  char c = 72;
  s21_size_t n = 1;
  // Assert
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

Suite *suite_memset() {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("tc_memset");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, full_buffer);
  tcase_add_test(tc, large_buffer);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, small_range_n);

  suite_add_tcase(s, tc);

  return s;
}

int memset_main() {
  int failed = 0;
  Suite *s = suite_memset();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
