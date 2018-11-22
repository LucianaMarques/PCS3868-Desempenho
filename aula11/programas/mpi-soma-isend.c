/*
Soma de Elementos de um vetor usando MPI_Isend.
Numero de elementos do vetor: multiplo do número de processos.
 
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
        MPI_Request req;
        int inicio,fim,i,j,k;
        double soma,parcial_soma,soma_rec;
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
        inicio=rank*k;
        fim=inicio+k;
        if (rank==0) {
          for(i=0;i<n;i++)
            for(j=0;j<n;j++)
              a[i][j]=1;
              
          for (i=1;i<n_nos;i++)
{
printf("rank 0 antes de Send\n");
fflush(stdout);

            MPI_Isend(&a[0][0]+(k*n*i),k*n,MPI_DOUBLE,i,10,MPI_COMM_WORLD,&req);
printf("rank 0 apos Send\n");
fflush(stdout); 
}        }
        else {
          MPI_Recv(a,k*n,MPI_DOUBLE,0,10,MPI_COMM_WORLD,&status);
        printf("a[0][0]=%f\n",a[0][0]);
        fflush(stdout);
        }
        parcial_soma=0;
        for(i=0;(i<n/n_nos);i++)
         for(j=0;j<n;j++)
          parcial_soma+=a[i][j];
        printf("rank=%d parcial_soma=%f\n",rank,parcial_soma);
        fflush(stdout);
        if (rank==0) {
           soma=parcial_soma;
           for(i=1;i<n_nos;i++){
             MPI_Recv(&soma_rec,1,MPI_DOUBLE,MPI_ANY_SOURCE,11,MPI_COMM_WORLD,&status);
             soma+=soma_rec;}
           printf("RESULTADO=%f\n",soma);
           fflush(stdout); 
           }
        else {
           MPI_Send(&parcial_soma,1,MPI_DOUBLE,0,11,MPI_COMM_WORLD);
             }
	MPI_Finalize();
	return(0);
}
