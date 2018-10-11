#include <stdio.h>
#include <omp.h>

#define SIZE 2000

int X[SIZE];
int Y[SIZE];
int A[SIZE];
int B[SIZE];
int C[SIZE];

omp_lock_t sem1;
omp_lock_t sem2;

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
      int i,j;
      #pragma omp section
      {
        for (i = 0; i < SIZE - 1; i++)
        {
          omp_set_lock(&sem1);
          A[i] = i*3 + 15;
          omp_set_unlock(&sem1);
        }
      }
      #pragma omp section
      {
        omp_set_lock(&sem2);
        B[0] = 1;
        omp_set_unlock(&sem2);
        int k, l;
        for (k = 1; k < SIZE; k ++)
        {
          omp_set_lock(&sem2);
          B[i] = Y[i] + A[i-1];
          omp_set_unlock(&sem2);
        }
      }
      #pragma omp section
      {
        C[0] = 1;
        int x,w;
        for (x = 1; x < SIZE; x++)
        {
          C[i] = Y[i] + B[i-1]*2;
        }
      }
    }
  }
  omp_destroy_lock(&sem1);
  omp_destroy_lock(&sem2);
  return 0;
}
