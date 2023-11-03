#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TF 500
int main()
{
	int  TLA=0, i;
	char op, nome[30], vAluno[TF][30],vRA[TF][15], RA[15];
	
		printf(" **** SISTEMA ****\n");
	
	do {
		
		printf("\nCadastro de Aluno [A]\n");
		printf("Cadastro de Disciplina [B]\n");
		printf("Lancar Notas [C]\n");
		printf("\nDigite a opcao abaixo:\n");
		fflush(stdin);
		scanf("%c",&op);
		op = toupper(op);
		
		switch(op) {
			
			case 'A':
			
				printf("Informe o RA do aluno:\n");
				fflush(stdin);
				gets(RA);
				
				
				i=0;
				
				//BUSCA DO RA
				
				while(i < TLA && strcmp(vRA[i],RA) != 0) 
					i++;
						
				
				
				if(i < TLA) { // ACHOU
				
					printf("\n ** ALUNO JA CADASTRADO **\n");
					printf("RA: %s\n", vRA[i]);
					printf("Aluno: %s\n\n", vAluno[i]);
					
				} else { // NAO ACHOU
					
					printf("Informe o nome do aluno:\n");
					fflush(stdin);
					gets(nome);
					strcpy(vAluno[TLA], nome);
					
					strcpy(vRA[TLA], RA);
						
					TLA++;
					
				}
			
						
				break;
			
			case 'B':
				break;
				
			case 'C':
				break;
		}
	
	
	}while(op != 27);
	
	
	
}
