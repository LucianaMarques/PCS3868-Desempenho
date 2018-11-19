/*
 * Programa que inicia matrizes de maneira paralelizada com três processos
 */

#include <stdio.h>
#define size 1000
#define n_processos 3
#include   <sys/shm.h>
#include <stdlib.h>

typedef struct {
   double a[1000][1000], b[1000][1000], c[1000][1000];
} matrizes;

matrizes *matriz;
pid_t pid_p;

void main()
{  
	
	int i,j,k;

     	pid_t pid[n_processos]; //pid_t é um tipo que guarda o id do processo
   
	int status;

	struct shmid_ds *buf; //estrutura de dados do kernel que referencia um pedaço de memória compartilhada

   	int id;

   	int n_iter,inicio,fim;

	//identifica um segmento de memória compartilhada
	id = shmget (IPC_PRIVATE, sizeof(matrizes), 0777 | IPC_CREAT);

	//aloca as matrizes nesse segmento
	matriz= shmat (id, 0, 0);
   	
	//inicializa as matrizes   -  3 processos
   	n_iter=size/(n_processos+1);

   	inicio=0;
   	
	fim=n_iter;
   	
	k=-1;
   	
	do {
     		k++; 
     		pid_p=fork();
		if ((int)pid_p != 0){   //pai
       			pid[k]=pid_p;
		}
   	}while((pid_p !=0) & (k<(n_processos-1)));
	
	if ((int)pid_p == 0){     //filhos
		matriz= shmat (id, 0, 0);
        	inicio=(k+1)*n_iter;
        	fim=inicio+n_iter;
   	}
   	
	printf("inicio=%d  fim=%d   k=%d   n_iter=%d\n",inicio,fim,k,n_iter);
   	
	for (i=inicio;i<fim;i++)
       		for (j=0;j<size;j++){
               		((matrizes *)matriz)->a[i][j]=1.5;
               		((matrizes *)matriz)->b[i][j]=2.6;
					((matrizes *)matriz)->c[i][j] = matriz->a[i][j] + matriz->b[i][j];
      		}

	if ((int)pid_p == 0){     //filhos
      		shmdt (matriz);
      		exit(1);
   	}
   	
	// fim da inicializacao
   	
	for (k=0;k<n_processos;k++){
      		waitpid(pid[k],&status,0);
		printf("wait pid\n");
	}

	printf("saiu\n");
   	
	printf("c[0][0]=%f   c[15][20]=%f  c[size-1][size-1]=%f \n",((matrizes *)matriz)->c[0][0],((matrizes *)matriz)->c[15][20],((matrizes *)matriz)->c[size-1][size-1]);
      	
	shmdt (matriz);
      	
	shmctl (id, IPC_RMID, buf); //remove area compartilhada
}

        

        
   

