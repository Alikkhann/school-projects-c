#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  s21_decimal five = {{5, 0, 0, 0}};
  set_scale(&five, 1);
  s21_truncate(value, result);
  if (!s21_is_equal(value, *result)) {
    if (get_sign(value)) {
      s21_sub(value, five, &value);
    } else {
      s21_add(value, five, &value);
    }
    s21_truncate(value, result);
  }
  return 0;
}