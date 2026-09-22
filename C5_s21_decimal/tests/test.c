#include "test.h"

int main() {
  int failed = 0;

  // Arithmetic Operators

  failed += test_add();
  failed += test_sub();
  failed += test_mul();
  // failed += test_div();

  // Comparison Operators

  failed += test_is_less();
  failed += test_is_less_or_equal();
  failed += test_is_greater();
  failed += test_is_greater_or_equal();
  failed += test_is_equal();
  failed += test_is_not_equal();

  // Convertors And Parsers

  failed += test_from_decimal_to_float();
  failed += test_from_decimal_to_int();
  failed += test_from_int_to_decimal();
  // failed += test_from_float_to_decimal();

  // Other functions

  failed += test_floor();
  failed += test_round();
  failed += test_truncate();
  failed += test_negate();

  return failed ? 1 : 0;
}
