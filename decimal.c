#include "./decimal.h"

int getBit(decimal num, int index) {
  int res = 0;
  if(index / 32 < 4) {
    unsigned int mask = 1u << (index % 32);
    res = num.bits[index / 32] & mask;
  }
  return !!res;
}