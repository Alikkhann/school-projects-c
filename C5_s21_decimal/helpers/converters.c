#include "../s21_decimal.h"

s21_decimal convert_to_decimal(s21_big_decimal value) {
  s21_decimal output = {0};

  for (int i = 0; i < 3; i++) {
    output.bits[i] = value.bits[i];
  }

  return output;
}

s21_big_decimal convert_to_big_decimal(s21_decimal value) {
  s21_big_decimal output = {0};

  for (int i = 0; i < 3; i++) {
    output.bits[i] = value.bits[i];
  }

  output.bits[7] = value.bits[3];

  return output;
}
