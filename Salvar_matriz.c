#include "Salvar_matriz.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void salvar_matriz(double ***M, int n, double h, int k) {
  int i, j;
  FILE *arq;
  char nome[100];
  snprintf(nome, sizeof(nome), "./saida/M-%d.dat", k);
  arq= fopen(nome,"w");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fprintf(arq, "%g %g %g\n ",i*h,j*h, M[i][j][1]);
    }
    fprintf(arq, "\n");
  }
  fclose(arq);
}
