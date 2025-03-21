#include "../decimal.h"

/**
 * @brief Уставка знака
 * @param num указатель на число децимал
 * @param sign знак
 */
void setSign(Decimal *num, int sign) {
  unsigned int mask = 1u << 31;
  if(sign != 0) {
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
int getScale(const Decimal *num) {
  return (char)(num->bits[3] >> 16);
}

/**
 * @brief Установка степени
 * @param num указатель на число децимал
 * @param scale степень
 */
void setScale(Decimal *num, int scale) {
  if(scale < 0 || scale > 28) {
    printf("wrong scale = %d\n", scale);
  } else {
    int clearMask = ~(0xFF << 16);
    num->bits[3] &= clearMask; 
    int mask = scale << 16;
    num->bits[3] |= mask;
  }
}