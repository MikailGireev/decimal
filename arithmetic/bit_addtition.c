#include "../decimal.h"

/**
 * @brief Складывает биты, не трогай scale
 * @param var1 Первое слагаемое
 * @param var2 Второе слагаемое
 * @return decimal результат сложения
 */
Decimal bitAddition(Decimal *var1, Decimal *var2) {
  Decimal res = {{0, 0, 0, 0}, NORMAL_VALUE};
  int buffer = 0;

  for (int i = 0; i < 96; i++) {
    int cur_bit_var1 = getBit(*var1, i);
    int cur_bit_var2 = getBit(*var2, i);

    if (!cur_bit_var1 && !cur_bit_var2) { // Выключены оба бита
      if (buffer) {
        setBit(&res, i, 1);
        buffer = 0;
      } else {
        setBit(&res, i, 0);
      }
    } else if (cur_bit_var1 != cur_bit_var2) { // Один бит включен
      if (buffer) {
        setBit(&res, i, 0);
        buffer = 1;
      } else {
        setBit(&res, i, 0);
      }
    } else { // Включены оба бита
      if (buffer) {
        setBit(&res, i, 1);
        buffer = 1;
      } else {
        setBit(&res, i, 0);
        buffer = 1;
      }
    }
    if (i == 95 && buffer == 1 && var1->type != ADDCODE &&
        var2->type != ADDCODE) {
      res.type = _INFINITY;
    } else
      res.type = NORMAL_VALUE;
  }
  if (is_inf(var1, var2) != 0) {
    res.type = _INFINITY;
  }
  return res;
}