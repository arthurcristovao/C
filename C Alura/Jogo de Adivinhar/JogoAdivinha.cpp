#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//constante -> define é uma diretiva
//#define NUMERO_DE_TENTATIVAS 5


//Ep. F23 ---> tipos de dados ---> short, int, long, float and double
//Ep. F25 ---> abs
//Ep. F26 ---> rand and time.h

int main(void){
	
	printf("************************************\n");
	printf("* Bem vindo ao jogo de adivinhacao *\n");
	printf("************************************\n");
	
	int segundos = time(0);
	srand(segundos);
	int numeroGrande = rand();
	
	int numeroSecreto = numeroGrande % 100, chute;
	int ganhou = 0;
	int tentativas = 1;
	float pontos = 1000, pontosPerdidos = 0;
	
	int nivel;
	int numeroDeTentativas;
	
	do{
		printf("\nQual o nivel da dificuldade?\n");
		printf("(1) Facil (2) Media (3) Dificil\n");
		printf("Escolha: ");
		scanf("%d", &nivel);
		
		if(nivel == 1){
			numeroDeTentativas = 20;
			printf("Dificuldade: Facil!\n");
		} else if ( nivel == 2) {
			numeroDeTentativas = 15;
			printf("Dificuldade: Media!\n");
		} else if ( nivel == 3) {
			numeroDeTentativas = 6;
			printf("Dificuldade: Dificil!\n");
		} else {
			printf("\nVoce escolheu um nivel invalido!\nTente novamente com umas das opcoes do menu...\n");
			printf("---------------\n");
		}
	
	}	while( nivel < 1 || nivel > 3);
	
	for(int i = 0 ; i < numeroDeTentativas; i++){
		
		printf("\n---------------\n| Tentativa %d |\n---------------\nEscolha entre 0 a 100\n", tentativas);
		printf("Qual eh o seu chute: ");
		scanf("%d", &chute);
		//printf("Seu chute foi: %d\n", chute);
		
		if(chute < 0) {
			printf("Voce nao pode chutar numeros negativo.");
			
			continue; // pula para o proximo loop
		}
		
		int acertou = ( numeroSecreto == chute);
		int maior = ( chute > numeroSecreto );
		
		if( acertou ){
			printf("--> Parabens! Voce ganhou!\n");
			printf("Continue jogando... voce eh um bom jogador!\n");
			ganhou = 1;
			
			if(tentativas == 1)
				printf("\nVoce acertou em 1 tentativa");
			else
				printf("\nVoce acertou em %d tentativas", tentativas);
			
			break; //acaba com o loop
		} else if( maior ){
			printf("--> Seu chute foi maior que o numero secreto\n");
		} else {
			printf("--> Seu chute foi menor que o numero secreto\n");
		}
		
		tentativas++;
		
		float pontosPerdidos = abs( chute - numeroSecreto ) / (float)2;
		pontos -= pontosPerdidos;
	}
	
	if( ganhou != 1 ) {
		printf("\nVoce perdeu! Tente de novo...");
		printf("\nO numero secreto era %d.", numeroSecreto);
	}
	
	printf("\nTotal de pontos: %.2f", pontos);
	printf("\nFim de jogo!");
	
		
	return 0;
}
