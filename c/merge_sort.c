/* merge_sort.c */

#include <stdio.h>
#include <stdlib.h>


void print_ar(int n, int *ar) {
   for(int i=0; i<n; i++) {
      printf("%02d ",ar[i]);
   }
   printf("\n");
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

 



int main(int argc, char*argv[]) 
{
    int n; 
    int choice;
    
    scanf("%d", &choice);
    scanf("%d", &n);
    int *ar;
    ar= (int *) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) { 
       scanf("%d", &ar[i]); 
    }

  // ar stores the elements of the array.
  print_ar(n,ar);
  
  printf("Partition:(%d)", partition(ar,0,n-1));
   
  print_ar(n,ar);
  free(ar);
  return 1;

}
