#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result){
 int status = OK;
 if(result == NULL || rows < 1 || columns < 1){
    status = INCORRECT_MATRIX;
  }else{
    result->matrix = (double**)calloc(rows, sizeof(double*));
    if(result->matrix == NULL){
        status = CALCULATION_ERROR;
    }else{
      for(int i = 0; i < rows; i++){
        result->matrix[i] = (double*)calloc(columns, sizeof(double));
      if(result->matrix[i] == NULL){
        status = CALCULATION_ERROR;
        break;
       }
      }
      if(status != CALCULATION_ERROR){
        result->rows = rows;
        result->columns = columns;
      }
    }
  }
  return status;
}

void s21_remove_matrix(matrix_t *A){
    if(A != NULL && A->matrix != NULL){
        for(int i = 0; i < A->rows; i++){
        free(A->matrix[i]);
        }
      free(A->matrix);
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B){
 int status = SUCCESS;
 int should_continue = 1;
  if(A->rows != B->rows || A->columns != B->columns){
    status = FAILURE;
  }else{
    for(int i = 0; i < A->rows && should_continue; i++){
      for(int j = 0; j < A->columns; j++){
        if(fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7){
          status = FAILURE;
          should_continue = 0;
        }
      }
    }
  }
  return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
  int status = s21_create_matrix(A->rows, A->columns, result);
 if(status == 0){
  if(A->rows != B->rows || A->columns != B->columns){
    status = 2;
  }else{
  for(int i = 0; i < A->rows; i++){
      for(int j = 0; j < A->columns; j++){
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
  int status = s21_create_matrix(A->rows, A->columns, result);
 if(status == 0){
  if(A->rows != B->rows || A->columns != B->columns){
    status = 2;
  }else{
  for(int i = 0; i < A->rows; i++){
      for(int j = 0; j < A->columns; j++){
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
  int status = s21_create_matrix(A->rows, A->columns, result);
 if(status == 0){
  for(int i = 0; i < A->rows; i++){
      for(int j = 0; j < A->columns; j++){
      result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
return status;
 }

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
  int status = s21_create_matrix(A->rows, B->columns, result);
  if(status == 0){
    if(A->columns != B->rows &&
        (result->columns != A->columns || result->rows != B->rows)) {
      status = 2;
    }else{
      for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < B->columns; j++){
          int sum = 0;
          for(int k = 0; k < A->columns; k++){
            sum += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = sum;
        }
      }
    }
  }
return status;
}

int s21_transpose(matrix_t *A, matrix_t *result){
  int status = s21_create_matrix(A->rows, A->columns, result);
  if(status == 0){
    for(int i = 0; i < A->rows; i++){
      for(int j = 0; j < A->columns; j++){
        result->matrix[i][j] = A->matrix[j][i]; 
      }
    }
  }
  return status;
}

void s21_create_submatrix(matrix_t *A, matrix_t *submatrix, int exclude_line, int exclude_col){
  for(int i = 0, sub_i = 0; i < A->rows; i++){
    if(i != exclude_line){
      for(int j = 0, sub_j = 0; j < A->columns; j++){
        if(j != exclude_col){
          submatrix->matrix[sub_i][sub_j] = A->matrix[i][j];
          sub_j++;
        }
      }
      sub_i++;
    }
  }
}

int s21_determinant(matrix_t *A, double *result){
  int status = 1;
  if(result != NULL){
    if(A->rows != A->columns){
      status = 2;
    }else{
      double det = 0;
      if(A->rows == 1){
        det = A->matrix[0][0];
      }else if(A->rows == 2){
        det = A->matrix[0][0] * A->matrix[1][1] -
              A->matrix[0][1] * A->matrix[1][0];
      }else{
        for(int i = 0; i < A->columns; i++){
          matrix_t submatrix;
          s21_create_matrix(A->rows -1, A->columns -1, &submatrix);
          s21_create_submatrix(A, &submatrix, 0, i);
          double subdet = 0;
          s21_determinant(&submatrix, &subdet);
          det += (i % 2 == 0 ? 1 : -1) * A->matrix[0][i] * subdet;
          s21_remove_matrix(&submatrix);
        }
      }
      *result = det;
      status = 0;
    }
  }
  return status;
}
 

int s21_calc_complements(matrix_t *A, matrix_t *result){
  int status = s21_create_matrix(A->rows, A->columns, result);
  if(status == 0){
    if(A->rows != A->columns){
      status = 2;
    }else{
      for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
          matrix_t submatrix;
          s21_create_matrix(A->rows -1, A->columns -1, &submatrix);
          s21_create_submatrix(A, &submatrix, i, j);
          double subdet = 0;
          s21_determinant(&submatrix, &subdet);
          result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * subdet;
          s21_remove_matrix(&submatrix);
        }
      }
    }
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result){
  int status = 1;
  if(result != NULL){
      double det = 0;
      s21_determinant(A, &det);
      status = 0;
      if(det != 0){
        matrix_t minor;
        s21_calc_complements(A, &minor);
        matrix_t transposition;
        s21_transpose(&minor, &transposition);
        s21_mult_number(&transposition, (1/det), result);
        s21_remove_matrix(&minor);
        s21_remove_matrix(&transposition);
      }else{
        status = 2;
      }
    }
  return status;
}