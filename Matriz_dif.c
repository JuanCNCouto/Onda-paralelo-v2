#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matriz_dif.h"

void M_dif(double ***y,double **y_ex, int n,double h,int k){
  int i,j;
  char nome[100];
  FILE *arq;
  snprintf(nome, sizeof(nome), "./saida/Mdif-%d.dat", k);
  arq = fopen(nome,"w");
  for (i = 0; i < n; i++) {                                                                                                       for (j = 0; j < n; j++) {
		  fprintf(arq, "%g %g %g\n",i*h,j*h, y_ex[i][j]-y[i][j][1]);
 		}
	}
  fclose(arq);
}
