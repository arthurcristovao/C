#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define MAX_TXT 30

struct lde {
	struct lde* ant;
	char texto[MAX_TXT];
	struct lde* prox;
};
typedef struct lde LDE;
LDE* historicoAtual = NULL;


LDE* cria_lde()
{
	return NULL;
}

void destroi_lde()
{

}

bool inserir(char* url)
{


}

void definePaginaInicial(char* url)
{

}

void visitar(char* url)
{
//	printf("visitando %s \n", url);

}

char* voltar(int qtd)
{
//	printf("voltar %d\n", qtd);
	
}

char* avancar(int qtd)
{
//	printf("avancar %d\n", qtd);

}

bool comparar(char* url)
{
	if (historicoAtual== NULL)
		return false;
//	printf("comparando %s == %s \n",historicoAtual->texto, url);
	return strcmp(historicoAtual->texto, url)==0;
}

int main(int argc, char *argv[]) {
	system("pause");
	printf("TESTE DE PAGINA INICIAL!\n");
	{
		// Caso 1: Inserção com sucesso
		cria_lde();
	    char* url1 = "#@$!@^#";
	    definePaginaInicial(url1);
	    assert(comparar(url1));
	    destroi_lde();
	
	    // Caso 2: Lista vazia
	    cria_lde();
	    char* url2 = "http://google.com.br";
	    definePaginaInicial(url2);
	    assert(comparar(url2));
	    destroi_lde();    
	}
	
	{
		
	    cria_lde();
	    char* url1 = "google.com";
	    definePaginaInicial(url1);
	    char url2[5][20] = {"g1.com", "g2.com", "g3.com", "g4.com", "g5.com" };
	    int i;
	    // NAVEGACAO 
	    printf("TESTE DE NAVEGACAO!\n");
	    for (i = 0; i < 5; i++)
	    {
	    	visitar(url2[i]);
	    	assert(comparar(url2[i]));
		}
		// VOLTAR 
		printf("TESTE DE VOLTAR!\n");
	    for (i = 4; i >= 0; i--)
	    {
	    	
	    	assert(comparar(url2[i]));
	    	voltar(1);
		}
		// AVANCAR 
		printf("TESTE DE AVANCAR!\n");
	    for (i = 0; i < 5; i++)
	    {
	    	avancar(1);
	    	assert(comparar(url2[i]));	
		}
		// VOLTAR 
	    destroi_lde();
	}
	printf("TUDO CERTO!");
	return 0;
}
