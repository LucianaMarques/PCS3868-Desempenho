#include <stdio.h>
#include <omp.h>

#define SIZE 2000

int X[SIZE];
int Y[SIZE];

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
  return 0;
}
