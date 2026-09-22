#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  memset(result->bits, 0, sizeof(s21_decimal));

  s21_big_decimal big_value = convert_to_big_decimal(value);

  int scale = get_scale(value);

  while (scale > 0) {
    divide_by_ten(&big_value);
    scale--;
  }

  *result = convert_to_decimal(big_value);
  result->bits[3] = big_value.bits[7];

  set_scale(result, scale);

  return 0;
}