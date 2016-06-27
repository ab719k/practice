/*
main_sort.c
- Practice for writing all the sorting algorithms,
Later can be used as a library of all the sorting functionalities.

*/

#include <stdio.h>
#include <stdlib.h>

enum sorting {
 INSERTION_SORT=0,
 QUICK_SORT,
 MERGE_SORT,
 BUBBLE_SORT,
 SELECTION_SORT 
};

void print_ar(int n, int *ar) {
   for(int i =0; i<n; i++) {
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
    
printf("Partion: Pivot high(%d) low(%d) arr[%d]=%d\n",high,low, high, pivot);
    printf("partition Before: ");
    print_ar(high-low, &arr[low]); 
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

    printf("partition After: ");
    print_ar(high-low, &arr[low]); 
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        printf("Pi high(%d) low(%d) arr[%d]=%d\n",high,low, pi,arr[pi]);
  
        // Separately sort elements before
        // partition and after partition
        printf("quickSort(low, pi-1): ");
        print_ar(pi-1-low, &arr[low]); 
        quickSort(arr, low, pi - 1);
        printf("quickSort(pi+1,high): ");
        print_ar(high-pi, &arr[pi+1]); 
        quickSort(arr, pi + 1, high);
    }
}

int *i_sort(int n, int *ar) 
{
 int j,k;
 printf("\nInsertion Sort \n");
 for(int i=1; i<n ; i++) {
  j=i-1;
  k=ar[i];
  //printf("j(%d) k(%d)i\n",j,k);

  while(j>=0 && ar[j]>k) {
    //if(ar[j]>ar[k]) {
      swap(&ar[j+1],&ar[j]);
      j--; 
     // printf("j(%d):",j);
     // print_ar(n,ar);
  }
  ar[j+1]=k;
  printf("i(%d):",i);  
  print_ar(n,ar);
 } 
 return ar;
}

int *q_sort(int n, int *ar) 
{
 printf("Quick Sort \n");

 quickSort(ar, 0, n-1);
  return ar;
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
  
  switch(choice) {
   case INSERTION_SORT:
        ar=i_sort(n,ar);
        break;
   case QUICK_SORT:
        ar=q_sort(n,ar);
        break;
   case MERGE_SORT:
        ar=m_sort(n,ar);
	break;  
   //case
   default:
        break; 
  }
  
  print_ar(n,ar);
  free(ar);
  return 1;

}
