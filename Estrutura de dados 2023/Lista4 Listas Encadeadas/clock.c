#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
 
// função principal para encontrar o tempo de execução de um programa em C
int main()
{
    // para armazenar o tempo de execução do código
    double time_spent = 0.0;
 
    clock_t begin = clock();
 
    //faz algumas coisas aqui
    sleep(3);
 
    clock_t end = clock();
 
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
 
    return 0;
}
