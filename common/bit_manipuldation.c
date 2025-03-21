#include "../decimal.h"

/**
 * @brief Получение бита
 * @param num Указатель на число децимал
 * @param index Положение бита
 * @return Возвращает 0 или 1
 */
int getBit(Decimal num, int index) {
  int res = 0;
  if (index / 32 < 4) {
    unsigned int mask = 1u << (index % 32);
    res = num.bits[index / 32] & mask;
  }
  return !!res;
}

/**
 * @brief Установка бита
 * @param index Положение бита
 * @param value Значение бита
 */
void setBit(Decimal *num, int index, int value) {
  unsigned int mask = 1u << (index % 32);
  if (index / 32 < 4 && value) {
    num->bits[index / 32] |= mask;
  } else if (index / 32 < 4 && !value) {
    num->bits[index / 32] &= ~mask;
  }
}
