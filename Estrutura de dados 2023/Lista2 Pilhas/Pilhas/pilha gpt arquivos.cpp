#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct {
   int items[MAX_SIZE];
   int top;
} Stack;

// Inicializa a pilha
void init(Stack *stack) {
   stack->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(Stack *stack) {
   return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFull(Stack *stack) {
   return stack->top == MAX_SIZE - 1;
}

// Adiciona um elemento à pilha
void push(Stack *stack, int item) {
   if (isFull(stack)) {
      printf("Erro: pilha cheia\n");
      return;
   }
   stack->items[++stack->top] = item;
}

// Remove um elemento da pilha
int pop(Stack *stack) {
   if (isEmpty(stack)) {
      printf("Erro: pilha vazia\n");
      exit(1);
   }
   return stack->items[stack->top--];
}

// Salva a pilha em um arquivo de texto
void save(Stack *stack) {
   FILE *arquivo;
   int i;

   arquivo = fopen("pilha.txt", "w");
   if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo\n");
      exit(1);
   }

   fprintf(arquivo, "%d\n", stack->top + 1);
   for (i = stack->top; i >= 0; i--) {
      fprintf(arquivo, "%d\n", stack->items[i]);
   }

   fclose(arquivo);
}

// Pega a inserção do usuário e adiciona à pilha
void add(Stack *stack) {
   int item;
   printf("Insira um número: ");
   scanf("%d", &item);
   push(stack, item);
}

int main() {
   Stack stack;
   int opcao;

   init(&stack);

   do {
      printf("\n1 - Adicionar a pilha\n");
      printf("2 - Remover da pilha\n");
      printf("3 - Salvar a pilha\n");
      printf("4 - Sair\n");

      printf("Escolha uma opção: ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            add(&stack);
            break;
         case 2:
            printf("%d removido\n", pop(&stack));
            break;
         case 3:
            save(&stack);
            printf("Pilha salva em pilha.txt\n");
            break;
         case 4:
            printf("Saindo...\n");
            break;
         default:
            printf("Opção inválida\n");
            break;
      }

   } while (opcao != 4);

   return 0;
}

