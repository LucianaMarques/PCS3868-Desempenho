// Exercicio 1: Programa busca uma sequencia, definida pelo usuario, em um arquivo com varias sequencias
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define SEQ_SIZE 12



/*
* Error check the number of processes.
* Determine my rank in the world group.
* The sender will be rank 0 and the receiver, rank 1.
*/

int main(int argc, char **argv)
{
    int i = 0;
    int j, BUFSIZE, FILE_SIZE;

    char * buff;
    char sequencia[SEQ_SIZE];
    int file_size;
    char ** seq_vet, **rbuf;
    int NB_LINES;
    int k, busca_validation;
    FILE *f;

    int ierr, rank,n_nos;

    MPI_Init(&argc, &argv);

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &n_nos);

    printf("Hello world! I'm process %i out of %i processes\n",
       rank, n_nos);


    if (rank==0){
      f = fopen("seq-teste.txt", "r");
      fseek(f,0L,SEEK_END);
      FILE_SIZE =ftell(f);
      fseek(f,0L,SEEK_SET);
      NB_LINES=(FILE_SIZE+1)/(SEQ_SIZE-1);

      seq_vet=(char **)malloc(NB_LINES*sizeof(char *));
      for (k=0;k<NB_LINES;k++)
          seq_vet[k]=malloc(SEQ_SIZE*sizeof(char));

      for (i=0;i<NB_LINES;i++){
  	fgets(seq_vet[i], SEQ_SIZE, f);}


     printf("file_size=%d\n",FILE_SIZE);
     printf("Digite a sequencia que deseja buscar:\n ");

     scanf("%s",sequencia);

     BUFSIZE = NB_LINES/n_nos + 1;

    }

    MPI_Bcast(sequencia,SEQ_SIZE,MPI_UNSIGNED_CHAR,0,MPI_COMM_WORLD);
    MPI_Bcast(&BUFSIZE,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Bcast(&NB_LINES,1,MPI_INT,0,MPI_COMM_WORLD);


    rbuf=(char **)malloc(NB_LINES*sizeof(char *));
    int indice_achou[NB_LINES];
		MPI_Scatter(seq_vet, BUFSIZE*sizeof(char *), MPI_UNSIGNED_CHAR, rbuf, BUFSIZE*sizeof(char *), MPI_UNSIGNED_CHAR, 0, MPI_COMM_WORLD);

    k=0;
    i=0;



    for (i=0;i<BUFSIZE-1;i++){

      buff = rbuf[i];
      busca_validation = 1;
      for (j=0; j<SEQ_SIZE-2; j++)
      { if (buff[j] != sequencia[j])
      {busca_validation = 0;
        }

      }
      if (busca_validation ==1)
      {printf("Found one\n");
      indice_achou[k]=i;
      k++;}
     }

     if (k != 0){
   		printf("Sequencia encontrada  %d vezes\n",k);
   		for (i=0;i<k;i++)
   			printf("i=%d  \n",indice_achou[i]);
   		printf ("\n");
           }
   	else{
   		printf("Sequencia nao encontrada\n ");
   	fclose(f);
  }
  MPI_Finalize();
   	return 0;
}
