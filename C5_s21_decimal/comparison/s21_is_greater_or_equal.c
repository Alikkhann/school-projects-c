#include "../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int output = 0;
  int result = compare(value_1, value_2);
  if (result == 1 || result == 0) {
    output = 1;
  }
  return output;
}

