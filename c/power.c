#include<stdio.h>

float power(int x, int y) 
{ 
  float temp;
   if(y == 0)
	return 1;
   temp = power(x,y/2);
   if (y%2 == 0) {
      printf("%f*%f\n",temp,temp);
      return temp*temp;
   }
   else {
    if(y>0) { 
      printf("%d*%f*%f\n",x,temp,temp);
      return x*temp*temp;
    } else {
        printf("(%f*%f)/%d=%f\n",temp,temp,x,(temp*temp)/x);
        return (temp*temp)/x;
    }
  }
}

int main()
{
    float x = 2;
    int n = 2;
    int y = 3;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%f %d", &x, &y);
        printf("%f^%d = %f\n", x, y, power(x,y));
    }
    //getchar();
    return 0;

}

