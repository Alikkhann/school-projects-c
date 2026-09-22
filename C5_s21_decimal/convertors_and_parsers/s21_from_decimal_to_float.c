#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int sign = get_sign(src);
  int scale = get_scale(src);

  double tmp = 0;

  for (int i = 0; i < 32 * 3; i++) {
    if (get_bit(src, i)) {
      tmp += pow(2, i);
    }
  }

  while (scale > 0) {
    tmp /= 10;
    scale--;
  }

  if (sign) {
    tmp *= -1;
  }

  *dst = tmp;

  return 0;
}