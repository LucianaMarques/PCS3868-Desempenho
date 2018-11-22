/*
 * EXEMPLO de uso de MPI_Reduce (comunicacao coletiva).
 * Soma dos elementos de uma matriz.
 * Resultado em soma (elementos iguais a 1. soma=1 000 000)
 * Numero de elementos do vetor: multiplo do numero de processos 
 */

#include <mpi.h>
#include <stdio.h>
#include <math.h>

int main(argc, argv)

int			argc;
char			*argv[];

{
	int		n,n_nos, rank;
	MPI_Status	status;
        int fim,i,j,k;
        double soma,parcial;
        double a[1000][1000];
/*
 * Initialize MPI.
 */
	MPI_Init(&argc, &argv);
/*
 * Error check the number of processes.
 * Determine my rank in the world group.
 * The sender will be rank 0 and the receiver, rank 1.
 */
	MPI_Comm_size(MPI_COMM_WORLD, &n_nos);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        n=1000;
printf("INICIO\n");
fflush(stdout);
        k=n/n_nos;
        if (rank==0) {
          for(i=0;i<n;i++)
            for(j=0;j<n;j++)
              a[i][j]=1;
        }
        MPI_Scatter(a,k*n,MPI_DOUBLE,a,k*n,MPI_DOUBLE,0,MPI_COMM_WORLD);
        printf("rank=%d  a[0][0]=%f a[499][0]=%f\n",rank,a[0][0],a[499][0]);
        fflush(stdout);
        parcial=0;
        fim=k;
        for (i=0;i<fim;i++)
          for (j=0;j<n;j++)
             parcial=parcial+a[i][j]; 
        printf("rank=%d parcial=%f\n",rank,parcial);
        fflush(stdout);        
        MPI_Reduce(&parcial,&soma,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
        if (rank==0) {
           printf("RESULTADO=%f\n",soma);
           fflush(stdout);
        } 
	MPI_Finalize();
	return(0);
}
