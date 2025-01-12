#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (s21_valid_matrix(A)) {
    flag = s21_valid_matrix(A);
  } else if (A->columns != A->rows) {
    flag = CALC_ERROR;
  } else {
    flag = s21_create_matrix(A->rows, A->columns, result);

    if (flag == OK) {
      if (A->columns == 1 && A->rows == 1) {
        // Обработка матрицы 1x1
        result->matrix[0][0] = 1;
      } else {
        // Вычисления для матриц большего размера
        for (int i = 0; !flag && i < A->columns; i++) {
          for (int j = 0; !flag && j < A->rows; j++) {
            matrix_t result_minor;
            s21_create_matrix(A->rows - 1, A->columns - 1, &result_minor);

            flag = s21_mini_minor(A, i, j, &result_minor);
            if (!flag) {
              flag = s21_determinant(&result_minor, &result->matrix[i][j]);
              result->matrix[i][j] *= pow(-1, i + j);
            }
            s21_remove_matrix(&result_minor);
          }
        }
      }
    }
  }
  return flag;
}
