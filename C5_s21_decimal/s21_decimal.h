#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

/* -------------------------------------------------------------------------- */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------- */

// Decimal
typedef struct {
  unsigned bits[4];
} s21_decimal;

// Big Decimal
typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

/* -------------------------------------------------------------------------- */

// Arithmetic Operators

// Add
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Subtraction
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Multiplication
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Division
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/* -------------------------------------------------------------------------- */

// Comparison Operators

// Compare
int compare(s21_decimal value_1, s21_decimal value_2);

// Is Less
int s21_is_less(s21_decimal value_1, s21_decimal value_2);

// Is Less Or Equal
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

// Is Greater
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);

// Is Greater Or Equal
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

// Is Equal
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);

// Is Not Equal
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

/* -------------------------------------------------------------------------- */

// Convertors And Parsers

// From Decimal To Float
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// From Decimal To Int
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// From Int To Decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst);

// From Float To Decimal
// int s21_from_float_to_decimal(float src, s21_decimal *dst);

/* -------------------------------------------------------------------------- */

// Other functions

// Floor
int s21_floor(s21_decimal value, s21_decimal *result);

// Round
int s21_round(s21_decimal value, s21_decimal *result);

// Truncate
int s21_truncate(s21_decimal value, s21_decimal *result);

// Negate
int s21_negate(s21_decimal value, s21_decimal *result);

/* -------------------------------------------------------------------------- */

// Bit
int get_bit(s21_decimal value, int position);
void set_bit(s21_decimal *value, int position, int bit);

int get_big_bit(s21_big_decimal value, int position);
void set_big_bit(s21_big_decimal *value, int position, int bit);

// Sign
int get_sign(s21_decimal value);
void set_sign(s21_decimal *value, int sign);

// int get_big_sign(s21_big_decimal value);
// void set_big_sign(s21_big_decimal *value, int sign);

// Scale
int get_scale(s21_decimal value);
void set_scale(s21_decimal *value, int scale);

int get_big_scale(s21_big_decimal value);
void set_big_scale(s21_big_decimal *value, int scale);

// Shift
void shift_left(s21_big_decimal *value, int shift_value);
// void shift_right(s21_big_decimal *value, int shift_value);

// By Ten
void multiply_by_ten(s21_big_decimal *value);
void divide_by_ten(s21_big_decimal *value);

// Bit Operations
void bit_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result);
void bit_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);

// Big Converters
s21_decimal convert_to_decimal(s21_big_decimal value);
s21_big_decimal convert_to_big_decimal(s21_decimal value);

// Overflow
int is_overflow(s21_big_decimal big_result);
int is_last_overflow(s21_big_decimal value);

// Additional Functions
void normalize_scale(s21_big_decimal *value_1, s21_big_decimal *value_2);
int check_if_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
void reduce_mantissa(s21_big_decimal *big_result, int *scale);
void bank_rounding(s21_big_decimal *value);
int is_zero(unsigned int array[], int len);

#endif