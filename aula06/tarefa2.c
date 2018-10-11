#include <stdio.h>
#include <omp.h>

#define SIZE 2000

int X[SIZE];
int Y[SIZE];
int A[SIZE];
int B[SIZE];
int C[SIZE];

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
  #pragma omp sections
  {
    int i,j;
    #pragma omp section
    {
      for (i = 0; i < SIZE - 1; i++)
      {
        A[i] = i*3 + 15;
      }
    }
    #pragma omp section
    {
      B[0] = 1;
      int k, l;
      for (k = 1; k < SIZE; k ++)
      {
        B[0] = Y[i] + A[i-1];
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
  return 0;
}
