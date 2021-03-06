#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Matrix
{
	float M[20][20];
	int line;
	int row;
}matriz;


matriz* aloca(int i, int j)
{
	matriz *m = malloc(sizeof(matriz));
	m->line = i;
	m->row = j;

	return m;
}


void printamatriz(matriz* A)
{
	for (int i = 0; i < A->line; i++)
	{
		for (int j = 0; j < A->row; j++)
			printf("%.2f ", A->M[i][j]);

		printf("\n");
	}

	fflush(stdin);
}


matriz* transposta(matriz* A)
{
	matriz* m = aloca(A->row, A->line);

	for (int i = 0; i < A->row; i++)
		for (int j = 0; j < A->line; j++)
			m->M[i][j] = A->M[j][i];

	return m;
}

matriz* reduz(matriz* m, int l, int r)
{
	matriz* A = aloca(m->line - 1, m->row - 1);


	int varx, vary;
	varx = vary = 0;

	for (int i = 0; i < A->line; i++)
	{
		for (int j = 0; j < A->row; j++)
		{
			if (l == i)
				varx = 1;

			if (r == j)
				vary = 1;

			A->M[i][j] = m->M[i+varx][j+vary];
		}
		vary = 0;
	}

	return A;
}

matriz* determinante(matriz* m, int tam)
{	
	if (tam == 1)
		return m;
	
	if(tam == 2)
	{
		matriz* new = aloca(1,1);
		new->M[0][0] = ((m->M[0][0] * m->M[1][1]) - (m->M[0][1] * m->M[1][0]));
		return new;
	}

	matriz* B;

	float soma = 0;
	for (int i = 0; i < m->line; i++)
	{
		B = reduz(m, 0, i);
		soma = soma + (m->M[0][i] * pow(-1, i) * determinante(B, B->line)->M[0][0]);
		free(B);
	}
	matriz* A = aloca(1,1);
	A->M[0][0] = soma;
	return A;
}

matriz* adicao(matriz* A, matriz* B, bool x)
{	
	matriz* m = aloca(A->line, A->row);

	for(int i = 0; i < A->line; i++)
		for (int j = 0; j < A->row; j++)
			if(x == 0)
				m->M[i][j] = A->M[i][j] + B->M[i][j];
			else
				m->M[i][j] = A->M[i][j] - B->M[i][j];

	return m;
}


matriz* multiplica(matriz* A, matriz* B)
{
	if(A->row != B->line)
		return NULL;

	matriz* m = aloca(A->line, B->row);


	for (int i = 0; i < A->line; i++)
		for (int j = 0; j < B->row; j++)
		{
			float soma = 0;
			for (int x = 0; x < B->line; x++)
				soma = soma + A->M[i][x] * B->M[x][j];
			m->M[i][j] = soma;
		}

	return m;
}

matriz* adicaoescalar(matriz* A, float escalar, bool x)
{
	matriz* m = aloca(A->line, A->row);

	for (int i = 0; i < A->line; i++)
		for (int j = 0; j < A->row; j++)
			if (x == 0)
				m->M[i][j] = A->M[i][j] + escalar;
			else
				m->M[i][j] = A->M[i][j] - escalar;

	return m;
}

matriz* multiplicaescalar(matriz* A, float escalar)
{
	matriz* m = aloca(A->line, A->row);

	for (int i = 0; i < A->line; i++)
		for (int j = 0; j < A->row; j++)
			m->M[i][j] = A->M[i][j] * escalar;

	return m;
}

matriz* inversao(matriz* m)
{
	float D = determinante(m, m->line)->M[0][0];
	matriz* A = aloca(m->line, m->row);

	for (int i = 0; i < m->line; i++)
		for (int j = 0; j < m->row; j++)
			A->M[i][j] = pow(-1, i + j) * determinante(reduz(m, i, j), m->line - 1)->M[0][0];

	A = transposta(A);

	A = multiplicaescalar(A, 1/D);

	return A;
}

matriz* lematriz(int x, int y)
{
	matriz* A = aloca(x, y);
	float valor;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			scanf("%f", &valor);
			A->M[i][j] = valor;
		}

	printf("\n\n");
	return A;
}

matriz* adsub(bool operacao)
{
	matriz *A, *B;
	int x, y;
	printf("N??mero de linhas das Matrizes: ");
	scanf("%d", &x);
	printf("N??mero de colunas das Matrizes: ");
	scanf("%d", &y);
	if(x < 1 || y < 1)
	{
		printf("Inv??lido");
		return NULL;
	}
	printf("Insira a Matriz 1:\n");
	A = lematriz(x, y);
	printf("Insira a Matriz 2:\n");
	B = lematriz(x, y);

	return adicao(A, B, operacao);
}

matriz* mult()
{
	matriz *A, *B;
	int x, y;
	printf("N??mero de linhas da Matriz A: ");
	scanf("%d", &x);
	printf("N??mero de colunas das Matriz A: ");
	scanf("%d", &y);
	if(x < 1 || y < 1)
	{
		printf("Inv??lido");
		return NULL;
	}
	printf("Insira a Matriz A:\n");
	A = lematriz(x, y);
	printf("N??mero de colunas das Matriz B: ");
	scanf("%d", &x);
	printf("Insira a Matriz B:\n");
	B = lematriz(y, x);

	return multiplica(A, B);
}

matriz* escalar(int a)
{
	matriz* A;
	int x, y;
	float esc;
	printf("N??mero de linhas das Matrizes: ");
	scanf("%d", &x);
	printf("N??mero de colunas das Matrizes: ");
	scanf("%d", &y);
	if(x < 1 || y < 1)
	{
		printf("Inv??lido");
		return NULL;
	}

	printf("Informa a Matriz:\n");
	A = lematriz(x, y);

	printf("\nInforme o escalar: ");
	scanf("%f", &esc);

	switch (a)
	{
		case 1:
			return adicaoescalar(A, esc, 0);

		case 2:
			return adicaoescalar(A, esc, 1);

		case 3:
			return multiplicaescalar(A, esc);
	}

}

matriz* transpinversa(int a)
{
	matriz* A;
	int x, y;
	float esc;
	printf("N??mero de linhas das Matrizes: ");
	scanf("%d", &x);
	if (a == 1)
	{
		printf("N??mero de colunas das Matrizes: ");
		scanf("%d", &y);
	}
	else
		y = x;

	if(x < 1 || y < 1)
	{
		printf("Inv??lido");
		return NULL;
	}

	printf("Informe a Matriz:\n");
	A = lematriz(x, y);

	switch(a)
	{
		case 1:
			return transposta(A);

		case 2:
			return determinante(A, x);

		case 3:
			return inversao(A);
	}
}

int main()
{
	bool loop = 1;
	int opcao;
	int x, y;
	matriz* A;

	while (loop)
	{
		printf("1 - Somar matrizes;\n2 - Subtrair matrizes;\n3 - Multiplicar matrizes;\n4 - Somar matriz por escalar;\n");
		printf("5 - Subtrair matriz por escalar;\n6 - Multiplicar matriz por escalar;\n7 - Matriz Transposta;\n");
		printf("8 - Determinante;\n9 - Matriz Inversa;\n10 - Sair\n\nEscolha uma op????o: ");
		scanf("%d", &opcao);
		fflush(stdin);

		switch(opcao)
		{
			case 1:
				A = adsub(0);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 2:
				A = adsub(1);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 3:
				A = mult();
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 4:
				A = escalar(1);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 5:
				A = escalar(2);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 6:
				A = escalar(3);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 7:
				A = transpinversa(1);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				else
					printf("FOINULL");
				break;


			case 8:
				A = transpinversa(2);
				if (A != NULL)
				{
					printf("O determinante eh: %.2f", A->M[0][0]);
					free(A);
				}
				break;


			case 9:
				A = transpinversa(3);
				if (A != NULL)
				{
					printamatriz(A);
					free(A);
				}
				break;

			case 10:
				loop = 0;
		}

		printf("\n\n");
	}

	return 0;
}