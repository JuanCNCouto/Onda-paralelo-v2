#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "C_I_C.h"
#include <omp.h>

void C_I_C(double ***A, double h, int n) {
  	int i, j,chunk=1;
  	double x = 0, y = 0;
  // os Loops vão do segundo termo até o penultimo termo
  // por causa das condições de contorno de dirichlet,
  // assim as bordas continuam zero
	#pragma omp parallel for private(i,j,x,y) shared(A) 
	#pragma omp Schedule(dynamic,chunk)
  	for (i = 0; i < n; i++) {
    		y=i*h;
    		for (j = 0; j < n; j++) {
      	// condição inicial t=0
     	 		A[i][j][0] = (sin(2 * x)) * (sin(y));
			x= j*h;

    		}
  	}
  }
