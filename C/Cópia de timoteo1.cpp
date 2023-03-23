#include <stdlib.h>
#include <stdio.h>




int main(){
	
	int opcao, i = 0,contLinhas = 0 ;
	char dados[1000][100], procuraNome[20];
	
	
	FILE *txt;

	if((txt = fopen("arquivo.txt","w+")) == NULL)
        printf("Erro ao abrir arquivo");
    
    	while(!feof(txt)){
    		contLinhas++;
    		fscanf(txt, " %s", dados[contLinhas][0]);
    		fprintf(txt, "%s ", dados[contLinhas][0]);
		}
    
    fclose(txt);
    
	
	do{
		printf("1 - Novo Registro\n");
		printf("2 - Salvar todos no arquivo TXT\n");
		printf("3 - Pesquisar Nome de Aluno\n");
		printf("0 - SAIR\n");
		printf("DIGITE: ");
		scanf("%d", &opcao);
		
		
		if(opcao == 1){
			
				contLinhas++;
				
				printf("Digite o Nome e o Email do Usuario: \n");
				scanf(" %s", &dados[contLinhas][0]);
				fflush(stdin);
		
		
		} else if(opcao == 2){
			
				if((txt = fopen("arquivo.txt","w+")) == NULL)
        		printf("Erro ao abrir arquivo");
    			
    			
    			while(!feof(txt)){
    				i++;
    				fprintf(txt, "%s", dados[i][0]);
				}
    
    			fclose(txt);
			
		} else if(opcao == 3){
			
		}
		
		 
		
	}while(opcao!=0);

	
	return 0;
}
