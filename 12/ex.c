// Exemplo de uso de barreira    MPI_Barrier
// Nó 0 inicia vetor, envia todos os seus elementos para os demais nos.
// Todos nos fazem a soma de todos os elementos de vetor

#include <mpi.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 1000

double A[SIZE];
double B[SIZE];
double C[SIZE];
double D[SIZE];
double X[SIZE];
double Y[SIZE];
double Z[SIZE];

main(argc, argv)

int			argc;
char			*argv[];

{
	int		i,j,kn,n_nos, rank;
	MPI_Status	status;
        int vetor[1000];
        int soma;
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

        if (rank == 0)
        {
                omp_set_num_threads(2);
                #pragma omp parrallel shared (X,A,B) private (i){
                        #pragma parrallel for
                        for (i = 0; i < SIZE; i++)
                        {
                                A[i] = rand();
                                B[i] = rand();
                                X[i] = A[i]*B[i];

                        }
                }
        }

        if (rank == 1)
        {
                omp_set_num_threads(2);
                #pragma omp parrallel shared (Y,C,D) private (j){
                        #pragma parrallel for
                        for (j = 0; j < SIZE; j++)
                        {

                        }
                }
        }

        if (rank == 2)
        {
                omp_set_num_threads(2);
                #pragma omp parrallel shared (Z,Y,X) private (k){
                        #pragma parrallel for
                        for (k = 0; k < SIZE; k++)
                        {

                        }
                }
        }

        n=1000;
        for(i=0;i<n;i++)
            vetor[i]=i;
        if (rank == 0) sleep(10); 
        soma=0;
        for(i=0;(i<n);i++)
        soma+=vetor[i];
        printf("rank=%d soma=%d\n",rank,soma);
        fflush(stdout);
        MPI_Barrier(MPI_COMM_WORLD);
        printf("FIM rank=%d\n",rank);
        fflush(stdout);
	MPI_Finalize();
	return(0);
}

