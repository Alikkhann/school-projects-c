#include "test.h"

START_TEST(found) {
  // Arrange
  const void *str = "1234567";
  int c = '7';
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(not_found) {
  // Arrange
  const void *str = "1234567";
  int c = '8';
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(at_beginning) {
  // Arrange
  const void *str = "1234567";
  int c = '1';
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(at_end) {
  // Arrange
  const void *str = "1234567";
  int c = '7';
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(c_null) {
  // Arrange
  const void *str = "1234567";
  int c = s21_NULL;
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(str_empty) {
  // Arrange
  const void *str = "";
  int c = 4;
  size_t n = 7;
  s21_size_t s21_n = 7;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(small_range_n) {
  // Arrange
  const void *str = "1234567";
  int c = 3;
  size_t n = 5;
  s21_size_t s21_n = 5;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

START_TEST(big_range_n) {
  // Arrange
  const void *str = "1234567";
  int c = 3;
  size_t n = 15;
  s21_size_t s21_n = 15;
  // Act
  void *check = memchr(str, c, n);
  void *s21_check = s21_memchr(str, c, s21_n);
  // Assert
  ck_assert_ptr_eq(check, s21_check);
}
END_TEST

Suite *suite_memchr() {
  Suite *s;
  s = suite_create("suite_memchr");

  TCase *tc = tcase_create("tc_memchr");

  tcase_add_test(tc, found);
  tcase_add_test(tc, not_found);
  tcase_add_test(tc, at_beginning);
  tcase_add_test(tc, at_end);
  tcase_add_test(tc, c_null);
  tcase_add_test(tc, str_empty);
  tcase_add_test(tc, small_range_n);
  tcase_add_test(tc, big_range_n);

  suite_add_tcase(s, tc);

  return s;
}

int memchr_main() {
  int failed = 0;
  Suite *s;
  SRunner *runner;
  s = suite_memchr();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
