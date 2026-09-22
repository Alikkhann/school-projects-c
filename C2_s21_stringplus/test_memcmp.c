#include "test.h"

START_TEST(negative_output) {
  // Arrange
  char *str1 = "abc";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 3);
  int s21_check = s21_memcmp(str1, str2, 3);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(positive_output) {
  // Arrange
  char *str1 = "XYZ";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 3);
  int s21_check = s21_memcmp(str1, str2, 3);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(equal_output) {
  // Arrange
  char *str1 = "ABC";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 3);
  int s21_check = s21_memcmp(str1, str2, 3);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(empty) {
  // Arrange
  char *str1 = "";
  char *str2 = "";
  // Act
  int check = memcmp(str1, str2, 3);
  int s21_check = s21_memcmp(str1, str2, 3);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(small_range_n) {
  // Arrange
  char *str1 = "ABC";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 1);
  int s21_check = s21_memcmp(str1, str2, 1);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(big_range_n) {
  // Arrange
  char *str1 = "ABC";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 10);
  int s21_check = s21_memcmp(str1, str2, 10);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(zero_n) {
  // Arrange
  char *str1 = "ABC";
  char *str2 = "ABC";
  // Act
  int check = memcmp(str1, str2, 0);
  int s21_check = s21_memcmp(str1, str2, 0);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

START_TEST(int_array) {
  // Arrange
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {6, 7, 8, 9, 0};
  // Act
  int check = memcmp(arr1, arr2, 3);
  int s21_check = s21_memcmp(arr1, arr2, 3);
  // Assert
  ck_assert_int_eq(check, s21_check);
}
END_TEST

Suite *suite_memcmp() {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("tc_memcmp");

  tcase_add_test(tc, negative_output);
  tcase_add_test(tc, positive_output);
  tcase_add_test(tc, equal_output);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, small_range_n);
  tcase_add_test(tc, big_range_n);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, int_array);

  suite_add_tcase(s, tc);
  return s;
}

int memcmp_main() {
  int failed = 0;
  Suite *s = suite_memcmp();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
