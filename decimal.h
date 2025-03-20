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
} decimal;


int getBit(decimal num, int index);
void setBit(decimal *num, int index, int value);

#endif 