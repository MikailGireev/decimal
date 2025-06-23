#include "../decimal.h"

/**
 * @brief Вычитание двух чисел децимал
 * @param result Указательный на результат вычитания
 * @param num1 Первое число децимал
 * @param num2 Второе число децимал
 */
void decimal_substact(Decimal *result, const Decimal *num1, const Decimal *num2) {
  Decimal negated_num2 = *num2;
  decimal_negative(&negated_num2);
  *result = bitAddition(num1, &negated_num2);
}