#include "../s21_decimal.h"

// Big Decimal
int is_overflow(s21_big_decimal big_result) {
  int output = 0;

  for (int i = 96; i < 224; i++) {
    if (get_big_bit(big_result, i)) {
      output = 1;
      break;
    }
  }

  return output;
}

int is_last_overflow(s21_big_decimal value) {
  int output = 0;

  if (value.bits[4] == 0 && value.bits[5] == 0 && value.bits[6] == 0 &&
      value.bits[3] < 10) {
    output = 1;
  }

  return output;
}