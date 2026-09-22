#include "../s21_decimal.h"

// Decimal
int get_sign(s21_decimal value) { return get_bit(value, 127); }

void set_sign(s21_decimal *value, int sign) { set_bit(value, 127, sign); }

// Big Decimal
// int get_big_sign(s21_big_decimal value) { return get_big_bit(value, 254); }

// void set_big_sign(s21_big_decimal *value, int sign) {
//   set_big_bit(value, 254, sign);
// }