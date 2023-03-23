#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "JogoDaForca.h"

	char palavraSecreta[TAMANHO_PALAVRA];
	char chutes[26];
	int chutesDados = 0;

//Ep. F42 funções

void abertura(){
	printf("*******************************\n");
	printf("*        Jogo da Forca        *\n");
	printf("*******************************\n\n");
}

void chuta(){ //recebendo o endereço a da variavel
	char chute;
	fflush(stdin);
	scanf("%c", &chute);
	 
	chutes[chutesDados] = chute;
	chutesDados++;
	
}

int jaChutou(char letra){
	int achou = 0;
			
	for(int j = 0; j < chutesDados; j++){
		if(chutes[j] == letra){
			achou = 1;
			break;
		}
	}
	
	return achou;
}

void desenhaForca(){
	
	int erros = chutesErrados();
	
	printf(" _________			\n");	
	printf(" |/       |			\n");
	printf(" |       %c%c%c		\n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
	printf(" |       %c%c%c		\n", (erros >= 3 ? '\\' : ' '), ( erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
	printf(" |        %c		\n", (erros >= 2 ? '|' : ' '));
	printf(" |       %c %c		\n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
	printf(" |   				\n");
	printf("_|___				\n");
	printf("\n\n");
	
	for(int i = 0; i < strlen(palavraSecreta); i++){
			
		int achou = jaChutou(palavraSecreta[i]);
		
		if(achou) {
			printf("%c ", palavraSecreta[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void adicionaPalavra(){
	char quer;
	
	printf("Voce quer adicionar uma nova palavra no jogo? (S/N)");
	fflush(stdin);
	scanf("%c", &quer);
	
	if(quer == 'S') {
		char novaPalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra? ");
		scanf("%s", novaPalavra);
		
		FILE* f;
		
		f = fopen("palavras.txt", "r+");
		if( f == 0) { 
			printf("Desculpe, banco de dados nao disponivel\n\n");
			exit(1);
		}
		
		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;
		
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);
		
		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novaPalavra);
		
		fclose(f);
		
	}
}

void escolhePalavra(){
	FILE* f;
	
	f = fopen("palavras.txt", "r");
	if( f == 0) { 
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
	}
	
	int qtdDePalavras;
	fscanf(f, "%d", &qtdDePalavras);
	
	srand(time(0));
	int randomico = rand() % qtdDePalavras;
	
	for( int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavraSecreta);
	}
	
	fclose(f);
}

int chutesErrados(){
	int erros = 0;
	
	for( int i = 0; i < chutesDados; i++) {
		int existe = 0;
		
		for( int j = 0; j < strlen(palavraSecreta); j++){ 
			if(chutes[i] == palavraSecreta[j]) {
				existe = 1;
				break;
			}
		}
		if(!existe) erros++;
	}
	
	return erros;
}

int enforcou() {
	
	return chutesErrados() >= 5;
}

int acertou(){
	
	for(int i = 0; i < strlen(palavraSecreta); i++ ) {
		if(!jaChutou(palavraSecreta[i])){
			return 0;
		}
	}
	return 1;
}

int main(){
	escolhePalavra();
	abertura();
	
	do {
		
		desenhaForca();
		chuta();
				
	} while(!acertou() && !enforcou());
	
	if(acertou()){
		printf("\nParabens! Voce ganhou!\n");
		printf("     _______________	\n");
		printf("    |@@@@|     |####|	\n");
		printf("    |@@@@|     |####|	\n");
		printf("    |@@@@|     |####|	\n");
		printf("    \\@@@@|     |####/	\n");
		printf("     \\@@@|     |###/	\n");
		printf("      `@@|_____|##'		\n");
		printf("           (O)			\n");
		printf("        .-'''''-.		\n");
		printf("      .'  * * *  `.		\n");
		printf("     :  *       *  :	\n");
		printf("    : ~ A S C I I ~ :	\n");
		printf("    : ~ A W A R D ~ :	\n");
		printf("     :  *       *  :	\n");
		printf("      `.  * * *  .'		\n");
		printf("        `-.....-'		\n");	
		
	} else {
		printf("\nNao foi dessa vez, tente novamente!\n");
		printf("  		 ...										\n");
		printf("               ;::::;								\n");
		printf("             ;::::; :;								\n");
		printf("           ;:::::'   :;								\n");
		printf("          ;:::::;     ;.							\n");
		printf("         ,:::::'       ;           OOO\\			\n");
		printf("         ::::::;       ;          OOOOO\\			\n");
		printf("         ;:::::;       ;         OOOOOOOO			\n");
		printf("        ,;::::::;     ;'         / OOOOOOO			\n");	
		printf("      ;:::::::::`. ,,,;.        /  / DOOOOOO		\n");
		printf("    .';:::::::::::::::::;,     /  /     DOOOO		\n");
		printf("   ,::::::;::::::;;;;::::;,   /  /        DOOO		\n");	
		printf("  ;`::::::`'::::::;;;::::: ,#/  /          DOOO		\n");
		printf("  :`:::::::`;::::::;;::: ;::#  /            DOOO	\n");
		printf("  ::`:::::::`;:::::::: ;::::# /              DOO	\n");
		printf("  `:`:::::::`;:::::: ;::::::#/               DOO	\n");
		printf("   :::`:::::::`;; ;:::::::::##                OO	\n");
		printf("   ::::`:::::::`;::::::::;:::#                OO	\n");
		printf("   `:::::`::::::::::::;'`:;::#                O		\n");
		printf("    `:::::`::::::::;' /  / `:#						\n");
		printf("     ::::::`:::::;'  /  /   `#						\n");
	}
	
	return 0;
}
