#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (s21_valid_matrix(A)) {
    flag = s21_valid_matrix(A);
  } else if (A->columns != A->rows) {
    flag = CALC_ERROR;
  }

  if (!flag) {
    if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (A->columns == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else {
      double determinant = 0;

      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

      for (int j = 0; j < A->columns; j++) {
        flag = s21_mini_minor(A, 0, j, &minor);
        if (!flag) {
          double minor_determinant;
          s21_determinant(&minor, &minor_determinant);
          determinant += minor_determinant * A->matrix[0][j] * pow(-1, j);

          *result = (int)determinant;
        }
      }
      s21_remove_matrix(&minor);
    }
  }
  return flag;
}