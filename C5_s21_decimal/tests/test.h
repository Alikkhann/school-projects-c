#ifndef TEST_H
#define TEST_H

/* -------------------------------------------------------------------------- */

#include <check.h>
#include <limits.h>

/* -------------------------------------------------------------------------- */

#include "../s21_decimal.h"

/* -------------------------------------------------------------------------- */

// Arithmetic Operators

int test_add();
int test_sub();
int test_mul();
// int test_div();

// Comparison Operators

int test_is_less();
int test_is_less_or_equal();
int test_is_greater();
int test_is_greater_or_equal();
int test_is_equal();
int test_is_not_equal();

// Convertors And Parsers

int test_from_decimal_to_float();
int test_from_decimal_to_int();
int test_from_int_to_decimal();
// int test_from_float_to_decimal();

// Other functions

int test_floor();
int test_round();
int test_truncate();
int test_negate();

#endif