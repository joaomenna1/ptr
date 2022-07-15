#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

struct Matrix {
    int a, b;
    double **data;
    char *name;
};

Matrix matrix_empty(int a, int b, char *name) {
    Matrix new_matrix = malloc(sizeof(Matrix));

    new_matrix = calloc(a, sizeof(double *));

    for (int i =0; i < a; i++) {
        new_matrix->data[i] = calloc(b,sizeof(double));
    }

    new_matrix->a = a;
    new_matrix->b = b;
    return new_matrix;
}

Matrix matrix_sum(Matrix matrix1, Matrix matrix2, char *name) {
    
    if (matrix1->a == matrix2->a && matrix1->b == matrix2->b) {
        Matrix new_matrix = matrix_empty(matrix1->a, matrix1->b, name);
        for (int i = 0; i < new_matrix->a; i++) {
            for (int j = 0; j < new_matrix->b; j++ ) {
                new_matrix->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
            }
        }
        return new_matrix;
    }else {
        printf("Matrix should have same dimensions");
        return NULL;
    }
}

Matrix matrix_difference(Matrix matrix1, Matrix matrix2, char *name) {
    if (matrix1->a == matrix2->a && matrix1->b == matrix2->b) {
        Matrix new_matrix = matrix_empty(matrix1->a, matrix1->b, name);
        for (int i = 0; i < new_matrix->a; i++) {
            for (int j = 0; j < new_matrix->b; j++ ) {
                new_matrix->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
            }
        }
        return new_matrix;
    }else {
        printf("Matrix should have same dimensions");
        return NULL;
    }
}

Matrix matrix_product(Matrix matrix1, Matrix matrix2, char *name) {
     if (matrix1->a == matrix2->a && matrix1->b == matrix2->b) {
        Matrix new_matrix = matrix_empty(matrix1->a, matrix1->b, name);
        for (int i = 0; i < new_matrix->a; i++) {
            for (int j = 0; j < new_matrix->b; j++ ) {
                for (int k = 0; j < matrix2->a; k++) {
                    new_matrix->data[i][j] += matrix1->data[i][j] * matrix2->data[k][j];
                }
            }
        }
        return new_matrix;
    }else {
        printf("Matrix should have same dimensions");
    }
        return NULL;
}

Matrix matrix_by_scalar_sum(Matrix matrix, double scalar, char *name) {
    Matrix new_matrix = matrix_empty(matrix->a, matrix->b, name);
    for (int i = 0 ; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            new_matrix->data[i][j] = scalar + matrix->data[i][j];
        }
    }
    return new_matrix;
}

Matrix matrix_by_scalar_product(Matrix matrix, double scalar, char *name) {
    Matrix new_matrix = matrix_empty(matrix->a, matrix->b, name);
    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            new_matrix->data[i][j] = matrix->data[i][j] * scalar;
        }
    
    }
    return new_matrix;
}

Matrix matrix_by_scalar_difference(Matrix matrix, double scalar,char *name) {
  Matrix new_matrix = matrix_empty(matrix->a, matrix->b, name);
    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            new_matrix->data[i][j] = matrix->data[i][j] - scalar;
        }
    }
    return new_matrix;
}

Matrix matrix_transposed(Matrix matrix, char *name) {
    Matrix new_matrix = matrix_empty(matrix->a, matrix->b, name);
    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            new_matrix->data[j][i] = matrix->data[i][j];
        }
    }
    return new_matrix;
}

double matrix_determinant(Matrix matrix) {
     if (matrix->a != matrix->b)
    {
        printf("A matriz deve ser quadrada.\n");
        exit(1);
    }
    else if (matrix->a >= 5)
    {
        printf("Esta funcao se limita ao calculo de determinante de uma matriz 4x4.\n");
        exit(1);
    }
    else {
        double determinant = 0;
        switch (matrix->a) {
            case 1:
                determinant = matrix->data[0][0];
                return determinant;
                break;
            case 2:
                determinant = matrix->data[0][0] * matrix->data[1][1] - matrix->data[1][0] * matrix->data[0][1];
                return determinant;
                break;
            case 3:
            //Sarrus
                determinant = matrix->data[0][0] * matrix->data[1][1] * matrix->data[2][2] 
                    + matrix->data[0][1] * matrix->data[1][2] * matrix->data[2][0]
                    + matrix->data[2][1] * matrix->data[1][0] * matrix->data[0][2] 
                    - matrix->data[2][0] * matrix->data[1][1] * matrix->data[0][2] 
                    - matrix->data[1][0] * matrix->data[0][1] * matrix->data[2][2] 
                    - matrix->data[2][1] * matrix->data[1][2] * matrix->data[0][0];
                return determinant;
                break;
            default:
             // Teorema de Laplace
             for (int i = 0; i < matrix->a; i++)
                determinant += matrix->data[0][i] * mat_cofactor(matrix, 0, i);
                break;
                return determinant;
        }
    }

}

double matrix_cofactor(Matrix matrix, int a, int b)
{
    if (a > matrix->a || b > matrix->b)
    {
        printf("Cofactor addressing exceeds array size.\n");
        exit(1);
    }
    else if (matrix->a != matrix->b)
    {
        printf("The matrix must be square.\n");
        exit(1);
    }
    else if (matrix->a >= 5)
    {
        printf("This function is limited to the calculation of cofactors of a 4x4 matrix.\n");
        exit(1);
    }
    else
    {
        //main minor
        Matrix new_mat = mat_sup(matrix, a, b, "cofactor\n");
        //result determinant
        double det = mat_det(new_mat);
        if ((a + b) % 2 != 0) //Multiply by -1 the values ​​where a+b are odd
            det = -det;
        //return coafactor
        matrix_delete(new_mat);
        return det;
    }
}

void matrix_delete(Matrix matrix) {
    for (int i = 0; i < matrix->a; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void printm(Matrix matrix) {
    if (matrix == NULL) {
        printf("Matrix null\n");
        return;
    }
    printf("%s\n", matrix->name);
    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            printf("%.3lf  ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


Matrix matrix_insert() {
    int a = 0;
    int b = 0;
    char *name = malloc(sizeof(char));

    printf("Insert the number of lines\n");
    scanf("%d", &a);
    printf("Insert the number of columns\n");
    scanf("%d", &b);
    printf("Insert the name matrix\n");
    scanf("%s", name);

    if (a <= 0 || b <= 0){
        printf("The array was not created. the number of rows or columns must be greater than zero.\n");
        return NULL;
    }

    Matrix matrix = matrix_empty(a, b, name);

    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {
            printf("Insert element line: %d, column: %d\n", i, j);
            scanf("%lf", &matrix->data[i][j]);
        }
    }
    printf("Matriz created success!\n");
    //mat_display(matrix);
    return matrix;
}

