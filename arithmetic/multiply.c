#include "decimal.h"

Decimal decimal_multiply(const Decimal *num1, const Decimal *num2) {
  Decimal result;
  initStruct(&result);

  Decimal left = *num1;
  Decimal right = *num2;

  int scale_a = getScale(&left);
  int scale_b = getScale(&right);
  int total_scale = scale_a + scale_b;

  int sign = getSign(&left) ^ getSign(&right);

  setSign(&left, 0);
  setSign(&right, 0);

  Decimal temp_result;
  initStruct(&temp_result);

  for(int i = 0; i < 96; i++) {
    if (getBit(right, i)) {
      Decimal shifted = left;
      shiftLeft(&shifted, i);

      temp_result = bitAddition(&temp_result, &shifted);
    }
  }

  result = temp_result;

  setScale(&result, total_scale);
  setSign(&result, sign);

  return result;
}