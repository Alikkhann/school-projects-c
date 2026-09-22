#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int output = 0;

  memset(result->bits, 0, sizeof(s21_decimal));

  s21_big_decimal big_value_1 = convert_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = convert_to_big_decimal(value_2);
  s21_big_decimal big_result = {0};

  normalize_scale(&big_value_1, &big_value_2);

  int scale = get_big_scale(big_value_1);

  int sign = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  if (sign_1 != sign_2) {
    bit_addition(big_value_1, big_value_2, &big_result);
    sign = !sign_2;
  } else {
    if (check_if_greater_or_equal(big_value_1, big_value_2)) {
      bit_subtraction(big_value_1, big_value_2, &big_result);
      sign = sign_1;
    } else {
      bit_subtraction(big_value_2, big_value_1, &big_result);
      sign = !sign_2;
    }
  }

  if (is_overflow(big_result)) {
    reduce_mantissa(&big_result, &scale);

    if (is_overflow(big_result)) {
      output = sign ? 2 : 1;
    } else {
      *result = convert_to_decimal(big_result);
      set_sign(result, sign);
      set_scale(result, scale);
    }

  } else {
    *result = convert_to_decimal(big_result);
    set_sign(result, sign);
    set_scale(result, scale);
  }

  return output;
}
