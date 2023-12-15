#include <stdio.h>
#include<stdlib.h>
#include "Primeiro_passo.h"
#include<omp.h>
double ***P_P(double ***M,int n,double h, double ratio,double c){
       	int i,j,chunk=1;
	double ***y,u;
	y=M;
	#pragma omp parallel for private(i,j,u) shared(y)
	#pragma omp Schedule(dynamic,chunk)
	for (i = 1; i < n-1; i++) { // para o primeiro passo
		for (j = 1; j < n-1; j++) {
			u = y[i][j][0] + c*c*(ratio * ratio) * (y[i + 1][j][0] + y[i - 1][j][0] + y[i][j + 1][0] + y[i][j - 1][0] - 4.0 * y[i][j][0]);
			y[i][j][1]=u;	
		}
	}


	return y;
}
