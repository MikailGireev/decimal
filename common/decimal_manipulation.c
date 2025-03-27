#include "../decimal.h"

/**
 * @brief Временная функция для инициализации структуры
 * @param num Указатель на число децимал
 */
void initStruct(Decimal *num) {
  clearBits(num);
  num->type = NORMAL_VALUE;
}

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
 * @brief Копирование битов
 * @param src Указатель на исходное число децимал
 * @param dest Указатель на целевое число децимал
 */
void bitsCopy(Decimal *src, Decimal *dest) {
  dest->bits[0] = src->bits[0];
  dest->bits[1] = src->bits[1];
  dest->bits[2] = src->bits[2];
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
  initStruct(&tmp);

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
      Decimal remainder;
      Decimal ten = {{10,0,0,0}, NORMAL_VALUE};

      Decimal tmpDiv
    }
   }
}