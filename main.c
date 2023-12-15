#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C_I_C.h"
#include <time.h>
#include "Matriz_exata.h"
#include "Salvar_matriz.h"
#include "Wave.h"
#include <omp.h>

int main() {
  double  Lx, Ly, ***M,**M_ex,n,**M_dif, h;
  int i, j, cont = 0;
  double k = 0.333, den = 390.0, ten = 180.0 , c,cp,ccp, ratio;
  FILE  *M0;

  c = sqrt(ten / den); // velocidade da onda
  
  /* quantos pontos vai ter a matriz*/
  n = 4000;
  // cumprimento dos eixos
  Lx = Ly = 3.141592;
  c= sqrt(ten/den);
  cp=c;
  ccp- c/cp;
  ratio= 0.5*ccp*ccp;
  // h = dx=dy ( malha quadrada):
  h = Lx / n;
  //printf("2- cria a matriz \n");
  // M[i][j][k] - o primeiro indice é o tempo passado,presente,futuro e os
  // outros 2 são dimensoes espaciais
  M = (double ***)malloc(n * sizeof(double **));
  M_ex = (double **)malloc(n * sizeof(double *));
  M_dif = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    M[i] = (double **)malloc(n * sizeof(double *));
    M_ex[i] = (double *)malloc(n * sizeof(double ));
    M_dif[i] = (double *)malloc(n * sizeof(double ));
    for (j = 0; j < n; j++) {
      M[i][j] = (double *)malloc(3 * sizeof(double));
    }
  }
  printf("1 \n");
  // Condições Iniciais e de Contorno (C.I.C) :
  C_I_C(M, h, n);

  printf("2 \n");
  M0 = fopen("M-0.dat", "w");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fprintf(M0, "%g %g %g\n", i*h,j*h, M[i][j][0]);
    }
  }
  fclose(M0);
  printf("3  \n");

  /* Diferenças finitas*/

  M=Wave(M,M_ex,M_dif ,n, h, ratio,c,cont); // dentro da função resolve em 10000 passos no tempo
  printf("4 \n");
  //imprime_matriz(M[2], n, n, h);
  // Libera a memória alocada para M
  printf("5\n");
  free(M);
  free(M_ex);
  free(M_dif);
 
  printf("acabou\n");
  return 0;
}
