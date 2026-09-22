#include "../s21_decimal.h"

// Big Decimal
void multiply_by_ten(s21_big_decimal *value) {
  s21_big_decimal value_1 = *value;
  s21_big_decimal value_2 = *value;
  shift_left(&value_1, 3);
  shift_left(&value_2, 1);
  bit_addition(value_1, value_2, value);
}

void divide_by_ten(s21_big_decimal *value) {
  unsigned long long carry = 0;
  for (int i = 6; i >= 0; i--) {
    unsigned long long temp = (carry << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    carry = temp % 10;
  }
}