#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

#define WORKTAG 1
#define DIETAG 2
#define NUM_WORK_REQS 11
#define NSLAVES 10

void (*tab_func[NUM_WORK_REQS])( );

int f1()
{int i;
  i=11;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f2()
{int i;
  i=22;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f3()
{int i;
  i=33;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f4()
{int i;
  i=44;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f5()
{int i;
  i=55;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f6()
{int i;
  i=66;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f7()
{int i;
  i=77;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f8()
{int i;
  i=88;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f9()
{int i;
  i=99;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}

int f10()
{int i;
  i=1010;
  MPI_Send(&i,1,MPI_INT,0,0,MPI_COMM_WORLD);
  return 0;
}




/* This is the master */
int master_io()
{
    int        i,j, size, work, rank,result;
    int buf;
    MPI_Status status;

     for (rank=1;rank<=NSLAVES;rank++){

      buf = WORKTAG;
      printf("MASTER sending WORKTAG to %d\n", rank);
     MPI_Send(&buf,1,MPI_INT,rank,0, MPI_COMM_WORLD);
     }
     printf("ALL WORKTAGS SENT\n");
      for (rank=1;rank<=NSLAVES;rank++) {

      printf("MASTER sending DIETAG to %d\n", rank);
      MPI_Recv(&result,1,MPI_INT,rank,0,MPI_COMM_WORLD,&status);
      printf("RESULT PROCESS %d : %d\n",rank,result);
      buf = DIETAG;
      MPI_Send(&buf,1,MPI_INT,rank,0,MPI_COMM_WORLD);
     }
 printf("ALL DIETAGS SENT\n");
    }




void slave_io() /*slave */
{ int result;

 int  rank;
 int i;

 MPI_Comm_rank(MPI_COMM_WORLD, &rank );

 MPI_Status status;

while (1) {
MPI_Recv(&result,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 if (result==DIETAG)
 {
  printf("Process %d - DIETAG\n", rank);
  break;

 }
 else
 {  printf("Process %d - WORKTAG\n", rank);

if (rank==1) {f1();}
if (rank==2) {f2();}
if (rank==3) {f3();}
if (rank==4) {f4();}
if (rank==5) {f5();}
if (rank==6) {f6();}
if (rank==7) {f7();}
if (rank==8) {f8();}
if (rank==9) {f9();}
if (rank==10) {f10();}
}
}
}



int main( argc, argv )
int argc;
char **argv;
{
    int rank, size;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < NUM_WORK_REQS) {
      printf("Too few processes\n");
      MPI_Finalize();
      return(0);
    }

    if (rank == 0)
	master_io();
    else
	slave_io();

    MPI_Finalize( );
    return 0;
}
