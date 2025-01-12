#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (A && A->matrix && (A != NULL && result != NULL)) {
    if (A->columns != A->rows) {
      flag = CALC_ERROR;
    } else {
      double sum = 0;
      s21_determinant(A, &sum);
      if (!sum) {
        flag = CALC_ERROR;
      }

      else {
        matrix_t result_2;
        matrix_t result_3;

        s21_calc_complements(A, &result_2);
        s21_transpose(&result_2, &result_3);
        s21_mult_number(&result_3, 1.0 / sum, result);

        s21_remove_matrix(&result_2);
        s21_remove_matrix(&result_3);
      }
    }
  } else {
    flag = INVALID_MATRIX;
  }

  return flag;
}