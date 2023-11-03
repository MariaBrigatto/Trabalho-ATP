#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TF 500
int main()
{
	int  TLA=0, i, vCod[TF], j= 0, TLD= 0, cod= 0;
	char op, nome[30], vAluno[TF][30],vRA[TF][15], RA[15], vDisciplina[15][TF];
	
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
				printf("digite o codigo da disciplina\n");
				scanf("%d", &cod);	
				while(cod != 0)//meu 'j' é minha variavel de controle
				{
					j= 0;
					while(j< TLD && cod!= vCod[j])
						j++;	
					if(j== TLD)
					{
						printf("digite o nome da disciplina\n");
						fflush(stdin);
						strupr(gets(vDisciplina[TLD]));
						vCod[TLD]= cod;
			 			TLD++;
					}	
					else
						printf("Numero encontrado\n");
					printf("digite o codigo da disciplina\n");
					scanf("%d", &cod);
				}
				break;
				
			case 'C':
				break;
		}
	
	
	}while(op != 27);
	
	
	
}
