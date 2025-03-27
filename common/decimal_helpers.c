#include "../decimal.h"

/**
 * @brief Проверка на ноль
 * @param num1 Первое число децимал
 * @param num2 Второе число децимал
 */
int zeroCheck(Decimal num1, Decimal num2) {
  int is_zero = FALSE;
  
  Decimal *ptr1 = &num1;
  Decimal *ptr2 = &num2; 

  if(ptr1 && ptr2) {
    if(!num1.bits[0] && !num2.bits[0] && !num1.bits[1] && !num2.bits[1] && !num1.bits[2] && !num2.bits[2]) {
      is_zero = TRUE;
    }
  }
  return is_zero;
}

/**
 * @brief Проверка на положительную бесконечность
 * @param dec1 Первое число децимал
 * @param dec2 Второе число децимал
 * @return 0 - не бесконечны, 1 - первое бесконечное, 2 - оба бесконечны, -1 -
 * второе бесконечное
 */
int is_inf(Decimal *dec1, Decimal *dec2) {
  int whoIsInf = 0;
  int type_dec1 = dec1->type;
  int type_dec2 = dec2->type;

  if (type_dec1 == _INFINITY && type_dec2 != INFINITY) {
    whoIsInf = 1;
  } else if (type_dec1 != _INFINITY && type_dec2 == INFINITY) {
    whoIsInf = -1;
  } else if (type_dec1 == _INFINITY && type_dec2 == INFINITY) {
    whoIsInf = 2;
  }

  return whoIsInf;
}
