#include <stdio.h>
#include <omp.h>
#define MAXRET  1000000
double total_pi = 0.0;
int main()
  {
  int i;
  double x, largura, y;
  largura = 1.0/MAXRET;
  y=0.0;
printf("largura %lf\n",largura);
//omp_set_dynamic(0);
omp_set_num_threads(2);
#pragma omp parallel shared (largura) private(i,x) reduction(+:y)
{
#pragma omp for 
 for (i = 0; i < MAXRET; i++)
   { x = ((i-0.5) * largura);		/* calcula x */
    y = y + (4.0 / ( 1.0 + x * x));
    }
  
}
total_pi = y * largura;
  printf("TOTAL-PI %lf\n",total_pi);
}

