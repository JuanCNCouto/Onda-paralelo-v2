#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Wave.h"
#include "MAPE.h"
#include "Matriz_exata.h"
#include "Salvar_matriz.h"
#include "Primeiro_passo.h"
#include "Df.h"
#include "L_f.h"


double ***Wave(double ***M,double **y_ex,double **y_d, int n, double h, double ratio,double c,int aux) 
{
	int i, j, k,auxf;
	double*** y;
	char nome[100],nome2[100];
	FILE *arq;
	
	y= P_P(M,n,h,ratio,c);
	
	for (k = 1; k <16001; k++) { // loop para repetir o processo de resolver a equação
		
		y= DF(y,n,h);
		
		y= L_F(y,n);

		if(k%100==0.0)
		{	
			/*printf("%d \n",k);*/
			salvar_matriz(y,n,h,k);
			matriz_exata(y_ex,n,c,h*k,k);
			MAPE(y,y_ex,n,h,k);
		}

	}
	return y;
}
