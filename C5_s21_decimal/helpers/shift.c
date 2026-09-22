#include "../s21_decimal.h"

// Big Decimal
void shift_left(s21_big_decimal *value, int shift_value) {
  unsigned int memory = 0;
  for (int i = 0; i < 7; i++) {
    unsigned int temp = value->bits[i];
    value->bits[i] <<= shift_value;
    value->bits[i] |= memory;
    memory = temp >> (32 - shift_value);
  }
}

// void shift_right(s21_big_decimal *value, int shift_value) {
//   unsigned int memory = 0;
//   for (int i = 6; i >= 0; i--) {
//     unsigned int temp = value->bits[i] << (32 - shift_value);
//     value->bits[i] >>= shift_value;
//     value->bits[i] |= memory;
//     memory = temp >> (32 - shift_value);
//   }
// }