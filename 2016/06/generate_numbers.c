#include <stdio.h>
#include <stdlib.h>

#define max_n 100
int main(int argc, char * argv[])
{
    int n=max_n;
    if (argc > 1)
        n=atoi(argv[1]);
    //printf("%d\n",n);
    
    for(int i=0; i < n; i++)
        printf("%d ", i);
   return 0; 
}