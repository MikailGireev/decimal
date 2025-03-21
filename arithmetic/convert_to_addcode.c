#include "../decimal.h"

/**
 * @brief Функция переводит число децимал в доп.код
 * @param num указатель на число децимал
*/
void converToAddcode(Decimal *num) {
  Decimal res;
  Decimal add = {{1,0,0,0}, NORMAL_VALUE};

  num->bits[0] = ~num->bits[0];
  num->bits[1] = ~num->bits[1];
  num->bits[2] = ~num->bits[2];

  res = bitAddition(num, &add);

  num->bits[0] = res.bits[0];
  num->bits[1] = res.bits[1];
  num->bits[2] = res.bits[2];

  num->type = 4;
}