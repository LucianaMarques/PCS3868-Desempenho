#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <omp.h>
#define think 20
#define eat 10

sem_t sem[5];

void thinking(i)
{ 
	printf("filosofo %d thinking\n",i);
  
	fflush(stdout);
  
	usleep(think);
} 

void eating(int i)
{ 
	printf("filosofo %d eating\n",i);
  
	fflush(stdout);
  
	usleep(eat);
} 

void filosofo(int i)
{ 
	int k;
  
	for (k=0;k<100;k++) { 
     
		thinking(i);
     
		if (i != 4){
			sem_wait(&sem[i]);

			usleep(1);
     
			sem_wait(&sem[(i+1)%5]);
		}     
		else
		{
			sem_wait(&sem[(i+1)%5]);

			usleep(1);

			sem_wait(&sem[i]);
		}

		eating(i);
     
		sem_post(&sem[i]);
     
		sem_post(&sem[(i+1)%5]);
		
  
	}
}

void main()
{
  
	printf("INICIO \n");
  
	fflush(stdout);
  
	sem_init(&sem[0],0,1);
  
	sem_init(&sem[1],0,1);
  
	sem_init(&sem[2],0,1);
  
	sem_init(&sem[3],0,1);
  
	sem_init(&sem[4],0,1);
  

	#pragma omp parallel num_threads(5)

      	{   
      		#pragma omp sections
      		{
        		 #pragma omp section
         		 filosofo(0);
       			 
			#pragma omp section         
			filosofo(1);

         
			#pragma omp section
		         filosofo(2);
         
			#pragma omp section
         		filosofo(3);
         		
			#pragma omp section
         		filosofo(4);
      }
  }
      printf("FIM\n");
}      
  
