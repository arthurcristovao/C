#include <stdio.h>

struct card {
	char *face;
	char *suit;
};

int main(){
	
	struct card aCard; //declara uma variavel struct card
	struct card *cardPtr; //declara ponteiro para uma struct card
	
	// coloca strings em aCard
	aCard.face = "As";
	aCard.suit = "Espadas";
	
	cardPtr = &aCard; //atribui o endereço de aCard a cardPtr
	
	printf("%s%s%s\n%s%s%s\n%s%s%s\n", 	aCard.face, " de ", aCard.suit, 
										cardPtr->face, " de ", cardPtr->suit,
										(*cardPtr).face, " de ", (*cardPtr).suit);
	
	return 0;
}
