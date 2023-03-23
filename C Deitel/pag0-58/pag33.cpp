#include <stdio.h>

int main(void){
	int num1, num2, resto;
	
	printf("Entre com dois inteiros e eu lhe direi\n");
	printf("as relacoes que eles satisfazem: ");
	
	scanf("%d%d", &num1, &num2);
	
	if(num1 == num2)
		printf("%d eh igual a %d\n", num1, num2);
	
	if(num1 != num2)
		printf("%d eh diferente a %d\n", num1, num2);
		
	if(num1 < num2)
		printf("%d eh menor que %d\n", num1, num2);
	
	if(num1 > num2)
		printf("%d eh maior que %d\n", num1, num2);
		
	if(num1 <= num2)
		printf("%d eh menor ou igual a %d\n", num1, num2);
		
	if(num1 >= num2)
		printf("%d eh maior ou igual a %d\n", num1, num2);
	
	return 0;
}
