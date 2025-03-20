#include "../decimal.h"

void setSign(Decimal *num, int sign) {
  unsigned int mask = 1u << 31;
  if(sign != 0) {
    num->bits[3] |= mask;
  } else {
    num->bits[3] &= ~mask;
  }
}

int getSign(const Decimal *num) {
  unsigned int mask = 1u << 31;
  return !!(num->bits[3] & mask);
}

int getScale(const Decimal *num) {
  return (char)(num->bits[3] >> 16);
}