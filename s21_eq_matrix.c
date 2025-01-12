#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  int result = 0;
  if (A->matrix == NULL || B->matrix == NULL || A->columns != B->columns ||
      A->rows != B->rows) {
    flag = FAILURE;
  } else {
    if (A && B && A->matrix && B->matrix && A->rows == B->rows &&
        A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if ((float)A->matrix[i][j] != (float)B->matrix[i][j] && result != 1) {
            flag = FAILURE;
            result = 1;
          }
        }
      }
    }
  }
  return flag;
}

// TODO У меня элемент А домножаю на 10 и элемент В умножаю на 10. Инт(А*10^7)
// != инт(В*10^7). Но я еще знаю такой метод (флоат)А != (флоат)В. Может на него
// поменяю. Флоат, так как он до 7 знаков после запятой работает.
