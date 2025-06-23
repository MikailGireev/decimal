#ifndef DECIMAL_H
#define DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef enum {
  NORMAL_VALUE = 0,
  _INFINITY = 1,
  NEGATIVE_INFINITY = 2,
  _NAN = 3,
  ADDCODE = 4,
} valueTypeT;

typedef struct {
  unsigned bits[4];
  valueTypeT type;
} Decimal;

void initStruct(Decimal *num);
int getBit(Decimal num, int index);
void bitsCopy(Decimal *src, Decimal *dest);
void setBit(Decimal *num, int index, int value);
void clearBits(Decimal *num);
void setSign(Decimal *num, int sign);
int getSign(const Decimal *num);
int getScale(const Decimal *num);
void setScale(Decimal *num, int scale);
int lastBit(Decimal num);
int zeroCheck(Decimal num1, Decimal num2);
void shiftLeft(Decimal *num, int shift);
void converToAddcode(Decimal *num);
int scaleEqualize(Decimal *num1, Decimal *num2);
void decimal_negative(Decimal *d);
void decimal_substact(Decimal *result, const Decimal *num1, const Decimal *num2);
int decimal_compare(const Decimal *num1, const Decimal *num2);
Decimal decimal_multiply(const Decimal *num1, const Decimal *num2);
Decimal decimal_divide(const Decimal *num1, const Decimal *num2);
Decimal decimal_substact_internal(const Decimal* a, const Decimal* b);

Decimal from_int(int num);

Decimal bitAddition(Decimal *var1, Decimal *var2);

#endif