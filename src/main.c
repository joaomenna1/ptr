#include <stdlib.h>
#include <dstring.h>
#include <matrix.h>
#include "stdio.h"

enum options
{
    EXIT_PROGRAMN,
    DO_MAKE_ADT_STRING,
    INSERT_M1,
    INSERT_M2,
    CREATE_MATRIX_ZEROS,
    CREATE_MATRIX_ONES, // MAYBE NECESSARY
    DO_MATRIX_SUM,
    DO_MATRIX_DIFFERENCE,
    DO_MATRIX_PRODUCT,
    DO_MATRIX_BY_SCALAR_SUM,
    DO_MATRIX_BY_SCALAR_PRODUCT,
    DO_MATRIX_TRANSPOSED,
    DO_MATRIX_INVERSE,
    REMOVE_LINE_COL,
    RESULT_MATRIX_DETERMINAT,
    RESULT_MATRIX_COFACTOR,
    DO_MATRIX_COF,
    DO_MATRIX_ADJ,
    SHOW_MATRIX1,
    SHOW_MATRIX2
}; 


int menu_option;
void open_menu();

/*Functions that ask the user to enter data through scanf()
  I don't know if it will be necessary, this functions hahahah!  
*/

int setLines();
int setColumns();
char *setNameMatrix();
double setScalar();

int main() {
    Matrix matrix1 = NULL;
    Matrix matrix2 = NULL;
    int a, b;

    while (1)
    {
        open_menu();
        switch (menu_option) {
            case EXIT_PROGRAMN:
                exit(0);
            break;

            case DO_MAKE_ADT_STRING:
                adt_string();
            break;        

            default:
                printf("Insert options invalidate");
                break;
        }
    }
    
  
}


int setLines() {
    
    int lines;
    printf("Insert row number in matrix\n");
    scanf("%d",&lines);
}

int setColumns() {

    int columns;
    printf("Insert columns number in matrix\n");
    scanf("%d",&columns);
    return columns;
}

char *setNameMatrix() {

    char *name = malloc(sizeof(char));
    printf("Insert name matrix: ");
    scanf("%s", name);
    return name;
}

double setScalar() {

    double scalar;
    printf("Insert escalar: ");
    scanf("%lf", &scalar);
    return scalar;
}

void adt_string() {
      printf("\n [ADT STRINGS] -Welcome to the jungle - [lab 1] Programing Real Time\n");
    printf("\nCreated 2 strings...\n");
    dstring str1 = new_string("first");
    dstring str2 = new_string("second");

    string_print(str1);
    string_print(str2);

    printf("\n---------------------\n");
    printf("----------------------\n");
    printf("\ncopy string...\n");
    printf("\n---------------------\n");

    str1 = string_copy(str2);
    printf("\nString copied:\n");
    string_print(str1);

    string_free(str1);
    string_free(str2);

    printf("\n---------------------\n");
    printf("----------------------\n");
    printf("\nfree init variable in memory.....\n");
    printf("\n---------------------\n");
    printf("\nStart news variables....\n");
    printf("\n---------------------\n");
    printf("---------------------\n");

    dstring str3 = new_string("hiii");
    dstring str4 = new_string("world");

    printf("\nConstructing new strings [hiii] and [world]\n");
    string_print(str3);
    string_print(str4);

    printf("\nconcating....\n");

    dstring str5 = string_concat(str3, str4);
    string_print(str5);

    printf("\nString concat success!:\n");

    printf("\nChecking size string concated...\n");

    printf("Size string : %d  check!\n", string_lenght(str5));

    printf("\nTesting using macro\n");
    printf("%s\n", $(str5));
}

void open_menu()
{
    printf("\nDigite o numero da opcao desejada\n");
    printf("1. adt strings\n");
    printf("1. Inserir uma matriz m1\n");
    printf("2. Inserir uma matriz m2\n");
    printf("3. Criar matriz de zeros\n");
    printf("4. Criar matriz de uns\n");
    printf("5. Criar matriz identidade\n");
    printf("6. Soma de matrizes\n");
    printf("7. Subtracao de matrizes\n");
    printf("8. Multiplicacao de matrizes\n");
    printf("9. Soma por escalar\n");
    printf("10. Multiplicação por escalar\n");
    printf("11. Transposta\n");
    printf("12. Inversa\n");
    printf("13. Remover uma linha e coluna\n");
    printf("14. Determinante\n");
    printf("15. Cofator\n");
    printf("16. Matriz de cofatores\n");
    printf("17. Adjunta\n");
    printf("18. Exibir a matriz M1\n");
    printf("19. Exibir a matriz M2\n");
    printf("0. Encerrar programa\n\n");

    printf("Opcao: ");
    scanf("%d", &menu_option);
}

