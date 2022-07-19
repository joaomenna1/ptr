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
        printf("The matrix must be square\n");
        exit(1);
    }
    else if (matrix->a >= 5)
    {
        printf("This function is limited to calculating the determinant of a 4x4 matrix.\n");
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
                determinant += matrix->data[0][i] * matrix_cofactor(matrix, 0, i);
                break;
                return determinant;
        }
    }

}

double matrix_cofactor_by_associated_a_matrix(Matrix matrix, int a, int b) {

    if (a > matrix->a || b > matrix->b) {
        printf("Cofactor addressing exceeds array size.\n");
        exit(1);
    } else if (matrix->a != matrix->b) {
        printf("The matrix must be square.\n");
        exit(1);
    } else if (matrix->a >= 5) {
        printf("This function is limited to the calculation of cofactors of a 4x4 matrix.\n");
        exit(1);
    } else {
        //main minor
        Matrix new_matrix = matrix_minor_complementary(matrix, a, b, "cofactor\n");
        //result determinant
        double det = matrix_determinant(new_matrix);
        if ((a + b) % 2 != 0) //Multiply by -1 the values ​​where a+b are odd
            det = -det;
        //return coafactor
        matrix_delete(new_matrix);
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

Matrix matrix_minor_complementary(Matrix matrix, int a, int b, char *name) {

    if (a > matrix->a - 1 || b > matrix->b - 1)
    {
        printf("Values ​​passed exceed array bounds\n");
        return NULL;
    }
    Matrix new_matrix = matrix_empty(matrix->a - 1, matrix->b - 1, name);
    // aux_a e aux_b are triggers that fire when the counter passes through 
    // line and columns removed
    // They add the counter by one, removing a row or column
    int aux_a = 0, aux_b = 0;

    for (int i = 0; i < new_matrix->a; i++) {
        if (i == a) aux_a = 1;

        for (int j = 0; j < new_matrix->b; j++) {

            if (j >= b) aux_b = 1;
            else
                aux_b = 0;
                new_matrix->data[i][j] = matrix->data[i + aux_a][j + aux_b];
        }
    }

    return new_matrix;
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
    //printm(matrix);
    return matrix;
}

Matrix matrix_cofactor(Matrix matrix) {
    
    Matrix new_matrix = matrix_empty(matrix->a, matrix->b, matrix->name);

    for (int i = 0; i < matrix->a; i++)
    {
        for (int j = 0; j < matrix->b; j++)
        {
            new_matrix->data[i][j] = matrix_cofactor_by_associated_a_matrix(matrix, i, j);
        }
    }

    return new_matrix;
}

Matrix matrix_adjacent(Matrix matrix) {

    Matrix new_mat = matrix_transposed(matrix_cofactor(matrix), matrix->name);
    return new_mat;
}

Matrix matrix_inverse(Matrix matrix, char *name) {

    double determinant = matrix_determinant(matrix);
    
    if (determinant == 0) {
        printf("The inverse does not exist, the determinate is equal to zero\n");
        return NULL;
    }

    Matrix new_matrix = matrix_adjacent(matrix);

    new_matrix->name = name;

    for (int i = 0; i < matrix->a; i++) {
        for (int j = 0; j < matrix->b; j++) {

            new_matrix->data[i][j] = new_matrix->data[i][j] / determinant;
        }
    }

    return new_matrix;
}