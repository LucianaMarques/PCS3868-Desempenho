// Exemplo de uso de barreira    MPI_Barrier
// Nó 0 inicia vetor, envia todos os seus elementos para os demais nos.
// Todos nos fazem a soma de todos os elementos de vetor

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000

double A[SIZE];
double B[SIZE];
double C[SIZE];
double D[SIZE];
double X[SIZE];
double Y[SIZE];
double Z[SIZE];

/*

omp_set_num_threads(2);
                        #pragma omp parrallel shared (X,A,B) private (i){
                                #pragma parrallel for
                                for (i = 0; i < SIZE; i++)
                                {
                                        A[i] = rand()%100;
                                        B[i] = rand()%100;
                                        X[i] = A[i]*B[i];
                                        printf("rank=%d X[i]=%f\n",rank,X[i]);
                                        fflush(stdout);
                                        MPI_Barrier(MPI_COMM_WORLD);
                                }
                        }
                        
                if (rank == 1)
                {
                        omp_set_num_threads(2);
                        #pragma omp parrallel shared (Y,C,D) private (j){
                                #pragma parrallel for
                                for (j = 0; j < SIZE; j++)
                                {
                                        C[j] = rand()%100;
                                        D[j] = rand()%100;
                                        Y[j] = C[j]*D[j];
                                        printf("rank=%d Y[j]=%f\n",rank,Y[j]);
                                        fflush(stdout);
                                        MPI_Barrier(MPI_COMM_WORLD);
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
                                        Z[k] = X[k]*Y[k];
                                        printf("rank=%d Z[k]=%f\n",rank,Z[k]);
                                        fflush(stdout);
                                }
                        }
                } 

*/

main(argc, argv)

int			argc;
char			*argv[];

{
	int		i,j,k,n_nos,rank;
	MPI_Status	status;
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


                /*Processo 0*/
                if (rank == 0)
                {
                        #pragma omp parallel for num_threads(2)
                        for (i = 0; i < SIZE; i++)
                        {
                                A[i] = rand()%100;
                                B[i] = rand()%100;
                                X[i] = A[i]*B[i];
                                printf("rank=%d X[i]=%f\n",rank,X[i]);
                                fflush(stdout);
                                MPI_Barrier(MPI_COMM_WORLD);
                        }
                }
                if (rank == 1)
                {
                        #pragma omp parallel for num_threads(2)
                        for (j = 0; j < SIZE; j++)
                        {
                                C[j] = rand()%100;
                                D[j] = rand()%100;
                                Y[j] = C[j]*D[j];
                                printf("rank=%d Y[j]=%f\n",rank,Y[j]);
                                fflush(stdout);
                                MPI_Barrier(MPI_COMM_WORLD);
                        }
                }

                
                if (rank == 2)
                {
                        #pragma omp parallel for num_threads(2)
                        for (k = 0; k < SIZE; k++)
                        {
                                Z[k] = X[k]*Y[k];
                                printf("rank=%d Z[k]=%f\n",rank,Z[k]);
                                fflush(stdout);
                        }
                }
                printf("FIM rank=%d\n",rank);
                fflush(stdout);
	MPI_Finalize();
	return 0;
}

