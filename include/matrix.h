#ifndef MATRIX_H
#define MATRIX_H

struct Matrix;
typedef struct Matrix *matriz;


// create space for a new matrix ixj
matriz* aloca(int i, int j)
// print a given matrix
void printamatriz(matriz* A)
// Returns the transposed matrix
matriz* transposta(matriz* A)
// return a reduced matrix (-1,-1)
matriz* reduz(matriz* m, int l, int r)
// calculates matrix determinant
matriz* determinante(matriz* m, int tam)
// add or subtract two matrices
matriz* adicao(matriz* A, matriz* B, bool x)
//  Returns the product of two matrices
matriz* multiplica(matriz* A, matriz* B)
// Returns an array with the result of the sum or difference of a scalar on all elements of the passed array
matriz* adicaoescalar(matriz* A, float escalar, bool x)
// Returns an array with the dot product result of the array and the value passed
matriz* multiplicaescalar(matriz* A, float escalar)
// Returns the inverse of the matrix
matriz* inversao(matriz* m)
// Receive input elements of a Matrix
matriz* lematriz(int x, int y)
// aux function to add/subtract
matriz* adsub(bool operacao)
// aux function to multiply 2 matrices
matriz* mult()
// aux function to add/subtract/multiply an matrix to a escalar
matriz* escalar(int a)
// aux function to transpose or inverse a matrix or calculate its determinant
matriz* transpinversa(int a)
#endif
