#include <stdio.h>
#include <stdlib.h>

void teste(int* x){
	
	*x = 3;
	
}

int main(void) 
{
	int x = 10;
	
	printf("x = %d\n", x);
	teste( &x );
	printf("x = %d\n", x); //faça x valer 3 

}
