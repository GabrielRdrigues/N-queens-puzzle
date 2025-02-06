/* 
Se tenho uma rainha na linha i, então linha i está bloqueada
Se tenho uma rainha na coluna j, então coluna j está bloqueada
Se tenho uma rainha na posição (i,j), então (i,j) + o vetor (k,l) para k,l -n até n


((i,j),_._,_,_,_,_,_)
*/

int cont=0; /* VARIÁVEL GLOBAL PARA CONTAR O NÚMERO TOTAL DE COMBINAÇÕES DE RAINHAS */

struct Pqueen
{
	int x;
	int y;
};
typedef struct Pqueen queen;

#include <stdio.h>
#include <stdlib.h>


int VerificaDiagonais(queen* vet,int n,int pos)
{
	int i,j,k,row,col;
	for(i=0;i<pos;i++)
	{
			/*o if abaixo verifica se duas rainhas estão na mesma diagonal*/
			if(pos!=i)
			{
				if(abs(vet[pos].x - vet[i].x) == abs(vet[pos].y - vet[i].y))
					{
						return 1; /* Tem colisão */
					}
			}
	}
	return 0; // Não tem colisão
}

int VerificaLinhas(queen* vet,int n,int linha)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(vet[i].x == linha)
		{
			return 1; // Linha ocupada
		}
	}
	return 0; // Linha livre
}

void nRainhas(queen* vet,int pos,int n)
{
	int i;
	if(pos==n)
	{
		cont++;
		for(i=0;i<n;i++)
		{
			printf("(%d,%d) ",vet[i].x,vet[i].y);
		}
		puts("");
	}
	else
	{
		vet[pos].y=pos;
		for(i=0;i<n;i++)
		{
			vet[pos].x=i;
			if(!VerificaDiagonais(vet,n,pos) && !VerificaLinhas(vet,pos,i))
			{	
				nRainhas(vet,pos+1,n);
			}
		}
	}
}

int main()
{
	queen* vet = (queen*)malloc(sizeof(queen)*20);
	nRainhas(vet,0,8);
	free(vet);
	printf("\n Número de combinações [%d] \n",cont);
}
