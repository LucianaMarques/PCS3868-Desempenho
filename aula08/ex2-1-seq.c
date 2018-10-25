// Exercicio 1: Programa busca uma sequencia, definida pelo usuario, em um arquivo com varias sequencias 

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SEQ_SIZE 12
#define TRUE 0
#define FALSE 1

int main()
{

    	int i = 0;
    	int j;
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

	igual = FALSE;
   	for (i=0;i<n_seq;i++){	  
        	buff=seq_vet[i];
        	printf("i=%d buff %s\n ",i,buff);
        	for (j = 0; j < SEQ_SIZE-2; j++){
			if (sequencia[j] != buff[j]){
				break;
			}
		}
        	if (j== SEQ_SIZE-2) {
              		igual=TRUE;
              		break;
        	}
   	}

   	if (igual == TRUE)
		printf("Sequencia encontrada na linha %d\n",i);
   	else
		printf("Sequencia nao encontrada i=%d\n",i);

   	fclose(f);
   	return 0;
}
