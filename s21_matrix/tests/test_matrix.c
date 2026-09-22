#include "test_matrix.h"

// s21_eq_matrix

START_TEST(first_testcase) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = SUCCESS;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(second_testcase) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 9;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(third_testcase) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(fourth_testcase) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123456789;
  A.matrix[0][1] = 2.123456789;
  A.matrix[0][2] = 3.123456789;
  A.matrix[1][0] = 4.123456789;
  A.matrix[1][1] = 5.123456789;
  A.matrix[1][2] = 6.123456789;
  A.matrix[2][0] = 7.123456789;
  A.matrix[2][1] = 8.123456789;
  A.matrix[2][2] = 9.123456789;

  B.matrix[0][0] = 1.123456798;
  B.matrix[0][1] = 2.123456798;
  B.matrix[0][2] = 3.123456798;
  B.matrix[1][0] = 4.123456798;
  B.matrix[1][1] = 5.123456798;
  B.matrix[1][2] = 6.123456798;
  B.matrix[2][0] = 7.123456798;
  B.matrix[2][1] = 8.123456798;
  B.matrix[2][2] = 9.123456798;

  int expected = SUCCESS;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(fifth_testcase) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123556789;
  A.matrix[0][1] = 2.123556789;
  A.matrix[0][2] = 3.123556789;
  A.matrix[1][0] = 4.123556789;
  A.matrix[1][1] = 5.123556789;
  A.matrix[1][2] = 6.123556789;
  A.matrix[2][0] = 7.123556789;
  A.matrix[2][1] = 8.123556789;
  A.matrix[2][2] = 9.123556789;

  B.matrix[0][0] = 1.123456798;
  B.matrix[0][1] = 2.123456798;
  B.matrix[0][2] = 3.123456798;
  B.matrix[1][0] = 4.123456798;
  B.matrix[1][1] = 5.123456798;
  B.matrix[1][2] = 6.123456798;
  B.matrix[2][0] = 7.123456798;
  B.matrix[2][1] = 8.123456798;
  B.matrix[2][2] = 9.123456798;

  int expected = FAILURE;
  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// s21_sum_matrix

START_TEST(sixth_testcase) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 0;
  expected_matrix.matrix[0][2] = 0;
  expected_matrix.matrix[1][0] = 0;
  expected_matrix.matrix[1][1] = 0;
  expected_matrix.matrix[1][2] = 0;
  expected_matrix.matrix[2][0] = 0;
  expected_matrix.matrix[2][1] = 0;
  expected_matrix.matrix[2][2] = 0;

  int expected = 2;
  int res = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(seventh_testcase) {
  matrix_t A;
  matrix_t B;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// s21_sub_matrix

START_TEST(eigth_testcase) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 0;
  expected_matrix.matrix[0][2] = 0;
  expected_matrix.matrix[1][0] = 0;
  expected_matrix.matrix[1][1] = 0;
  expected_matrix.matrix[1][2] = 0;
  expected_matrix.matrix[2][0] = 0;
  expected_matrix.matrix[2][1] = 0;
  expected_matrix.matrix[2][2] = 0;

  int expected = 0;
  int res = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(ninth_testcase) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 0;
  expected_matrix.matrix[0][2] = 0;
  expected_matrix.matrix[1][0] = 0;
  expected_matrix.matrix[1][1] = 0;
  expected_matrix.matrix[1][2] = 0;
  expected_matrix.matrix[2][0] = 0;
  expected_matrix.matrix[2][1] = 0;
  expected_matrix.matrix[2][2] = 0;

  int expected = 2;
  int res = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(tenth_testcase) {
  matrix_t A;
  matrix_t B;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_sub_matrix(&A, &B, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// s21_mult_number

START_TEST(eleventh_testcase) {
  matrix_t A;
  double number = 2.0;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 2;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 6;
  expected_matrix.matrix[1][0] = 8;
  expected_matrix.matrix[1][1] = 10;
  expected_matrix.matrix[1][2] = 12;
  expected_matrix.matrix[2][0] = 14;
  expected_matrix.matrix[2][1] = 16;
  expected_matrix.matrix[2][2] = 18;

  int expected = 0;
  int res = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(twelwth_testcase) {
  matrix_t A;
  double number = 2.0;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_mult_number(&A, number, NULL);
  ck_assert_int_eq(expected, res);
  s21_remove_matrix(&A);
}

// s21_mult_matrix

START_TEST(thirdteenth_testcase) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns - 1, &A);
  s21_create_matrix(rows - 1, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  expected_matrix.matrix[0][0] = 9;
  expected_matrix.matrix[0][1] = 11;
  expected_matrix.matrix[0][2] = 17;
  expected_matrix.matrix[1][0] = 12;
  expected_matrix.matrix[1][1] = 13;
  expected_matrix.matrix[1][2] = 22;
  expected_matrix.matrix[2][0] = 15;
  expected_matrix.matrix[2][1] = 15;
  expected_matrix.matrix[2][2] = 27;

  int expected = 0;
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

// s21_transpose

START_TEST(fourteenth_testcase) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[1][0] = 2;
  expected_matrix.matrix[1][1] = 5;
  expected_matrix.matrix[2][0] = 3;
  expected_matrix.matrix[2][1] = 6;

  int expected = 0;
  int res = s21_transpose(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(fifteenth_testcase) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 7;
  expected_matrix.matrix[1][0] = 2;
  expected_matrix.matrix[1][1] = 5;
  expected_matrix.matrix[1][2] = 8;
  expected_matrix.matrix[2][0] = 3;
  expected_matrix.matrix[2][1] = 6;
  expected_matrix.matrix[2][2] = 9;

  int expected = 0;
  int res = s21_transpose(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(sixteenth_testcase) {
  matrix_t A;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int expected = 1;
  int res = s21_transpose(&A, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
}

// s21_determinant

START_TEST(seventhteenth_testcase) {
  matrix_t A;
  double det;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int expected = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(expected, res);
  ck_assert_double_eq(0, det);
  s21_remove_matrix(&A);
}

// s21_calc_complements

START_TEST(eighteenth_testcase) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  expected_matrix.matrix[0][0] = 0;
  expected_matrix.matrix[0][1] = 10;
  expected_matrix.matrix[0][2] = -20;
  expected_matrix.matrix[1][0] = 4;
  expected_matrix.matrix[1][1] = -14;
  expected_matrix.matrix[1][2] = 8;
  expected_matrix.matrix[2][0] = -8;
  expected_matrix.matrix[2][1] = -2;
  expected_matrix.matrix[2][2] = 4;
  int expected = 0;
  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

// s21_inverse_matrix

START_TEST(ninteenth_testcase) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  expected_matrix.matrix[0][0] = 1;
  expected_matrix.matrix[0][1] = -1;
  expected_matrix.matrix[0][2] = 1;
  expected_matrix.matrix[1][0] = -38;
  expected_matrix.matrix[1][1] = 41;
  expected_matrix.matrix[1][2] = -34;
  expected_matrix.matrix[2][0] = 27;
  expected_matrix.matrix[2][1] = -29;
  expected_matrix.matrix[2][2] = 24;
  int expected = 0;
  int res = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(twenteeth_testcase) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_matrix;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &expected_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  expected_matrix.matrix[0][0] = 2;
  expected_matrix.matrix[0][1] = 4;
  expected_matrix.matrix[0][2] = 6;
  expected_matrix.matrix[1][0] = 8;
  expected_matrix.matrix[1][1] = 10;
  expected_matrix.matrix[1][2] = 12;
  expected_matrix.matrix[2][0] = 14;
  expected_matrix.matrix[2][1] = 16;
  expected_matrix.matrix[2][2] = 18;

  int expected = 0;
  int res = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(expected, res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(expected_matrix.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}

START_TEST(twenty_one_testcase) {
  matrix_t A;

  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int expected = 1;
  int res = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(expected, res);

  s21_remove_matrix(&A);
}

Suite *s21_matrix_suite_tests(void) {
  Suite *s = suite_create("s21_matrix_suite");
  TCase *tc = tcase_create("s21_matrix_tc");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  tcase_add_test(tc, seventh_testcase);
  tcase_add_test(tc, eigth_testcase);
  tcase_add_test(tc, ninth_testcase);
  tcase_add_test(tc, tenth_testcase);
  tcase_add_test(tc, eleventh_testcase);
  tcase_add_test(tc, twelwth_testcase);
  tcase_add_test(tc, thirdteenth_testcase);
  tcase_add_test(tc, fourteenth_testcase);
  tcase_add_test(tc, fifteenth_testcase);
  tcase_add_test(tc, sixteenth_testcase);
  tcase_add_test(tc, seventhteenth_testcase);
  tcase_add_test(tc, eighteenth_testcase);
  tcase_add_test(tc, ninteenth_testcase);
  tcase_add_test(tc, twenteeth_testcase);
  tcase_add_test(tc, twenty_one_testcase);

  suite_add_tcase(s, tc);
  return s;
}