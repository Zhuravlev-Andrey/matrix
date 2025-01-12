#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (s21_valid_matrix(A)) {
    flag = s21_valid_matrix(A);
  } else if (s21_valid_matrix(B)) {
    flag = s21_valid_matrix(B);
  } else if (A->columns != B->columns || A->rows != B->rows) {
    flag = CALC_ERROR;
  }
  if (!flag && !(flag = s21_create_matrix(A->rows, A->columns, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return flag;
}