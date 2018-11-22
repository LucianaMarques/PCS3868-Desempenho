// Exercicio 1: Programa busca uma sequencia, definida pelo usuario, em um arquivo com varias sequencias 

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SEQ_SIZE 12
#define TRUE 0
#define FALSE 1
#define n_threads 4

int main()
{
	int i = 0;

    	int igual;
    	char * buff;
    	char sequencia[SEQ_SIZE];
    	int file_size;
    	char ** seq_vet;
    	int n_seq;
    	int k;
    
	/*
	 * Abertura do arquivo
	 */
    	FILE *f = fopen("seq-teste.txt", "r");
	
	if (f == NULL)
	{
	    printf("Erro na abertura do arquivo\n");
	    exit(1);
	}
    
	/*
	 * Cálculo do tamanho do arquivo
	 */
	fseek(f,0L,SEEK_END);
    	file_size=ftell(f);
    	fseek(f,0L,SEEK_SET);
    	n_seq=(file_size+1)/(SEQ_SIZE-1);
    	seq_vet=(char **)malloc(n_seq*sizeof(char *));

    	for (k=0;k<n_seq;k++)
        	seq_vet[k]=malloc(SEQ_SIZE*sizeof(char));
    	
	while(!feof(f)){
		fgets(seq_vet[i], SEQ_SIZE, f);
        	printf("seq_vet[%d] =  %s\n ",i,seq_vet[i]);
        	i=i+1;
   	}
   	printf("file_size=%d\n",file_size);

	/*
	 * Captura da sequencia a ser buscada
	 */

   	printf("Digite a sequencia que deseja buscar: ");
   	scanf("%s",&sequencia);
   	
	/*
	 * Busca da string no arquivo
	 */

	omp_set_num_threads(n_threads);
	#pragma omp 
	{
		int p, j, k, n, inicio, fim, equal_buff = 1;
		igual = FALSE;
		#pragma parallel for num_threads(n_threads) private (p,j,k, equal_buff) sharead (igual, SEQ_SIZE, buff, seq_vet, sequencia)
		{

		   	for (k = 0; k < n_threads; k++)
			{

				n = n_seq/n_threads;

				inicio = k*n;
				fim = inicio + n;
				
				if (k == (n_threads-1))
					fim = fim + n_seq%n_threads;
				
				printf("k: %d inicio: %d fim: %d\n", k, inicio, fim);

				for (p=inicio;p<fim;p++){		

        				buff=seq_vet[p];
					equal_buff = 1;
        				//printf("i=%d buff %s\n ",i,buff);

					for (j = 0; j < SEQ_SIZE-2 && equal_buff == 1; j++){
							if (sequencia[j] != buff[j]){
								#pragma omp critical
								{
									equal_buff = 0;
								}
							}
					}

        				if (j== SEQ_SIZE-2) {
						#pragma omp critical
						{
							igual=TRUE;
						}
        				}
   				}

   				if (igual == TRUE)
					printf("Sequencia encontrada na linha\n");
   				else
					printf("Sequencia nao encontrada i=%d\n",i);
			}
		}
	}

   	fclose(f);
   	return 0;
}
