#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "MAPE.h"

void MAPE(double ***y,double **y_ex, int n,double h,int k){
  int i,j,cont=0,MAE;
  char nome[100];
  FILE *arq;
  double aux=0;
  for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
		aux= aux+ y_ex[i][j]-y[i][j][i];
		cont++;
 		}
	}
  MAE= aux/cont;
  snprintf(nome, sizeof(nome), "./saida/MAPE.dat", k);
  arq = fopen(nome,"a");
  fprintf(arq, "%d %g \n",k ,MAE);
  fclose(arq);
}
