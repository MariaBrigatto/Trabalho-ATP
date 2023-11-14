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
		printf(" Registros [H]\n");
		printf(" Sair [S]\n");
		printf("\n Digite a opcao abaixo:\n ");
		fflush(stdin);
		scanf("%c",&op);
		op = toupper(op);
		
		printf("\n----------------------------\n\n");
	
		system("cls"); // LIMPA A TELA DO MENU  *MENOS POLUIÃ‡ÃƒO VISUAL
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
						
						
					if(j == TLD) // NÃƒO ACHOU | CADASTRO 
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
				
				
			case 'C': //LANÃ‡AR NOTAS
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
						controle = 0; // VARIAVEL PARA QUEBRAR A REPETIÃ‡ÃƒO !
						
						while(i < TLN && controle != 1) 
						{
							if(strcmp(vRA_mat[i],RA)==0 && strcmp(vCod_mat[i],cod)==0) // ACHOU NA POSIÃ‡ÃƒO i, LOGO, NOTA JA LANÃ‡ADA!
								controle = 1; // QUEBRA DA CONDIÃ‡ÃƒO (WHILE)
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
							
							strcpy(vRA_mat[TLN],RA);         // ACRESCENTA NO VETOR DE CONTROLE DE RA QUE A NOTA JA FOI LANÃ‡ADA
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
				
				
			case 'D': //EXCLUSÃƒO
				
				printf("**** EXCLUSAO DE ALUNO ****\n\n");
				printf("Informe o RA:\n");
				fflush(stdin);
				gets(RA);
				
				i = 0;
				
					while(i < TLA && strcmp(vRA[i], RA) != 0) 	// BUSCA DO RA
						i++;
						
					if(i < TLA) { //ACHOU 
						
						printf("Excluir [RA: %s | Aluno: %s ] [S|N]\n",vRA[i],vAluno[i]); // CONFIRMAÃ‡ÃƒO DE EXCLUSÃƒO
						fflush(stdin);
						scanf("%c",&op);
						op = toupper(op);
						
						if(op == 'S') {
							
							for(i = i; i < TLA - 1; i++) { // REMANEJAMENTO DO RA (EXCLUSÃƒO)
								
								strcpy(vRA[i], vRA[i+1]);
								strcpy(vAluno[i], vAluno[i+1]);
								
							}
							for(i = 0; i < TLN; i++) { 
														
								if(strcmp(vRA_mat[i], RA) == 0) {
									
									for( e = i; e < TLN - 1 ; e++) { //// REMANEJAMENTO DAS NOTAS NO VETOR DE CONTROLE (EXCLUSÃƒO) || "e" VARIAVEL DE CONTROLE NOVA!
																									
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
				printf("\tlistagem de nota\n");
				for(i=0;i<TLA;i++)
				{
					printf("Aluno:  %s - %s\n",vRA[i],vAluno[i]);
					for(j=0;j<TLN;j++)
						if(strcmp(vRA[i],vRA_mat[j])==0)
						{
							e=0;
							while(strcmp(vCod_mat[j],vCod[e])!=0)
								e++;
							printf("disciplina: %s - %s     nota 1 : %.2f   nota 2 : %.2f   media : %.2f\n", vCod[e], vDisciplina[e], vNota1[j], vNota2[j], (vNota1[j]+vNota2[j])/2);	
						}
					printf("\n");
				}
				getch();
				break;
				
				
			case 'F':
				e=0;
			 	printf(" Relatorio Alunos Aprovados [F]\n");
                printf("Digite o codigo da disciplina : \n");
                fflush(stdin);
                gets(nome);
               	while(e<TLD&& strcmp(nome, vCod[e]))
               		e++;
                for(i=0;i<TLN;i++)
                {
                    if(strcmp(nome,vCod_mat[i])==0)
                    {
                        if((vNota1[i]+vNota2[i])/2>=6)
                        {
                            j=0;
                            while(j<TLA && strcmp(vRA_mat[i],vRA[j])!=0)
                                j++;
                            printf("O aluno %s foi aprovado com media = %.2f na disciplina %s\n",vAluno[j],(vNota1[i]+vNota2[i])/2,vDisciplina[e]);
                        }
                    }
                }

                getch();
                break;
			case 'G':
				e=0;
				printf(" Relatorio Alunos Reprovados[G]\n");
                printf("Digite o codigo da disciplina : \n");
                fflush(stdin);
                gets(nome);
               	while(e<TLD&& strcmp(nome, vCod[e]))
               		e++;
                for(i=0;i<TLN;i++)
                {
                    if(strcmp(nome,vCod_mat[i])==0)
                    {
                        if((vNota1[i]+vNota2[i])/2<6)
                        {
                            j=0;
                            while(j<TLA && strcmp(vRA_mat[i],vRA[j])!=0)
        		         j++;
                            printf("O aluno %s foi reprovado com media = %.2f na disciplina %s\n",vAluno[j],(vNota1[i]+vNota2[i])/2,vDisciplina[e]);
                        }
                    }
                }
				break;
				
			case 'H':
				
				strcpy(vRA[TLA],"1111");
				strcpy(vAluno[TLA],"Joao");
				TLA++;
				
				strcpy(vRA[TLA],"2222");
				strcpy(vAluno[TLA],"Gabriel");
				TLA++;
				
				strcpy(vCod[TLD],"10");
				strcpy(vDisciplina[TLD],"calculo I");
				TLD++;
				
				strcpy(vCod[TLD],"20");
				strcpy(vDisciplina[TLD],"calculo II");
				TLD++;
				
				strcpy(vCod[TLD],"30");
				strcpy(vDisciplina[TLD],"ATP I");
				TLD++;
				
				strcpy(vRA_mat[TLN],"1111");
				strcpy(vCod_mat[TLN],"10");
				vNota1[TLN]=5.6;
				vNota2[TLN]=7.4;
				TLN++;
				
				strcpy(vRA_mat[TLN],"1111");
				strcpy(vCod_mat[TLN],"20");
				vNota1[TLN]=7;
				vNota2[TLN]=4;
				TLN++;
				
				strcpy(vRA_mat[TLN],"1111");
				strcpy(vCod_mat[TLN],"30");
				vNota1[TLN]=8;
				vNota2[TLN]=10;
				TLN++;
				
				strcpy(vRA_mat[TLN],"2222");
				strcpy(vCod_mat[TLN],"10");
				vNota1[TLN]=8;
				vNota2[TLN]=7.4;
				TLN++;
				
				strcpy(vRA_mat[TLN],"2222");
				strcpy(vCod_mat[TLN],"20");
				vNota1[TLN]=4.4;
				vNota2[TLN]=5.6;
				TLN++;
				
				strcpy(vRA_mat[TLN],"2222");
				strcpy(vCod_mat[TLN],"30");
				vNota1[TLN]=9;
				vNota2[TLN]=4.1;
				TLN++;
				break;
				
				
			default: printf("\n **** OPERACAO INVALIDA/FINALIZADA! ****\n\n");
		}
	
	
	}while(op != 'S');

	return 0;
	
}
