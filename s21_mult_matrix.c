#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (s21_valid_matrix(A)) {
    flag = s21_valid_matrix(A);
  } else if (s21_valid_matrix(B)) {
    flag = s21_valid_matrix(B);
  } else if (A->columns != B->rows) {
    flag = CALC_ERROR;
  } else if (A && A->matrix) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double sum = 0;
        for (int k = 0; k < A->columns; k++) {
          sum += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = sum;
      }
    }
  } else {
    flag = INVALID_MATRIX;
  }

  return flag;
}
