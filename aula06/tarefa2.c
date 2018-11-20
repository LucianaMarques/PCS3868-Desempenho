#include <stdio.h>
#include <omp.h>

#define SIZE 2000

int X[SIZE];
int Y[SIZE];
int A[SIZE];
int B[SIZE];
int C[SIZE];

omp_lock_t sem1_doing;
omp_lock_t sem1_done;
omp_lock_t sem2_doing;
omp_lock_t sem2_done;

int i, k, x, j;

int main()
{
  //sequential initialization of X and Y
  for (int i = 0; i < SIZE; i++)
  {
      X[i] = i;
      Y[i] = i + 1;
  }
  B[0] = 1;
  C[0] = 1;
  omp_set_num_threads(3);

  omp_init_lock(&sem1_doing);
  omp_init_lock(&sem1_done);
  omp_init_lock(&sem2_doing);
  omp_init_lock(&sem2_done);

  omp_unset_lock(&sem1_done);
  omp_unset_lock(&sem2_done);

  #pragma omp parallel sections
  {
      #pragma omp section 
      {
        #pragma omp parallel for shared(A) private(i)
        for (i = 0; i < SIZE - 1; i++)
        {
          omp_set_lock(&sem1_doing);
          A[i] = i*3 + 15;
          omp_unset_lock(&sem1_doing);
        }
      }
      #pragma omp section 
      {
        #pragma omp parallel for shared (B,Y,A) private(k)
        for (k = 1; k < SIZE; k ++)
        {
          omp_set_lock(&sem1_done);
          omp_set_lock(&sem2_doing);
          B[k] = Y[k] + A[k-1];
          omp_unset_lock(&sem2_doing);
          omp_unset_lock(&sem1_done);
        }
      }
      #pragma omp section 
      {
        #pragma omp parallel for shared(C,Y,B) private(x)
        for (x = 1; x < SIZE; x++)
        {
          omp_set_lock(&sem2_done);
          C[x] = Y[x] + B[x-1]*2;
          omp_unset_lock(&sem2_done);
        }
      }
  }
  omp_destroy_lock(&sem1_doing);
  omp_destroy_lock(&sem1_done);
  omp_destroy_lock(&sem2_doing);
  omp_destroy_lock(&sem2_done);

  printf("MATRIZ A\n");

  for (int z = 0; z < 1999; z++)
  {
    printf("%d ", A[z]);
  }

  printf("\n");

  printf("MATRIZ B\n");

  for (int z = 0; z < SIZE; z++)
  {
    printf("%d ", B[z]);
  }

  printf("\n");

  printf("MATRIZ C\n");

  for (int z = 0 ; z < SIZE; z++)
    printf("%d ", C[z]);
  
  printf("\n");

  return 0;
}
