// 1 processos MPI, criando 2 grupos com um processo cada
// grupo1 - comunicador everyone1 executa worker_teste1_a
// grupo2 - comunicador everyone2 executa worker_teste1_b
/* manager */ 
#include <stdio.h>
#include "mpi.h" 
int main(int argc, char *argv[]) 
{ 
//   int world_size, universe_size, *universe_sizep, flag; 
   int world_size; 
   MPI_Comm everyone1;           /* intercommunicator 1 */
   MPI_Comm everyone2;
   int X,Y,Z;
   int rank; 
   MPI_Status status; 
MPI_Init(&argc, &argv); 
   MPI_Comm_size(MPI_COMM_WORLD, &world_size); 
printf("PASSEI 1 world_size=%d\n",world_size);
fflush(stdout); 
if (world_size != 1)    error("erro: deverá ser apenas 1 processo"); 
 
/*  
    * Now spawn the workers. Note that there is a run-time determination 
    * of what type of worker to spawn, and presumably this calculation must 
    * be done at run time and cannot be calculated before starting 
    * the program. If everything is known when the application is  
    * first started, it is generally better to start them all at once 
    * in a single MPI_COMM_WORLD.  
    */ 
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
printf("PROGRAMA PRINCIPAL rank=%d\n",rank);
fflush(stdout); 
      MPI_Comm_spawn("worker_teste1_a", MPI_ARGV_NULL, 1,  
             MPI_INFO_NULL, 0, MPI_COMM_SELF, &everyone1,  
             MPI_ERRCODES_IGNORE); 
      MPI_Comm_spawn("worker_teste1_b", MPI_ARGV_NULL, 1,
             MPI_INFO_NULL, 0, MPI_COMM_SELF, &everyone2,
             MPI_ERRCODES_IGNORE);

      X=3;
      MPI_Send(&X,1,MPI_INT,0,11,everyone1);
      printf("rank=%d ENVIOU X=3 para 0 de grupo1\n",rank);
      fflush(stdout);
      X=7;
      MPI_Send(&X,1,MPI_INT,0,11,everyone2);
      printf("ENVIOU X=7 para 0 de grupo2\n");
      fflush(stdout);
      MPI_Recv(&Y,1,MPI_INT,0,12,everyone1,&status);
      printf("main RECEBEU Y=%d de 0 de grupo1\n",Y);
      fflush(stdout);
      MPI_Recv(&Z,1,MPI_INT,0,12,everyone2,&status);
      printf("RECEBEU Z=%d de 0 de grupo2\n",Z);
      fflush(stdout);
   printf ("MAIN TESTE\n");
   fflush(stdout);  
 
MPI_Finalize(); 
   return 0; 
} 



 

