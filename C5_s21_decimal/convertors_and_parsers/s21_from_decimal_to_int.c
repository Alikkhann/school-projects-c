#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int output = 0;
  int sign = get_sign(src);
  *dst = 0;

  s21_truncate(src, &src);

  if (src.bits[1] == 0 && src.bits[2] == 0 &&
      ((src.bits[0] <= INT_MAX && !sign) ||
       (src.bits[0] <= INT_MAX + 1u && sign))) {
    *dst = src.bits[0];

    if (sign) {
      *dst *= -1;
    }

  } else {
    output = 1;
  }

  return output;
}