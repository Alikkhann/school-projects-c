#include "../s21_decimal.h"

// Big Decimal
void normalize_scale(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int scale_1 = get_big_scale(*value_1);
  int scale_2 = get_big_scale(*value_2);

  if (scale_1 > scale_2) {
    int difference = scale_1 - scale_2;
    while (difference) {
      multiply_by_ten(value_2);
      difference--;
      scale_2++;
    }

    set_big_scale(value_2, scale_2);
  } else if (scale_1 < scale_2) {
    normalize_scale(value_2, value_1);
  }
}

int check_if_greater_or_equal(s21_big_decimal value_1,
                              s21_big_decimal value_2) {
  int output = 0;
  int i = 6;

  while (i >= 0) {
    if (value_1.bits[i] < value_2.bits[i]) {
      output = 0;
      i = -1;
    } else if (value_1.bits[i] > value_2.bits[i]) {
      output = 1;
      i = -1;
    }
    i--;
  }

  return output;
}

void reduce_mantissa(s21_big_decimal *big_result, int *scale) {
  while ((*scale > 0 && is_overflow(*big_result)) || *scale > 28) {
    if (*scale == 1 || is_last_overflow(*big_result)) {
      bank_rounding(big_result);
    } else {
      divide_by_ten(big_result);
    }
    (*scale)--;
  }
}

void bank_rounding(s21_big_decimal *value) {
  s21_big_decimal tmp = *value;

  divide_by_ten(value);
  int is_odd = get_big_bit(*value, 0);
  multiply_by_ten(value);

  bit_subtraction(tmp, *value, &tmp);
  divide_by_ten(value);

  if (tmp.bits[0] > 5 || (tmp.bits[0] == 5 && is_odd)) {
    s21_big_decimal one = {0};
    one.bits[0] = 1;
    bit_addition(*value, one, value);
  }
}

int is_zero(unsigned int array[], int len) {
  int output = 1;

  for (int i = 0; i < len; i++) {
    if (array[i] != 0) {
      output = 0;
      break;
    }
  }

  return output;
}