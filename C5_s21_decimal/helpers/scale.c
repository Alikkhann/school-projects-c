#include "../s21_decimal.h"

// Decimal
int get_scale(s21_decimal value) {
  int output = 0;
  for (int j = 16, i = 0; j < 24; j++, i++) {
    output += get_bit(value, 96 + j) * pow(2, i);
  }
  return output;
}

void set_scale(s21_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    int clearMask = ~(0xFF << 16);
    value->bits[3] &= clearMask;
    scale <<= 16;
    value->bits[3] |= scale;
  }
}

// Big Decimal
int get_big_scale(s21_big_decimal value) {
  int output = 0;
  for (int j = 16, i = 0; j < 24; j++, i++) {
    output += get_big_bit(value, 224 + j) * pow(2, i);
  }
  return output;
}

void set_big_scale(s21_big_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    int clearMask = ~(0xFF << 16);
    value->bits[7] &= clearMask;
    scale <<= 16;
    value->bits[7] |= scale;
  }
}