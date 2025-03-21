#include "../decimal.h"

/**
 * @brief Возвращает номер последнего установленного бита
 * @param num указатель на число децимал
 */
int lastBit(Decimal num) {
  int lastBit = 95;
  for(;lastBit >= 0 && getBit(num, lastBit) == 0;lastBit--);
  return lastBit;
}

/**
 * @brief Побитовый сдвиг влево
 * @param num Указатель на число децимал
 * @param shift Количество двигов влево
 */
void shiftLeft(Decimal *num, int shift) {
  int last_bit = lastBit(*num);
  if(last_bit + shift > 95) {
    num->type = _INFINITY;
    return;
  }
  for(int i = 0; i < shift; i++) {
    int value_31bit = getBit(*num, 31);
    int value_63bit = getBit(*num, 63);

    num->bits[0] <<= 1;
    num->bits[1] <<= 1;
    num->bits[2] <<= 1;

    if(value_31bit) setBit(num, 32, 1);
    if(value_63bit) setBit(num, 64, 1);
  }
}