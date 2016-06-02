#include <stdio.h>


void print_arr(int n, int *a)
{
  for(int i=0; i < n; i++)
    printf("%d ",a[i]);
    printf("\n");
}

void insertion_sort(int n, int *a)
{
  for(int i=1; i<n;i++)
  {
    int key=a[i];
    int j=i-1;
    while(j>=0 && a[j] > key)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1] = key;
  }
}


int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i < n; i++)
    scanf("%d ", &a[i]);
  print_arr(n,a);

/* Start sorting */
  insertion_sort(n,a);

  print_arr(n,a);

  return 0;
}

