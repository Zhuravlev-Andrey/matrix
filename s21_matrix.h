#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum RES_CODE { OK, INVALID_MATRIX, CALC_ERROR };
enum EQ_CODE { FAILURE, SUCCESS };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns,
                      matrix_t *result);      // Создание матриц
void s21_remove_matrix(matrix_t *A);          // Очистка матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);  // Очистка матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Вычитание матриц
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // Умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // Умножение матриц
int s21_transpose(matrix_t *A, matrix_t *result);  // Транспонирование матриц
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  // Минор матрицы и матрица алгебраических дополнений
int s21_determinant(matrix_t *A,
                    double *result);  // Вычисление детерминанта матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // Обратная матрица

// доп функции
void s21_print(matrix_t *result);
int s21_mini_minor(matrix_t *A, int i, int j, matrix_t *minor);
int s21_valid_matrix(matrix_t *A);
#endif