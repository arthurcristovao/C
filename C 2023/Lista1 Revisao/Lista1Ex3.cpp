#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
	char nome[30];
	char *marca;
	float preco;
	
} Produto;

int main(){
	Produto p1, p2;
	int tam = 20;
	
	p1.marca = (char *) malloc(tam * sizeof(char));
	p2.marca = (char *) malloc(tam * sizeof(char));
	
	printf("\nCadastre um produto.\n");
	printf("Digite o nome: ");
	scanf("%s", p1.nome);
	printf("Digite a marca: ");
	scanf("%s", p1.marca);
	printf("Digite o preco: ");
	fflush(stdin);
	scanf("%f", &p1.preco);
	
	printf("\nCadastre um produto.\n");
	printf("Digite o nome: ");
	scanf("%s", p2.nome);
	printf("Digite a marca: ");
	scanf("%s", p2.marca);
	printf("Digite o preco: ");
	fflush(stdin);
	scanf("%f", &p2.preco);
	

	printf("O produto 1 é:\n\n%s\n%s\n%.2f\n", p1.nome, p1.marca, p1.preco*1.1);
	printf("O produto 1 é:\n\n%s\n%s\n%.2f\n", p2.nome, p2.marca, p2.preco*1.1);
}
