#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int output = 0;

  memset(result->bits, 0, sizeof(s21_decimal));

  if (!is_zero(value_1.bits, 3) && !is_zero(value_2.bits, 3)) {
    int scale = get_scale(value_1) + get_scale(value_2);
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int sign = sign_1 ^ sign_2;

    s21_big_decimal big_value_1 = convert_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = convert_to_big_decimal(value_2);
    s21_big_decimal big_result = {0};

    for (int i = 0; i < 7 * 32; i++) {
      int bit = get_big_bit(big_value_2, i);

      if (bit) {
        bit_addition(big_value_1, big_result, &big_result);
      }

      shift_left(&big_value_1, 1);
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
  }

  return output;
}