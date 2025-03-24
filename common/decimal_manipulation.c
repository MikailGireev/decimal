#include "../decimal.h"

/**
 * @brief Уставка знака
 * @param num указатель на число децимал
 * @param sign знак
 */
void setSign(Decimal *num, int sign) {
  unsigned int mask = 1u << 31;
  if (sign != 0) {
    num->bits[3] |= mask;
  } else {
    num->bits[3] &= ~mask;
  }
}

/**
 * @brief Получение знака
 * @param num указатель на число децимал
 */
int getSign(const Decimal *num) {
  unsigned int mask = 1u << 31;
  return !!(num->bits[3] & mask);
}

/**
 * @brief Получение степени числа децимал
 * @param num указатель на число децимал
 */
int getScale(const Decimal *num) { return (char)(num->bits[3] >> 16); }

/**
 * @brief Установка степени
 * @param num указатель на число децимал
 * @param scale степень
 */
void setScale(Decimal *num, int scale) {
  if (scale < 0 || scale > 28) {
    printf("wrong scale = %d\n", scale);
  } else {
    int clearMask = ~(0xFF << 16);
    num->bits[3] &= clearMask;
    int mask = scale << 16;
    num->bits[3] |= mask;
  }
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

/**
 * @brief Копирование битов
 * @param src Указатель на исходное число децимал
 * @param dest Указатель на целевое число децимал
 */
void bitsCopy(Decimal *src, Decimal *dest) {
  dest->bits[0] = src->bits[0];
  dest->bits[1] = src->bits[1];
  dest->bits[2] = src->bits[2];
}

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

int scaleEqualize(Decimal *num1, Decimal *num2) {
  Decimal *bigger = NULL;
  Decimal *smaller = NULL;
  
  if(getScale(num1) == getScale(num2)) {
    return 0;
  } else if(getScale(num1) > getScale(num2)) {
    bigger = num1;
    smaller = num2;
  } else {
    bigger = num2;
    smaller = num1;
  }

  Decimal tmp;
  clearBits(&tmp);

  int scaleSmall;
  int scaleBig;

  while(getScale(num1) != getScale(num2)) {
    if(tmp.type == NORMAL_VALUE) {
      scaleSmall = getScale(smaller);

      Decimal tmp1;
      Decimal tmp2;

      tmp1 = *smaller;
      tmp2 = *smaller;
      shiftLeft(&tmp1, 1);
      shiftLeft(&tmp2, 3);
      tmp = bitAddition(&tmp1, &tmp2);

      if(tmp.type == NORMAL_VALUE) {
        bitsCopy(&tmp, smaller);
        setScale(smaller, scaleSmall + 1);
      }
    } else {
      
    }
   }
}