#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static inline void swap(int *a, int *b) {
        *a^=*b;
        *b=*a^*b;
        *a^=*b;   
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int ia,ib;
    scanf("%d %d", &ia, &ib);
    int d[26][26];
    int a,b;
    a=ia;
    b=ib;
    if(b>a) {
        swap(&a,&b);
    }
    
    if((a<25) && (b<25)) {        
        goto exit;
    } else if((a>25) && ((a-b)!=2)) {
        goto exit;
    } else if (a==b) {
        goto exit;
    } 
    
    d[0][0]=1;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if((i>0) && (j>0)) {
                printf("d[%d][%d]=%d+%d\n",i,j,d[i-1][j],d[i][j-1]);
                d[i][j]=d[i-1][j]+d[i][j-1];   
            } else if (i>0) {
                d[i][j]=d[i-1][j];
            } else if (j>0) {
                d[i][j]=d[i][j-1];
            }
            printf("d[%d][%d]=%d\n",i,j,d[i][j]);
        }
    }
    
    if(a==25) {
        ret=d[a][b-1];
        goto exit;
    }

exit:
    printf("%d",ret);   
    return 0;
}
