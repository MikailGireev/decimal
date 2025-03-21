#ifndef DECIMAL_H
#define DECIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef enum {
  NORMAL_VALUE = 0,
  _INFINITY = 1,
  NEGATIVE_INFINITY = 2,
  _NAN = 3,
  ADDCODE = 4,
} valueTypeT;

typedef struct 
{
  unsigned bits[4];
  valueTypeT type;
} Decimal;


int getBit(Decimal num, int index);
void setBit(Decimal *num, int index, int value);
void setSign(Decimal *num, int sign);
int getSign(const Decimal *num);
int getScale(const Decimal *num); 
void setScale(Decimal *num, int scale);
int lastBit(Decimal num);
void shiftLeft(Decimal *num, int shift);

#endif 