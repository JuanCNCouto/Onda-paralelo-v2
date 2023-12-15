#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include "L_f.h"
double*** L_F(double ***M,int n){
	int i,j;
	double ***y;
	y=M;
	#pragma omp parallel for private(i,j)
	for (i = 0; i < n; i++) { // loop para atualizar os valores
		for (j = 0; j < n; j++) {
			y[i][j][0] = y[i][j][1]; // presente virou passado

			y[i][j][1] = y[i][j][2]; // futuro virou presente    	                                                                                                                                                                                           
		}
	}
	return y;
} 
