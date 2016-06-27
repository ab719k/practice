#include <stdio.h>
#include <string.h>
#include <stdlib.h>


  int max_sub_array(int *a,int n) {
    int max_so_far=0;
    int max_till_i=0;
  
    if(a==NULL)
      return 0;
    if(n==0) {
      return 0;
    }
    max_so_far=a[0];
    for(int i=0; i<n;i++) {
       if (max_so_far < a[i])
         max_so_far=a[i];
    }

    for(int i=0;i<n;i++) {
      max_till_i+=a[i];
      if(max_till_i<0) {
        max_till_i=0;
      }
      else if(max_so_far <  max_till_i) {
          max_so_far=max_till_i;
      }
      printf("%02d  %03d  %d  %d\n", i, a[i], max_till_i, max_so_far);
    }
    return max_so_far;  
  }


int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i<n;i++) {
    scanf("%d",&a[i]);
    printf("%d ", a[i]);
  }
  printf("\n");
  
  printf("Sum=%d\n", max_sub_array(a,n));
}
