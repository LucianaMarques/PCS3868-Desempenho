/*
 *
 * Soma matrizes paralelo
 *
 */

#include <stdio.h>
#define size 1000
#define n_processos 3
#include <sys/shm.h>
#include <stdlib.h>

pid_t pid_p;

typedef struct {
	double a[size][size],b[size][size],c[size][size];
} matrizes;

matrizes * matriz;

void main()
{  
	int i,j,k;

	pid_t pid[n_processos];

	int status;

	struct shmid_ds *buf;

	int id;

	int n_iter, inicio, fim;

	id = shmget (IPC_PRIVATE, sizeof(matriz), 0777 | IPC_CREAT);
   	
	matriz = shmat (id, 0, 0);

	n_iter = size/(n_processos+1);

	inicio = 0;

	fim = n_iter;

	k = -1;

	do {
		k++;
		pid_p = fork();
		if ((int)pid_p !=0){
			pid[k] = pid_p;
		}
	}while ((pid_p != 0) & (k<(n_processos-1)));

	if ((int)pid_p == 0){
		matriz = shmat(id,0,0);
		inicio = (k+1)*n_iter;
		fim = inicio+n_iter;
	}

	printf("inicio = %d fim = %d k = %d n_iter = %d\n", inicio, fim, k, n_iter);
	// soma de a com b
	
	for (i = inicio; i < fim; i++)
	{
		for (j = 0; j < size; j ++)
		{
			matriz->a[i][j] = 1.5;
			matriz->b[i][j] = 2.6;
			printf("got here\n");
			matriz->c[i][j] = 7;
			printf("got here2\n");
		}
	}

	for (k = 0; k < n_processos; k++)
	{
		waitpid(pid[k],&status,0);
		printf("end of process\n");
	}

   	printf("c[0][0]=%f   c[15][20]=%f  c[size-1][size-1]=%f \n",matriz->c[0][0],matriz->c[15][20],matriz->c[size-1][size-1]);

	shmdt(matriz);

	shmctl (id, IPC_RMID, buf); 
}      

        
   

