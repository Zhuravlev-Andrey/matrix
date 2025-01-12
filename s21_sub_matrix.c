#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A->matrix != NULL && B->matrix != NULL) {
    if (A->columns != B->columns || A->rows != B->rows) {
      flag = CALC_ERROR;
    } else if (A->columns == 1 && B->columns == 1) {
      result->matrix[0][0] = A->matrix[0][0] - B->matrix[0][0];
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (result->matrix != NULL) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    }
  } else {
    flag = INVALID_MATRIX;
  }
  return flag;
}