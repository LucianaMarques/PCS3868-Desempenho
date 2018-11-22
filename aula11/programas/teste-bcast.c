// Exemplo de uso do MPI_Bcast
// Nó 0 inicia vetor, envia todos os seus elementos para os demais nos.
// Todos nos fazem a soma de todos os elementos de vetor

#include <mpi.h>
#include <stdio.h>

main(argc, argv)

int			argc;
char			*argv[];

{
	int		i,n,n_nos, rank;
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
        n=1000;
        if (rank == 0){
          printf("n_nos=%d\n",n_nos);
          fflush(stdout);
          for(i=0;i<n;i++)
            vetor[i]=i;
        } 
        MPI_Bcast(vetor,n,MPI_INT,0,MPI_COMM_WORLD);
        soma=0;
        for(i=0;(i<n);i++)
          soma+=vetor[i];
        printf("rank=%d soma=%d\n",rank,soma);
        fflush(stdout);
	MPI_Finalize();
	return(0);
}

