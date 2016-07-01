#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, 
   l  --> Starting index, 
   h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
	printf("\n");
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int check_swap(int *A, int N)
{
	int B[N];
	int cnt=0;
	memcpy(B, A, N*sizeof(int));
	//quickSortIterative( B, 0, N - 1 );
	qsort(B, N, sizeof(int), cmpfunc);
	printArr(A,N);
	printArr(B,N);
	for(int i=0;i<N;i++) {
		if(A[i] != B[i]) {
			cnt++;
		}
	}
	if(cnt>2)
		return 0;
	return 1;
	
	
	
}


int main()
{
	int k;
	scanf("%d",&k);
	for (int j=0; j<k;j++) {
		int n;
		scanf("%d",&n);
		int A[n];
		for(int i=0;i<n;i++) {
			scanf("%d", &A[i]);
		}
		if (check_swap(A,n))
			printf("%d: TRUE\n",j);
		else
			printf("%d: FALSE\n",j);
	}
	
}