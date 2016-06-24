#include <stdio.h>
#include <stdlib.h>

// Babylonian method
int my_sqrt(float n) 
{
    float x=n;
    float y=1;
    float e=0.00001;
    
    while(x-y>e) {
        printf("x(%.2f),y(%.2f),n(%.2f)\n",x,y,n);
        x=(x+y)/2;
        y=n/x;
    }
    
    return x;
}

int main (int argc, char*argv[])
{
  if(argc==1) {
    printf("Correct usage ./sqrt n");
    return -1;
  }
  int s = atoi(argv[1]);
  
  printf("sqrt(%d) = %d\n", s, my_sqrt(s));
  //getchar();
  return 0;
}