#include "../s21_decimal.h"

// Big Decimal
void bit_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result) {
  unsigned int memory = 0;
  for (int i = 0; i < 32 * 7; i++) {
    unsigned int result_bit =
        get_big_bit(value_1, i) + get_big_bit(value_2, i) + memory;

    memory = result_bit / 2;
    result_bit %= 2;

    set_big_bit(result, i, result_bit);
  }
}

void bit_subtraction(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  unsigned int memory = 0;
  for (int i = 0; i < 32 * 7; i++) {
    unsigned int bit_1 = get_big_bit(value_1, i);
    unsigned int bit_2 = get_big_bit(value_2, i);
    unsigned int result_bit = 0;

    if (bit_1 && bit_2) {
      if (memory) {
        memory = 1;
        result_bit = 1;
      } else {
        result_bit = 0;
      }
    } else if (!bit_1 && !bit_2) {
      if (memory) {
        memory = 1;
        result_bit = 1;
      } else {
        result_bit = 0;
      }
    } else if (bit_1 && !bit_2) {
      if (memory) {
        memory = 0;
        result_bit = 0;
      } else {
        result_bit = 1;
      }
    } else if (!bit_1 && bit_2) {
      if (memory) {
        memory = 1;
        result_bit = 0;
      } else {
        memory = 1;
        result_bit = 1;
      }
    }

    set_big_bit(result, i, result_bit);
  }
}