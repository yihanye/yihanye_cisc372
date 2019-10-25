#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
      #pragma omp critical 
     {
       printf("Hello from thread %d of %d threads\n",omp_get_thread_num(),omp_get_num_threads());
      }
    }
}
