#include "../decimal.h"

int getBit(Decimal num, int index) {
  int res = 0;
  if(index / 32 < 4) {
    unsigned int mask = 1u << (index % 32);
    res = num.bits[index / 32] & mask; //16 = 1; 0 = 0
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
