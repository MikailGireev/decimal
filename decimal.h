#ifndef DECIMAL_H
#define DECIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct 
{
  unsigned bits[4];
} Decimal;


int getBit(Decimal num, int index);
void setBit(Decimal *num, int index, int value);
void setSign(Decimal *num, int sign);

#endif 