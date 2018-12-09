


/* worker */ 
// teste de comunicacao entre processos criados

#include <stdio.h> 
#include "mpi.h" 
int main(int argc, char *argv[]) 
{ 
   char A;
   MPI_Status      status;
   int size,rank,i,k,n_procs,rank_parent;
   MPI_Comm parent;
   MPI_Init(&argc, &argv); 
   MPI_Comm_get_parent(&parent); 
   if (parent == MPI_COMM_NULL) error("No parent!"); 
   MPI_Comm_remote_size(parent, &size); 
   if (size != 1) error("Something's wrong with the parent"); 
 
/* 
    * Parallel code here.  
    * The manager is represented as the process with rank 0 in (the remote 
    * group of) MPI_COMM_PARENT.  If the workers need to communicate among 
    * themselves, they can use MPI_COMM_WORLD. 
    */ 
   MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
   printf("n_procs = %d\n",n_procs);
   fflush(stdout);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   printf("GRUPO1  rank_world=%d \n",rank);
   fflush(stdout);
   printf("worker a\n");
   fflush(stdout);
   printf("ANTES DO RECEBIMENTO\n");
   fflush(stdout);
   MPI_Recv(&i,1,MPI_INT,0,11,parent,&status);
   printf("RECEBIDO rank=%d i=%d\n",rank,i);
   fflush(stdout);
   i=i+1;
   MPI_Send(&i,1,MPI_INT,0,12,parent);
   printf("fim worker_a rank %d\n",rank);
   fflush(stdout);
   MPI_Comm_free(&parent);
   MPI_Finalize(); 
   return 0; 
} 
 

