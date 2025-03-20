#include "./decimal.h"

int main() {
  Decimal d = {0};

  setBit(&d, 5, 1);
  printf("Later: 1 => give: %d\n", getBit(d, 5));
  
  setBit(&d, 5, 1);
  printf("%d", getBit(d, 5));

  return 0;
}