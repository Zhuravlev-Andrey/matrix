#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    flag = INVALID_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;

    // Array of pointers to arrays
    //  result->matrix = (double **)malloc(rows * sizeof(double *));

    // for (int i = 0; i < rows; i++)
    // {
    //     result->matrix[i] = (double *)malloc(columns * sizeof(double));
    // }

    // Array of pointers to array segments within one buffer
    result->matrix = (double **)calloc(rows + rows * columns, sizeof(double));
    double *ptr = (double *)(result->matrix + rows);
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + columns * i;
        if (result->matrix[i] == NULL) flag = INVALID_MATRIX;
      }

      // Array of pointers to segments of the second array
      // result->matrix = malloc(rows * sizeof(double *));
      // double *ptr = malloc(rows * columns * sizeof(double));

      // for (int i = 0; i < rows; i++)
      // {
      //     result->matrix[i] = ptr + columns * i;
      // }
    } else {
      flag = INVALID_MATRIX;
    }
  }

  return flag;
}