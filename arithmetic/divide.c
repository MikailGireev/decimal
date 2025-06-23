#include "decimal.h"

Decimal decimal_substact_internal(const Decimal* a, const Decimal* b) {
  Decimal result;
  Decimal negated_b = *b;
  decimal_negative(&negated_b);
  result = bitAddition((Decimal*)a, &negated_b);
  return result;
}

Decimal decimal_divide(const Decimal *num1, const Decimal *num2) {
  Decimal result;
  initStruct(&result);

  if (getBit(*num2, 0) == 0 && getBit(*num2, 1) == 0 && getBit(*num2, 2) == 0) {
    result.type = _NAN;
    return result;
  }

  Decimal left = *num1;
  Decimal right = *num2;
  setSign(&left, 0);
  setSign(&right, 0);

  int sign = getSign(&left) ^ getSign(&right);

  int scale_result = getScale(num1) - getScale(num2);

  for (int i = 0; i < 6; i++) {
    left = decimal_multiply(&left, &(Decimal){.bits = {10, 0, 0, 0}});
  }

  Decimal current = {0};
  Decimal one = from_int(1);

  for (int i = 95; i >= 0; i--) {
    shiftLeft(&current, 1);
    if (getBit(left, i)) setBit(&current, 0, 1);
    
    if (decimal_compare(&current, &right) >= 0) {
      current = decimal_substact_internal(&current, &right);
      setBit(&result, i, 1);
    }
  }

  setScale(&result, scale_result);
  setSign(&result, sign);

  return result;
}