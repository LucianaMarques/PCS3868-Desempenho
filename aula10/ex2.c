#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define BUFSIZE 1
#define MAT_SIZE 500
int n;
int X[MAT_SIZE][MAT_SIZE],Y[MAT_SIZE][MAT_SIZE],Z[MAT_SIZE][MAT_SIZE];

/*
tarefa1:X=A x B
tarefa2:Y=E x F
tarefa3:Z=C x D
tarefa4: W=X+Y+Z+W i imprime 10 primeiros elementos da linha MAT_SIZE de W


 */

void tarefa1()
{
  int i,j,n_nos, size;
  int* buf;
     MPI_Status status;
    for (i=0;i<MAT_SIZE;i++){
      for (j=0;j<MAT_SIZE;j++) {
        X[i][j]=i*2-j;
      }}

      buf=(int *)malloc(MAT_SIZE);
      MPI_Buffer_attach(buf,MAT_SIZE);

    for (i=0;i<MAT_SIZE-1;i++) {

         for(j=1;j<MAT_SIZE-1;j++){


                  X[i][j]=X[i+1][j-1]*3-X[i+1][j+1];


                }

                MPI_Bsend(&X[i], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);}
          MPI_Bsend(&X[MAT_SIZE-1], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);
        size = MAT_SIZE;
        MPI_Buffer_detach(buf,&size);
        printf("tarefa1 FIM\n");
    }




void tarefa2()
{
  int i,j,n_nos, size;
  int* buf;
     MPI_Status status;
    for (i=0;i<MAT_SIZE;i++){
      for (j=0;j<MAT_SIZE;j++) {
        Y[i][j]=i*3-j;
      }}

    buf=(int *)malloc(MAT_SIZE);
    MPI_Buffer_attach(buf,MAT_SIZE);

    for (i=0;i<MAT_SIZE-1;i++) {

         for(j=1;j<MAT_SIZE-1;j++){
                  Y[i][j]=Y[i+1][j-1]*4-Y[i+1][j+1];}




      MPI_Bsend(&Y[i], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);
    }
    MPI_Bsend(&Y[MAT_SIZE-1], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);
    size = MAT_SIZE;
    MPI_Buffer_detach(buf,&size);
      printf("tarefa2 FIM\n");
    }



void tarefa3()
{
    int i,j,n_nos, size;
    int* buf;
   MPI_Status status;

   MPI_Comm_size(MPI_COMM_WORLD, &n_nos);
    for (i=0;i<MAT_SIZE;i++){
      for (j=0;j<MAT_SIZE;j++) {
        Z[i][j]=i*2+j;
      }}

      buf=(int *)malloc(MAT_SIZE);
      MPI_Buffer_attach(buf,MAT_SIZE);

    for (i=0;i<MAT_SIZE-1;i++) {

         for(j=1;j<MAT_SIZE-1;j++){

                Z[i][j]=Z[i+1][j-1]*2-Z[i+1][j+1];}



                    MPI_Bsend(&Z[i], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);

                    }
                    MPI_Bsend(&Z[MAT_SIZE-1], MAT_SIZE, MPI_INT, 3, 0, MPI_COMM_WORLD);


                    size = MAT_SIZE;
                    MPI_Buffer_detach(buf,&size);
                    printf("tarefa3 FIM\n");

        }





void tarefa4()
{ int i,j;
  int buf1[MAT_SIZE],buf2[MAT_SIZE],buf3[MAT_SIZE];
  MPI_Status status;
  int W[MAT_SIZE][MAT_SIZE];
  int A[MAT_SIZE];
  for (i=0;i<MAT_SIZE;i++)
      for (j=0;j<MAT_SIZE;j++)
         W[i][j]=0;
  for (i=0;i<MAT_SIZE;i++) {

    MPI_Recv(&buf1, MAT_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    MPI_Recv(&buf2, MAT_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    MPI_Recv(&buf3, MAT_SIZE, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

          for (j=0;j<MAT_SIZE;j++){



            W[i][j]=buf1[j] + buf2[j] + buf3[j];

          }
  }
    printf("tarefa4 W[0][0]=%d W[300][400]=%d  W[499][499]=%d\n",W[0][0], W[300][400],W[499][499]);
    printf("tarefa4 Last element of W = %d\n",W[MAT_SIZE-1][MAT_SIZE-1]);
    printf("tarefa4 FIM\n");


}

int main(argc, argv)
int			argc;
char			*argv[];

{
        int		size, rank;
        MPI_Status	status;
        int i;
        MPI_Init(&argc, &argv);

        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if (4 != size) {
      		MPI_Finalize();
      		return(0);
      	}

        if (rank == 0)
        {
          tarefa1();
        }
        if (rank == 1)
        {
          tarefa2();
        }
        if (rank == 2)
        {
          tarefa3();
        }
        if (rank == 3)
        {
          tarefa4();
        }
MPI_Finalize();
  	return(0);
}
