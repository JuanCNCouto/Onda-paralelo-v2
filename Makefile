CC=gcc
CFLAGS= -I. -lm -O2 -fopenmp -fexpensive-optimizations -m64 -foptimize-register-move -funroll-loops -ffast-math -mtune=corei7-avx -pg -g 
#CFLAGS= -I. -fopenmp -O3 -mtune=native -pg -g  -lm
DEPS= C_I_C.h Primeiro_passo.h Df.h L_f.h MAPE.h Salvar_matriz.h Matriz_exata.h Wave.h main.h
	 
Onda: C_I_C.o Primeiro_passo.o Df.o L_f.o MAPE.o Salvar_matriz.o Matriz_exata.o Wave.o main.o
	$(CC) $(CFLAGS) -o Onda C_I_C.o Primeiro_passo.o Df.o L_f.o MAPE.o Salvar_matriz.o Matriz_exata.o Wave.o main.o 

.PHONY:clean

clean:
	rm -fr ./saida/*.dat *.o ./Onda ./saida/MAPE.txt
