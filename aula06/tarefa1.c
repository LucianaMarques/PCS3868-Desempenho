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
    int i,j;
    #pragma parallel for num_threads(2) shared (A,B,C,D) private(i,j)
    for (i = 0; i < SIZE; i ++)
    {
      for (j = 0; j < SIZE; j++)
      {
        A[i][j] = A[i][j]*B[i][j];
        C[i][j] = C[i][j]*D[i][j];
        printf("%d ", A[i][j]);
        printf("%d \n", C[i][j]);
      }
    }
    int k, l;
    #pragma parallel for shared (A,C,R) private(k,l)
    for (k = 0; k < SIZE; k ++)
    {
      for (l = 0; l < SIZE; l++)
      {
        R[k][l] = A[k][l] + C[k][l];
        printf("%d \n", R[k][l]);
      }
    }
  }
  return 0;
}
