#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(dst->bits, 0, sizeof(s21_decimal));

  if (src < 0) {
    src *= -1;
    set_sign(dst, 1);
  }

  dst->bits[0] = src;

  return 0;
}