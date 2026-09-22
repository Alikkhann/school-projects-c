#include "test.h"

START_TEST(basic) {
  // Arrange
  char str1[] = "453";
  char str2[] = "12";
  // Act
  void *check = strncpy(str1, str2, 2);
  void *s21_check = s21_strncpy(str1, str2, 2);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(full_buffer) {
  // Arrange
  char str1[10];
  char str2[10];
  // Act
  memset(str1, 'B', 10);
  s21_memset(str2, 'B', 10);
  // Assert
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(overlap_copy) {
  // Arrange
  char str1[] = "Hello,World!";
  // Act
  void *check = strncpy(str1 + 6, str1, 5);
  void *s21_check = s21_strncpy(str1 + 6, str1, 5);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(small_range_n) {
  // Arrange
  char str1[] = "000";
  char str2[] = "111";
  // Act
  void *check = strncpy(str1, str2, 1);
  void *s21_check = s21_strncpy(str1, str2, 1);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

Suite *suite_strncpy() {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("tc_strncpy");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, full_buffer);
  tcase_add_test(tc, overlap_copy);
  tcase_add_test(tc, small_range_n);

  suite_add_tcase(s, tc);

  return s;
}

int strncpy_main() {
  int failed = 0;
  Suite *s = suite_strncpy();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
