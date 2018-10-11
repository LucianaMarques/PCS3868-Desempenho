#include <stdio.h>
#include <omp.h>
#define SIZE 1000

int A [SIZE][SIZE];
int B [SIZE][SIZE];
int C [SIZE][SIZE];
int D [SIZE][SIZE];
int R [SIZE][SIZE];

void populate(int A[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      A[i][j] = 1;
    }
  }
}

int main(){
  populate(A);
  populate(B);
  populate(C);
  populate(D);
  omp_set_num_threads(2);
  #pragma omp
  {
    #pragma parallel for num_threads(2)
    for (int i = 0; i < SIZE; i ++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        A[i][j] = A[i][j]*B[i][j];
        C[i][j] = C[i][j]*D[i][j];
        printf("%d ", A[i][j]);
        printf("%d \n", C[i][j]);
      }
    }
    #pragma parallel for
    for (int i = 0; i < SIZE; i ++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        R[i][j] = A[i][j] + C[i][j];
        printf("%d \n", R[i][j]);
      }
    }
  }
  return 0;
}
