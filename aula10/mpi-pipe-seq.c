/*
tarefa1:X=A x B
tarefa2:Y=E x F
tarefa3:Z=C x D
tarefa4: W=X+Y+Z+W i imprime 10 primeiros elementos da linha 499 de W


 */

#include <stdio.h>
#include <stdlib>
#include <mpi.h>
int n;
int X[500][500],Y[500][500],Z[500][500];
void tarefa1()
{
    int i,j;
    for (i=0;i<500;i++)
      for (j=0;j<500;j++) {
        X[i][j]=i*2-j;
      }
    for (i=0;i<499;i++) {
         for(j=1;j<499;j++)
                X[i][j]=X[i+1][j-1]*3-X[i+1][j+1];
    }
    printf("tarefa1 FIM\n");
    fflush(stdout);
}


void tarefa2()
{
    int i,j;
    for (i=0;i<500;i++)
      for (j=0;j<500;j++) {
        Y[i][j]=i*3-j;
      }
    for (i=0;i<499;i++) {
         for(j=1;j<499;j++)
                Y[i][j]=Y[i+1][j-1]*4-Y[i+1][j+1];
    }
    printf("tarefa2 FIM\n");
    fflush(stdout);
}
void tarefa3()
{
    int i,j;
    for (i=0;i<500;i++)
      for (j=0;j<500;j++) {
        Z[i][j]=i*2+j;
      }
    for (i=0;i<499;i++) {
         for(j=1;j<499;j++)
                Z[i][j]=Z[i+1][j-1]*2-Z[i+1][j+1];
    }
    printf("tarefa3 FIM\n");
    fflush(stdout);
}

void tarefa4()
{ int i,j;
  int W[500][500];
  int A[500];
  for (i=0;i<500;i++)
      for (j=0;j<500;j++)
         W[i][j]=0;
  for (i=0;i<500;i++) {
          for (j=0;j<500;j++)
             W[i][j]=X[i][j]+Y[i][j]+Z[i][j];
  }
    printf("tarefa4 W[0][0]=%d W[300][400]=%d  W[499][499]=%d\n",W[0][0], W[300][400],W[499][499]);
    fflush(stdout);
    printf("tarefa4 FIM\n");
    fflush(stdout);
}

main(argc, argv)
int			argc;
char			*argv[];

{
        int		size, rank;
        MPI_Status	status;
        int i;
        MPI_init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        if (4 != size) {
      		MPI_Finalize();
      		return(1);
      	}
        n=500;
        if (rank == 0)
        {
          tarefa1();
          MPI_Send(buf, BUFSIZE, MPI_INT, 1, 11, MPI_COMM_WORLD);
        }
        if (rank == 1)
        {
          tarefa2();
          MPI_Send(buf, BUFSIZE, MPI_INT, 1, 11, MPI_COMM_WORLD);
        }
        if (rank == 2)
        {
          MPI_Recv(buf, BUFSIZE, MPI_INT, 0, 11, MPI_COMM_WORLD, &status);
          tarefa3();
        }
        if (rank == 3)
        {
          MPI_Recv(buf, BUFSIZE, MPI_INT, 0, 11, MPI_COMM_WORLD, &status);
          tarefa4();
        }
	return(0);
}
