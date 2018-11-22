/*

EXERCISE 01
 
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100000

int main(argc, argv)

int			argc;
char		*argv[];

{
	int		n,n_nos, rank;
	MPI_Status	status;
    MPI_Request req;
    int inicio,fim,i,j,k;
    double soma,parcial_soma,soma_rec;
    int A[SIZE], B[SIZE], C[SIZE], D[SIZE];
    int buff[1];
    int vet_ocorrencias[4];
    int num;
    int gsize;
    int *rbuf;

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

    n=SIZE;
    printf("INICIO\n");
    fflush(stdout);
    k=n/n_nos;
    inicio=rank*k;
    fim=inicio+k;

    /* Inicia Matriz de cada nó */

    for (i = inicio; i < fim; i ++)
    {
        A[i] = rand()%20;
        B[i] = rand()%20;
        C[i] = rand()%20;
        D[i] = rand()%20;
    }

    if (rank == 0)
    {
        num = rand()%20;
        MPI_Comm_size(MPI_COMM_WORLD, &gsize);
        rbuf = (int *)malloc(gsize*100*sizeof(int));
        MPI_Bcast(rbuf, 1, MPI_INT, 0, MPI_COMM_WORLD);

    }

    else
    {
        int a = 0, b = 0, c = 0, d = 0;
        for (i = inicio; i < fim; i ++)
        {
            if (A[i] == buff[0] && a == 1)
            {
                vet_ocorrencias[0] = i;
                a = 1;
            }
            if (B[i] == buff[0] && b == 1)
            {
                vet_ocorrencias[1] = i;                
                b = 1;
            }
            if (C[i] == buff[0] && c == 1)
            {
                vet_ocorrencias[2] = i;                
                c = 1;
            }
            if (D[i] == buff[0] && d == 1)
            {
                vet_ocorrencias[3] = i;
                d = 1;
            }            
        }
        MPI_Gather(&vet_ocorrencias,4,MPI_INT,16,1,MPI_INT,0,MPI_COMM_WORLD);
    }
        
	MPI_Finalize();

    printf("num: %d\n",num);
    for (int i = 0; i < 16; i++)
    {
        printf("%d\n", rbuf[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("A[%d] = %d B[%d] = %d C[%d] = %d D[%d] = %d\n",i,A[i],i,B[i],i,C[i],i,D[i]);
    }
	return(0);
}
