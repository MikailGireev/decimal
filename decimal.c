#include "./decimal.h"

int getBit(Decimal num, int index) {
  int res = 0;
  if(index / 32 < 4) {
    unsigned int mask = 1u << (index % 32);
    res = num.bits[index / 32] & mask;
  }
  return !!res;
}

void setBit(Decimal *num, int index, int value){
  unsigned int mask = 1u << (index % 32);
  if(index / 32 < 4 && value) {
    num->bits[index / 32] |= mask;
  } else if(index / 32 < 4 && !value) {
    num->bits[index / 32] &= ~mask;
  }
}

void setSign(Decimal *num, int sign) {
  unsigned int mask = 1u << 31;
  if(sign != 0) {
    num->bits[3] |= mask;
  } else {
    num->bits[3] &= ~mask;
  }
}