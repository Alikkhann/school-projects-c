#include "../s21_decimal.h"

int compare(s21_decimal value_1, s21_decimal value_2) {
  int output = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  s21_big_decimal big_value_1 = convert_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = convert_to_big_decimal(value_2);

  normalize_scale(&big_value_1, &big_value_2);

  if (sign_1 != sign_2) {
    if (!sign_1 && sign_2) {
      output = 1;
    } else if (sign_1 && !sign_2) {
      output = -1;
    }
  } else {
    for (int i = 6; i >= 0; i--) {
      if ((big_value_1.bits[i] > big_value_2.bits[i] && !sign_1) ||
          (big_value_1.bits[i] < big_value_2.bits[i] && sign_1)) {
        output = 1;
        break;
      } else if ((big_value_1.bits[i] < big_value_2.bits[i] && !sign_2) ||
                 (big_value_1.bits[i] > big_value_2.bits[i] && sign_2)) {
        output = -1;
        break;
      }
    }
  }

  return output;
}