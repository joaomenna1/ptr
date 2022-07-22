#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matriz.h>

typedef struct fila
{
	float v;
	struct fila *next;
}funcao;

funcao* aloca (float valor)
{
	funcao* new = malloc(sizeof(funcao));

	new->v = valor;
	new->prox = NULL;
}

funcao* add (funcao* f, float valor)
{
	if (f == NULL)
		return aloca(valor);

	f->next = add(f->next, valor);
	return f;
}

float resposta (funcao* f, float valor)
{
	funcao* aux = f->next;
	float soma = f->v;
	int i = 1

	while(aux != NULL)
	{
		soma = soma + (aux->v * pow(valor, i));
		i = i + 1;
	}

	return soma;
}

float riemann (funcao* f, float inicio, float fim, int divisoes, bool a)
{
	float soma = 0;
	float largura = (fim - inicio)/divisões;
	float x, y;
	
	if (a)
		x = inicio;
	else
		x = inicio + largura;

	for (int i = 0; i < divisoes; i++)
	{
		if(a)
			y = resposta(f, x1);
		else
			y = resposta(f, x2);

		soma = soma + y * largura;
	}

	return soma;
}

float pontomedio (funcao* f, float inicio, float fim)
{
	float h = fim - inicio;
	float x = (inicio + fim)/2;

	return (h * resposta(f, x));
}

float trapezio (funcao* f, float inicio, float fim, int intervalos)
{
	float soma = 0;
	float h = (fim - inicio);
	float largura = (fim - inicio)/intervalos;
	float x = inicio;

	for (int i = 0; i < intervalos; i++)
	{
		soma = soma + ((h/intervalos) * (resposta(f, x) + resposta(f, x + largura)));
		x = x + largura;
	}

	return soma;
}

float simpson (funcao *f, float inicio, float fim, int intervalos)
{
	float h = (fim - inicio)/2;
	float x2 = (inicio + fim)/2;
	float largura = (fim - inicio)/intervalos;
	float soma = 0;

	float x1 = inicio;
	float x2 = x1 + largura;


	for (int i = 0; i < intervalos; i++)
	{
		soma = soma + ((resposta(f, x1) + 4 * resposta((x1 + x2)/2) + resposta(f, x2))/(3*intervalos));
		x1 = x2;
		x2 = x2 + largura;
	}

	return (soma * h);
}

float quadratura (funcao *f)
{
	int n;
	int pontos[10];
	float matriz[10][10];
	float results[10];

	float x;

	printf("Quantos pontos (maximo 10)? ");
	scanf("%d", &n);
	fflush(stdin);

	for (int i = 0; i < n; i++)
	{
		printf("Insira o ponto %d: ", i);
		scanf("%f", &x);
		pontos = add(f, x);
	}

	float h = pontos[n-1] - pontos[0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matriz[i][j] = pow(pontos[j], i);
			results[i] = 1/(i+1);
		}


}

