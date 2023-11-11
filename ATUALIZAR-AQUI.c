#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> // biblioteca pra limpar a tela :)
#define TF 500
int main()
{
	int  TLA=0, i, j= 0, TLD= 0, TLN= 0, controle, e = 0;
	float  vNota1[TF], vNota2[TF];
	char  op, nome[30], vAluno[TF][30],vRA[TF][15], RA[15], vDisciplina[TF][30], cod[15], vCod[TF][30], vRA_mat[TF][30], vCod_mat[TF][30];		
	
	do {
		
		printf("----------------------------\n");
		printf(" **** SISTEMA ****");
		printf("\n----------------------------\n");
		printf("\n Cadastro de Aluno [A]\n");
		printf(" Cadastro de Disciplina [B]\n");
		printf(" Lancar Notas [C]\n");
		printf(" Excluir Aluno [D]\n");
		printf(" Relatorio de Notas [E]\n");
		printf(" Relatorio Alunos Aprovados [F]\n");
		printf(" Relatorio Alunos Reprovados [G]\n");
		printf(" Sair [S]\n");
		printf("\n Digite a opcao abaixo:\n ");
		fflush(stdin);
		scanf("%c",&op);
		op = toupper(op);
		
		printf("\n----------------------------\n\n");
	
		system("cls"); // LIMPA A TELA DO MENU  *MENOS POLUIÇÃO VISUAL
		switch(op) {
			
			case 'A': // CADASTRO DE ALUNO
			
				printf(" **** CADASTRO DE ALUNOS ****\n\n");		
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
					
				} else { // NAO ACHOU | CADASTRO
					
					printf("Informe o nome do aluno:\n");
					fflush(stdin);
					gets(nome);
					strcpy(vAluno[TLA], nome);
					
					strcpy(vRA[TLA], RA);
						
					TLA++;
				
				}	
						
				break;


			case 'B': //CADASTRO DE DISCIPLINAS
				
				printf(" **** CADASTRO DE DISCIPLINAS ****\n\n");
				printf("Digite o codigo da disciplina:\n");
				fflush(stdin);
				gets(cod);
				
			
					j= 0;
					
					
					while(j < TLD && strcmp(vCod[j],cod) != 0) // BUSCA DO COD
						j++;	
						
						
					if(j == TLD) // NÃO ACHOU | CADASTRO 
					{
						printf("Digite o nome da disciplina:\n");
						fflush(stdin);
						gets(vDisciplina[TLD]);
						strcpy(vCod[TLD], cod);
			 			TLD++;
					}	
					else // ACHOU
					{
						printf(" ** Disciplina Cadastrada **\n");
						printf("Codigo: %s\n",vCod[j]);
						printf("Disciplina: %s\n\n",vDisciplina[j]);
					
					}
				
				break;
				
				
			case 'C': //LANÇAR NOTAS
				printf(" **** LANCAMENTO DE NOTAS ****\n\n");
				printf("Informe o RA:\n");
				fflush(stdin);
				gets(RA);
				
				i=0;
				while(i < TLA && strcmp(vRA[i],RA) != 0)  // BUSCA DO RA
					i++;
					
				if(i < TLA) { // ACHOU
				
					printf(" \n**** ALUNO ****\n");
					printf("\nRA: %s\n", vRA[i]);
					printf("Aluno: %s\n\n",vAluno[i]);
				
					printf("Informe o codigo da disciplina:\n");
					fflush(stdin);
					gets(cod);
					
					j=0;
					while(j < TLD && strcmp(vCod[j],cod) != 0) // BUSCA DA DISCIPLINA 
						j++;
				
					if( j < TLD) { // ACHOU
						
						printf(" \n**** DISCIPLINA ****\n");	
						printf("Codigo: %s\n",vCod[j]);
						printf("Disciplina: %s\n\n",vDisciplina[j]);
						
						i = 0;
						controle = 0; // VARIAVEL PARA QUEBRAR A REPETIÇÃO !
						
						while(i < TLN && controle != 1) 
						{
							if(strcmp(vRA_mat[i],RA)==0 && strcmp(vCod_mat[i],cod)==0) // ACHOU NA POSIÇÃO i, LOGO, NOTA JA LANÇADA!
								controle = 1; // QUEBRA DA CONDIÇÃO (WHILE)
							else
								i++; // NAO ACHOU, ACRESCENTO +1!
						}
							
						if(i < TLN) { // ACHOU
							printf("\n **** NOTA JA CADASTRADA ****\n\n");
							printf("\n **** NOTA 1 : %f ",vNota1[i]);
							printf("\n **** NOTA 2 : %f ",vNota2[i]);
						}
						else {
							
							printf("Insira a nota do primeiro bimestre:\n");
							scanf("%f",&vNota1[TLN]);                        
							
							printf("Insira a nota do segundo bimestre:\n");
							scanf("%f",&vNota2[TLN]);
							
							strcpy(vRA_mat[TLN],RA);         // ACRESCENTA NO VETOR DE CONTROLE DE RA QUE A NOTA JA FOI LANÇADA
							strcpy(vCod_mat[TLN],cod);       // IDEM PARA O VETOR DE CONTROLE DE DISCIPLINA 
							
							TLN++;
				
						}
					}
					else
						printf(" ** DISCIPLINA NAO ENCONTRADA **\n\n");	// NAO ACHOU
				}
				else
					printf("\n ** ALUNO NAO ENCONTRADO **\n\n"); // NAO ACHOU
					
			
				break;
				
				
			case 'D': //EXCLUSÃO
				
				printf("**** EXCLUSAO DE ALUNO ****\n\n");
				printf("Informe o RA:\n");
				fflush(stdin);
				gets(RA);
				
				i = 0;
				
					while(i < TLA && strcmp(vRA[i], RA) != 0) 	// BUSCA DO RA
						i++;
						
					if(i < TLA) { //ACHOU 
							
							for(i = i; i < TLA - 1; i++) { // REMANEJAMENTO DO RA (EXCLUSÃO)
								
								strcpy(vRA[i], vRA[i+1]);
								strcpy(vAluno[i], vAluno[i+1]);
								
							}
							for(i = 0; i < TLN; i++) { 
														
								if(strcmp(vRA_mat[i], RA) == 0) {
									
									for( e = i; e < TLN - 1 ; e++) { //// REMANEJAMENTO DAS NOTAS NO VETOR DE CONTROLE (EXCLUSÃO) || "e" VARIAVEL DE CONTROLE NOVA!
																									
										vNota1[e] = vNota1[e+1];
										vNota2[e] = vNota2[e+1];
										strcpy(vRA_mat[e], vRA_mat[e+1]);
										strcpy(vCod_mat[e], vCod_mat[e+1]);
									
									}
									
								TLN--;
									
								}
								
							printf("\n **** EXCLUSAO CONCLUIDA! ****\n\n");	
								
							}
								
								TLA --;
								
						}
						else
							printf("\n **** ALUNO NAO ENCONTRADO! **** \n\n"); //NAO ACHOU!
					
				
					
															
					break;
					
			
			case 'E':
				break;
				
				
			case 'F':
				break;
				
				
			case 'G':
				break;
				
				
			default: printf("\n **** OPERACAO INVALIDA/FINALIZADA! ****\n\n");
		}
	
	
	}while(op != 'S');
	

	return 0;
	
}
