#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct fila
{
	float v;
	struct fila *next;
}funcao;

funcao* aloca (float valor)
{
	funcao* new = malloc(sizeof(funcao));

	new->v = valor;
	new->next = NULL;

	return new;
}

funcao* add (funcao* f, float valor)
{
	if (f == NULL)
		return aloca(valor);

	f->next = add(f->next, valor);
	return f;
}

float resposta (funcao* f, float valor, int n)
{
	funcao* aux = f->next;
	float soma = f->v;
	int i = n;

	while(aux != NULL)
	{
		soma = soma + (aux->v * pow(valor, i));
		aux = aux->next;
		i = i - 1;
	}

	return soma;
}

float riemann (funcao* f, float inicio, float fim, int divisoes, bool a, int n)
{
	float soma = 0;
	float largura = (fim - inicio)/divisoes;
	float x, y;
	
	if (a)
		x = inicio;
	else
		x = inicio + largura;

	for (int i = 0; i < divisoes; i++)
	{
		if(a)
			y = resposta(f, x, n);
		else
			y = resposta(f, y, n);

		soma = soma + y * largura;
	}

	return soma;
}

funcao* recebefuncao (int n)
{
	funcao* f = NULL;
	float valor;

	for (int i = n; i > 0; i--)
	{
		printf("Informe o termo de x^%d: ", i);
		scanf("%f", &valor);
		fflush(stdin);
		f = add(f, valor);
	}

	printf("Informe o termo independente: ");
	scanf("%f", &valor);
	fflush(stdin);
	f = add(f, valor);

	return f;
}

void printafuncao (funcao* f, int n)
{
	funcao* aux = f;
	for (int i = n; i > 0; i--)
	{
		printf("%.2fx^%d + ", aux->v,i);
		aux = aux->next;
	}

	printf(" %.2f\n\n", aux->v);
}

int main ()
{
	funcao *f;
	int n, div, lado;
	float x1, x2, area;

	printf("Informe a ordem da função linear (n): ");
	scanf("%d", &n);
	fflush(stdin);

	f = recebefuncao(n);
	printf("\nFuncao: ");
	printafuncao(f, n);
	
	printf("Digite o ponto inicial: ");
	scanf("%f", &x1);
	fflush(stdin);
	printf("Digite o ponto final: ");
	scanf("%f", &x2);
	fflush(stdin);
	printf("Número de divisoes desejadas: ");
	scanf("%d", &div);
	fflush(stdin);
	printf("Ler a direita (0) ou a esquerda (1)? ");
	scanf("%d", &lado);
	fflush(stdin);

	area = riemann(f, x1, x2, div, lado, n);

	printf("\n\nO valor da area e %.2f", area);


	return 0;
}