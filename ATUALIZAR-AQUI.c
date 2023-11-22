#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> // biblioteca pra limpar a tela :)
#define TF 500
int main()
{
	int  TLA=0, i, j,k, TLD= 0, TLM= 0, controle, e = 0;
	float  vNota1[TF], vNota2[TF], Media;
	char  op, nome[30], vAluno[TF][30],vRA[TF][15], RA[15], vDisciplina[TF][30], cod[15], vCod[TF][30], vRA_mat[TF][30], vCod_mat[TF][30];		
	
	do {
		
		printf("----------------------------\n");
		printf(" **** SISTEMA ****");
		printf("\n----------------------------\n");
		printf("\n[A] Cadastro de Aluno\n");
		printf("[B] Cadastro de Disciplina\n");
		printf("[C] Lancar Notas\n");
		printf("[D] Excluir Aluno\n");
		printf("[E] Relatorio de Notas\n");
		printf("[F] Relatorio Alunos Aprovados\n");
		printf("[G] Relatorio Alunos Reprovados\n");
		printf("[S] Sair\n");
		printf("\nDigite a opcao abaixo:\n");
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
						
						while(i < TLM && controle != 1) 
						{
							if(strcmp(vRA_mat[i],RA)==0 && strcmp(vCod_mat[i],cod)==0) // ACHOU NA POSIÇÃO i, LOGO, NOTA JA LANÇADA!
								controle = 1; // QUEBRA DA CONDIÇÃO (WHILE)
							else
								i++; // NAO ACHOU, ACRESCENTO +1!
						}
							
						if(i < TLM) { // ACHOU
							printf("\n **** NOTA JA CADASTRADA ****\n\n");
							printf("\n **** NOTA 1 : %f ",vNota1[i]);
							printf("\n **** NOTA 2 : %f ",vNota2[i]);
						}
						else {
							
							printf("Insira a nota do primeiro bimestre:\n");
							scanf("%f",&vNota1[TLM]);                        
							
							printf("Insira a nota do segundo bimestre:\n");
							scanf("%f",&vNota2[TLM]);
							
							strcpy(vRA_mat[TLM],RA);         // ACRESCENTA NO VETOR DE CONTROLE DE RA QUE A NOTA JA FOI LANÇADA
							strcpy(vCod_mat[TLM],cod);       // IDEM PARA O VETOR DE CONTROLE DE DISCIPLINA 
							
							TLM++;
				
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
						
						printf("Excluir [RA: %s | Aluno: %s ] [S|N]\n",vRA[i],vAluno[i]); // CONFIRMAÇÃO DE EXCLUSÃO
						fflush(stdin);
						scanf("%c",&op);
						op = toupper(op);
						
						if(op == 'S') {
							
							for(i = i; i < TLA - 1; i++) { // REMANEJAMENTO DO RA (EXCLUSÃO)
								
								strcpy(vRA[i], vRA[i+1]);
								strcpy(vAluno[i], vAluno[i+1]);
								
							}
							for(i = 0; i < TLM; i++) { 
														
								if(strcmp(vRA_mat[i], RA) == 0) {
									
									for( e = i; e < TLM - 1 ; e++) { //// REMANEJAMENTO DAS NOTAS NO VETOR DE CONTROLE (EXCLUSÃO) || "e" VARIAVEL DE CONTROLE NOVA!
																									
										vNota1[e] = vNota1[e+1];
										vNota2[e] = vNota2[e+1];
										strcpy(vRA_mat[e], vRA_mat[e+1]);
										strcpy(vCod_mat[e], vCod_mat[e+1]);
									
									}
									
								TLM--;
									
								}
								
							printf("\n **** EXCLUSAO CONCLUIDA! ****\n\n");	
								
							}
								
								TLA --;
								
						}
						else {
							
							if(op == 'N')
								printf("\n **** EXCLUSAO CANCELADA! ****\n\n");
							else
								printf("\n **** OPERACAO DESCONHECIDA! ****\n\n");
						}
						
						
					}
					else
						printf("\n **** ALUNO NAO ENCONTRADO! **** \n\n"); //NAO ACHOU!
					
															
					break;
					
			
			case 'E':
				printf("\n **** RELATORIO DE NOTAS ****\n\n");
				
				for(i = 0; i< TLA; i++) {
					printf("Aluno: %s - %s\n",vRA[i],vAluno[i]);
					for(j = 0; j < TLM; j++) {
						if(strcmp(vRA_mat[j],vRA[i]) == 0) {
							for(e = 0; e < TLD; e++) {
								if(strcmp(vCod_mat[j],vCod[e]) == 0) {
								
									printf("Disciplina: %s - %s   	Nota 1 = %.2f	Nota 2: %.2f	Media: %.2f\n\n",vCod_mat[j],vDisciplina[e],vNota1[j],vNota2[j],(vNota1[j]+vNota2[j])*2);
									printf("\n\n");
									
								}
								
							}
									
						}
						
					}
					
					
					
				}
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
