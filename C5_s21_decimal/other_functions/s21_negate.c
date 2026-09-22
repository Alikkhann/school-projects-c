#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  memset(result->bits, 0, sizeof(s21_decimal));
  *result = value;
  set_sign(result, !get_sign(*result));
  return 0;
}