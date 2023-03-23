#include <stdio.h>
#include <stdlib.h>

#define tam 10

typedef struct funcionario {
	char nome[20];
	char sobrenome[20];
	float salario;
} Funcionario;

void cadastra(Funcionario * f){
	for( int i = 0; i < tam ; i++ ){
		printf("\nCadastre um funcionario:\n");
		printf("Digite o nome: ");
		scanf("%s", f[i].nome);
		printf("Digite sobrenome: ");
		scanf("%s", f[i].sobrenome);
		printf("Digite o salario: ");
		fflush(stdin);
		scanf("%f", &f[i].salario);
	}
}

void lista(Funcionario * f){
	printf("\n");
	for( int i = 0; i < tam ; i++ ){
		printf("Funcionario %d\n", i+1);
		printf("%s\n", f[i].nome);
		printf("%s\n", f[i].sobrenome);
		printf("%.2f\n\n", f[i].salario);
	}
}

void media(Funcionario * f){
	float media = 0;
	for( int i = 0; i < tam ; i++ ){
		media += f[i].salario;
	}
	media /= tam;
	printf("A media salarial dos %d funcionarios eh: %.2f reais", tam, media);
}

int main(){
	Funcionario f[tam];
	
	cadastra(f);
	lista(f);
	media(f);
}
