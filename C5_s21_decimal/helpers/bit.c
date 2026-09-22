#include "../s21_decimal.h"

// Decimal
int get_bit(s21_decimal value, int position) {
  int output = 0;
  int cell = position / 32;
  if (cell < 4) {
    int one = 1 << (position % 32);
    output = value.bits[cell] & one;
  }
  return output ? 1 : 0;
}

void set_bit(s21_decimal *value, int position, int bit) {
  int cell = position / 32;
  int one = 1 << (position % 32);
  if (cell < 4) {
    if (bit) {
      value->bits[cell] |= one;
    } else {
      value->bits[cell] &= ~one;
    }
  }
}

// Big Decimal
int get_big_bit(s21_big_decimal value, int position) {
  int output = 0;
  int cell = position / 32;
  if (cell < 8) {
    int one = 1 << (position % 32);
    output = value.bits[cell] & one;
  }
  return output ? 1 : 0;
}

void set_big_bit(s21_big_decimal *value, int position, int bit) {
  int cell = position / 32;
  int one = 1 << (position % 32);
  if (cell < 8) {
    if (bit) {
      value->bits[cell] |= one;
    } else {
      value->bits[cell] &= ~one;
    }
  }
}