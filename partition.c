/*
main_sort.c
- Practice for writing all the sorting algorithms,
Later can be used as a library of all the sorting functionalities.

*/

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

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
//printf("Partion: Pivot high(%d) low(%d) arr[%d]=%d\n",high,low, high, pivot);
//    printf("partition Before: ");
//    print_ar(high-low, &arr[low]); 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

  //  printf("partition After: ");
  //  print_ar(high-low, &arr[low]); 
    return (i + 1);
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
