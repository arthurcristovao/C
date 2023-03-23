
#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main(){
    struct Produto produtos[5];

    for (int i = 0; i < 5; i++){
        printf("Insira o nome do produto: \n");
        scanf("%s", produtos[i].nome);

        printf("Insira o preco do produto: \n");
        scanf("%f", &produtos[i].preco);

        printf("Insira a quantidade do produto: \n");
        scanf("%d", &produtos[i].quantidade);
    }

    for (int i = 0; i < 5; i++){
        printf("Produto %d: \n", i+1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }

    return 0;
}
