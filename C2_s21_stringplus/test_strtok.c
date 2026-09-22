#include "test.h"

START_TEST(basic) {
  char input[] = "Hello,World!";
  char *delim = ",";
  char *token;

  char s21_input[] = "Hello,World!";
  char *s21_token;

  token = strtok(input, delim);
  s21_token = s21_strtok(s21_input, delim);
  ck_assert_str_eq(token, s21_token);

  token = strtok(NULL, delim);
  s21_token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, s21_token);

  token = strtok(NULL, delim);
  s21_token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, NULL);
  ck_assert_ptr_eq(s21_token, s21_NULL);
  ck_assert_ptr_eq(token, s21_token);
}
END_TEST

START_TEST(multiple_delims) {
  char input[] = "//He/ll;o,Wor!ld.";
  char *delim = "/;,!.";
  char *token;

  char s21_input[] = "//He/ll;o,Wor!ld.";
  char *s21_token;

  token = strtok(input, delim);
  s21_token = s21_strtok(s21_input, delim);
  ck_assert_str_eq(token, s21_token);

  while (token != NULL) {
    token = strtok(NULL, delim);
    s21_token = s21_strtok(s21_NULL, delim);
    if (s21_token != s21_NULL) {
      ck_assert_str_eq(token, s21_token);
    }
  }
}
END_TEST

START_TEST(leading_delims) {
  char str1[] = "   hello world";
  char str2[] = "   hello world";
  char delim[] = " ";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_str_eq(token, s21_token);

  while (token != NULL) {
    token = strtok(NULL, delim);
    s21_token = s21_strtok(s21_NULL, delim);
    if (s21_token != s21_NULL) {
      ck_assert_str_eq(token, s21_token);
    }
  }
}
END_TEST

START_TEST(trailing_delims) {
  char str1[] = "hello world   ";
  char str2[] = "hello world   ";
  char delim[] = " ";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_str_eq(token, s21_token);

  while (token != NULL) {
    token = strtok(NULL, delim);
    s21_token = s21_strtok(s21_NULL, delim);
    if (s21_token != s21_NULL) {
      ck_assert_str_eq(token, s21_token);
    }
  }
}
END_TEST

START_TEST(only_delims) {
  char str1[] = "     ";
  char str2[] = "     ";
  char delim[] = " ";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_ptr_eq(token, s21_token);
}
END_TEST

START_TEST(empty_str) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = " ";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_ptr_eq(token, s21_token);
}
END_TEST

START_TEST(single_char) {
  char str1[] = "a";
  char str2[] = "a";
  char delim[] = " ";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_str_eq(token, s21_token);
}
END_TEST

START_TEST(repeated) {
  char str1[] = "a,b,c,d,e,f";
  char str2[] = "a,b,c,d,e,f";
  char delim[] = ",";

  char *token = strtok(str1, delim);
  char *s21_token = s21_strtok(str2, delim);
  ck_assert_str_eq(token, s21_token);

  while (token != NULL) {
    token = strtok(NULL, delim);
    s21_token = s21_strtok(s21_NULL, delim);
    if (s21_token != s21_NULL) {
      ck_assert_str_eq(token, s21_token);
    }
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("tc_strtok");

  tcase_add_test(tc, basic);
  tcase_add_test(tc, multiple_delims);
  tcase_add_test(tc, leading_delims);
  tcase_add_test(tc, trailing_delims);
  tcase_add_test(tc, only_delims);
  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, single_char);
  tcase_add_test(tc, repeated);

  suite_add_tcase(s, tc);

  return s;
}

int strtok_main() {
  int failed = 0;
  Suite *s = suite_strtok();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
