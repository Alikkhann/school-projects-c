#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  s21_truncate(value, result);
  if (get_sign(value) && !s21_is_equal(*result, value)) {
    s21_decimal one = {0};
    one.bits[0] = 1;
    s21_sub(*result, one, result);
  }

  return 0;
}