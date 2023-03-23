#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    int topo;
    int capacidade;
    int *dados; //endereço de memoria
} Pilha;
 	
Pilha* criar_pilha(int capacidade)
{
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->dados = (int*) malloc(pilha->capacidade * sizeof(int));
    return pilha;
}

int pilha_cheia(Pilha *pilha)
{
    return (pilha->topo == pilha->capacidade - 1);
}

int pilha_vazia(Pilha *pilha)
{
    return (pilha->topo == -1);
}

void empilhar(Pilha *pilha, int item)
{
    if (pilha_cheia(pilha))
        return;
    pilha->dados[++pilha->topo] = item;
    printf("%d empilhado com sucesso!\n", item);
}

int desempilhar(Pilha *pilha)
{
    if (pilha_vazia(pilha))
        return -1;
    return pilha->dados[pilha->topo--];
}

void imprimir_pilha(Pilha *pilha)
{
    if (pilha_vazia(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elementos da pilha: ");
    int i;
    for (i = 0; i <= pilha->topo; i++)
        printf("%d ", pilha->dados[i]);
    printf("\n");
}

int main() 
{
    Pilha* pilha1 = criar_pilha(5);
    empilhar(pilha1, 10);
    empilhar(pilha1, 20);
    empilhar(pilha1, 30);
    empilhar(pilha1, 40);
    //imprimir_pilha(pilha1);
    int x = desempilhar(pilha1);
    printf("Elemento desempilhado: %d\n", x); 
    //imprimir_pilha(pilha1);
    return 0;
}
