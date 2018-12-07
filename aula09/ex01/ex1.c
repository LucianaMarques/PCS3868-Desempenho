/*
 * Transmit a message in a two process system.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAYSIZE		64

int			sendbuf[ARRAYSIZE], rbuf[ARRAYSIZE], *sub_maiors;

int
main(argc, argv)

int			argc;
char			*argv[];

{
	int		size, rank, BUFSIZE;
	MPI_Status	status;
       int i;
/*
 * Initialize MPI.
 */
	MPI_Init(&argc, &argv);
/*
 * Error check the number of processes.
 * Determine my rank in the world group.
 * The sender will be rank 0 and the receiver, rank 1.
 */
	/* saber o numero de processos */
	MPI_Comm_size(MPI_COMM_WORLD, &size);



	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
/*
 * As rank 0, send a message to rank 1.
 */

	if (0 == rank) {

		srand(time(NULL));
	        for (i=0;i<ARRAYSIZE;i++)
                	sendbuf[i] = rand();

	    	/* Sends message to 1 */
    		/*MPI_Send(buf, BUFSIZE, MPI_INT, 1, 11, MPI_COMM_WORLD);*/

			}
		BUFSIZE = ARRAYSIZE/size +1 ;

		MPI_Scatter(sendbuf, BUFSIZE, MPI_INT, &rbuf, BUFSIZE, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Barrier (MPI_COMM_WORLD);
		printf("\nProcess n°%d:\n", rank);

		int maior = rbuf[0];

                for(i=1;i<BUFSIZE;i++)
                {

									printf("%d-%d ",rank,rbuf[i]);
									if (rbuf[i] > maior)
										maior = rbuf[i];
               		//fflush(stdout);
		}
                printf("\nMAX VALUE FOR PROCESS N°%d : %d\n\n",rank, maior);

		if (rank == 0) {
			sub_maiors = malloc(sizeof(int) * size);}


		MPI_Gather(&maior,1,MPI_INT,sub_maiors,1,MPI_INT,0,MPI_COMM_WORLD);
		MPI_Barrier (MPI_COMM_WORLD);
	if (rank==0) {
		int total_max = sub_maiors[0];
		for(i=0;i<size;i++){
			if (sub_maiors[i] > total_max)
			 {total_max = sub_maiors[i];}
			printf("%d\n",sub_maiors[i]);}
			printf("TOTAL MAX = %d\n", total_max);
	}
	MPI_Finalize();
	return(0);
}
