#ifndef MATRIX_H
#define MATRIX_H

struct Matrix;
typedef struct Matrix *Matrix;

/*(NOTE): Matrix they must contain the same dimension */

/* returns the sum of two matrices. */
Matrix matrix_sum(Matrix matrix1, Matrix matrix2, char *name);
/* Returns the difference of two matrices. */
Matrix matrix_difference(Matrix matrix1, Matrix matrix2, char *name);
/* Returns the product of two matrices. */
Matrix matrix_product(Matrix matrix1, Matrix matrix2, char *name);
/* Returns an array with the result of the sum of a scalar on all elements of the passed array. */
Matrix matrix_by_scalar_sum(Matrix matrix, double scalar,char *name);
/*Returns an array with the dot product result of the array and the value passed.*/
Matrix matrix_by_scalar_product(Matrix matrix, double scalar, char *name);
/* Returns an array with the result of the difference of a scalar on all elements of the passed array. */
Matrix matrix_by_scalar_difference(Matrix matrix, double scalar,char *name);
/* Returns the transposed matrix */
Matrix matrix_transposed(Matrix matrix, char *name);
/* Returns the determinant of the matrix. */
double matrix_determinant(Matrix matrix);
/* Returns the inverse of the matrix. */
Matrix matrix_inverse(Matrix matrix, char *name);
/*Destroy the matrix.*/
void matrix_delete(Matrix matrix);
/* Print matrix in terminal */
void printm(Matrix matrix);
/* returns An array of zeros. */
Matrix matrix_empty(int a, int b,char *name);
/*Returns the cofactor associated with the ab element of the array*/
double matrix_cofactor_by_associated_a_matrix(Matrix matrix, int a, int b);
/*Returns the cofactor matrix*/
Matrix matrix_cofactor(Matrix matrix);
/*One returns a row and a column defined as arrays.*/
Matrix matrix_minor_complementary(Matrix matrix, int a, int b, char *name);
/*Allows the user to insert data into the array*/
Matrix matrix_insert();
/*returns a adjacent array*/
Matrix matrix_adjacent(Matrix matrix);
#endif
