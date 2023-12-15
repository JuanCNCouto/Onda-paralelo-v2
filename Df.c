#include<stdio.h>
#include<stdlib.h>
#include "Df.h"
#include<omp.h>

double ***DF(double ***M, int n, double ratio){
	int i,j,chunk=1;
	double ***y,u;	
	y=M;
	#pragma omp parallel for private(i,j,u) shared(y) 
	#pragma omp Schedule(dynamic,chunk)
	for (i = 1; i < n-1; i++){   // equação de onda ratio = c²*(dx/dt
		for (j = 1; j < n-1; j++){ 
			u= 2 * y[i][j][1] - y[i][j][0] +0.5*ratio*(y[i + 1][j][1] + y[i - 1][j][1] + y[i][j + 1][1] + y[i][j - 1][1] - 4.0 * y[i][j][1]);
			y[i][j][2]=u;
			}
		}
	return y;
}	
