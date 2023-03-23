#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck( Card* const wDeck, const char* wFace[], const char* wSuit[] );
void shuffle( Card* const wDeck );
void deal( const Card* const wDeck );

int main(void){
	Card deck[ 52 ]; //declara o array de cartas
	
	//inicializa o array de ponteiros
	const char *face[] = { "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
	
	//inicializa o array de ponteiros
	const char *suit[] = { "Copas", "Ouros", "Paus", "Espadas"};
	
	srand(time(0));
	
	fillDeck( deck, face, suit);
	shuffle( deck );
	deal( deck );
	
	return 0;
}

void fillDeck( Card* const wDeck, const char * wFace[], const char * wSuit[] ){
	
	for(int i = 0 ; i < 52; i++){
		wDeck[ i ].face = wFace[ i % 13];
		wDeck[ i ].suit = wSuit[ i / 13];
	}
	
} 

void shuffle( Card * const wDeck ){
	int i, j;
	
	Card temp; //declara estrutura temporaria para trocar Cards
	
	for( i = 0 ; i < 52 ; i++ ){
		j = rand() % 52; //mantem um valor aleatorio ebtre 0-51
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}	
}

void deal(const Card * const wDeck){
	for( int i = 0 ; i < 52 ; i++){
		printf(" %5s de %-8s%s ", wDeck[i].face, wDeck[i].suit, ( i + 1 ) % 4 ? " " : "\n");
	}
}


