#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TF 5
int main()
{
	int vCod[TF], j= 0, TLD= 0, cod= 0;
	char vDisciplina[15][TF]; 
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
}
