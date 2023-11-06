#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TF 500
int main()
{
	int  TLA=0, i, j= 0, TLD= 0;
	char op, nome[30], vAluno[TF][30],vRA[TF][15], RA[15], vDisciplina[TF][30], cod[15], vCod[TF][30];
	
		printf(" **** SISTEMA ****\n");
	
	do {
		
		printf("\nCadastro de Aluno [A]\n");
		printf("Cadastro de Disciplina [B]\n");
		printf("Lancar Notas [C]\n");
		printf("Excluir Aluno [D]\n");
		printf("Relatorio de Notas [E]\n");
		printf("Relatorio Alunos Aprovados [F]\n");
		printf("Relatorio Alunos Reprovados [G]\n");
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
				
				printf("Digite o codigo da disciplina:\n");
				fflush(stdin);
				gets(cod);
				
			
					j= 0;
					
					
					while(j < TLD && strcmp(vCod[j],cod) != 0)
						j++;	
						
						
					if(j == TLD)
					{
						printf("Digite o nome da disciplina:\n");
						fflush(stdin);
						gets(vDisciplina[TLD]);
						strcpy(vCod[TLD], cod);
			 			TLD++;
					}	
					else
					{
						printf(" ** Disciplina Cadastrada **\n");
						printf("Codigo: %s\n",vCod[j]);
						printf("Disciplina: %s\n\n",vDisciplina[j]);
					
					}
				break;
				
				
			case 'C':
				break;
				
				
			case 'D':
				break;
				
			
			case 'E':
				break;
				
				
			case 'F':
				break;
				
				
			case 'G':
				break;
				
			
		}
	
	
	}while(op != 27);
	
	return 0;
	
}
