#include <stdio.h>
#include <omp.h>

#define SIZE 2000

int X[SIZE];
int Y[SIZE];
int A[SIZE];
int B[SIZE];
int C[SIZE];

omp_lock_t sem1_done;
omp_lock_t sem1_doing;
omp_lock_t sem2_done;
omp_lock_t sem2_doing;

int i, k, x, j;

int main()
{
  //sequential initialization of X and Y
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      X[i] = i;
      Y[i] = i + 1;
    }
  }
  omp_init_lock(&sem1);
  omp_init_lock(&sem2);
  omp_set_num_threads(3);
  #pragma omp parallel sections
  {
    #pragma omp sections
    {
      #pragma omp section shared(A) private(i)
      {
        #pragma parallel for
        for (i = 0; i < SIZE - 1; i++)
        {
          A[i] = i*3 + 15;
        }
      }
      int k;
      #pragma omp section shared (B,Y,A) private(k)
      {
        omp_set_lock(&sem2);
        B[0] = 1;
        omp_set_unlock(&sem2);
        #pragma parallel for
        for (k = 1; k < SIZE; k ++)
        {
          omp_set_lock(&sem1);
          omp_set_lock(&sem2);
          B[k] = Y[k] + A[k-1];
          omp_set_unlock(&sem2);
        }
      }
      #pragma omp section shared(C,Y,B) private(x)
      {
        C[0] = 1;
        #pragma parallel for
        for (x = 1; x < SIZE; x++)
        {
          while(omp_test_lock(&sem2))
          {

          }
          C[x] = Y[x] + B[x-1]*2;
        }
      }
    }
  }
  omp_destroy_lock(&sem1);
  omp_destroy_lock(&sem2);
  return 0;
}
