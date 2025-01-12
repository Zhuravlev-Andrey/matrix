#include "s21_matrix.h"

// void s21_print(matrix_t *result) {
//   for (int i = 0; i < result->rows; i++) {
//     for (int j = 0; j < result->columns; j++) {
//       printf("%.lf ", result->matrix[i][j]);
//     }
//     printf("\n");
//   }
// }

int s21_mini_minor(matrix_t *A, int i, int j, matrix_t *minor) {
  int rows = 0;
  int columns = 0;
  for (int k = 0; k < A->rows; k++) {
    for (int m = 0; m < A->columns; m++) {
      if (k != i && m != j) {
        minor->matrix[rows][columns] = A->matrix[k][m];
        columns++;
        if (columns >= minor->columns) {
          rows++;
          columns = 0;
        }
      }
    }
  }
  return 0;
}

int s21_valid_matrix(matrix_t *A) {
  int error_code = OK;
  if (A && A->matrix && A->columns > 0 && A->rows > 0) {
    for (int i = 0; !error_code && i < A->rows; i++) {
      for (int j = 0; !error_code && j < A->columns; j++) {
        error_code = (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j]))
                         ? CALC_ERROR
                         : OK;
      }
    }
  } else {
    error_code = INVALID_MATRIX;
  }
  return error_code;
}