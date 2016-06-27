#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static inline void swap(int *a,int *b) {
    //printf("%d %d\n", *a, *b);
    *a^=*b;
    *b=*a^*b;
    *a^=*b;
    //printf("%d %d\n", *a, *b);
}

int my_pow (int k) {
    if (!k) return 1;
    if (k == 1) return 2;
    int q = my_pow(k / 2);
    q = (1LL * q * q) % 1000000007;
    if (k % 2) return (q + q) % 1000000007; else return q;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int ia,ib,r=0;
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
    }  else if (a==b) {
        goto exit;
    } else if (a==25 && b==24) {
        goto exit;
    }
    
    //memset(d,0,25*25*sizeof(int));
        for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            d[i][j]=0;
         }
        }
    d[0][0]=1;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if (i) 
                d[i][j]+=d[i-1][j];
            if(j) 
                d[i][j]+=d[i][j-1];
            
            d[i][j]%=1000000007;
        }
    }
    
    if(a==25) {
        r = d[a-1][b];
        goto exit;
    }
    else {
        r = d[24][24];
        //printf("ia=%d & ib=%d", ia, ib);
        int p=pow(2, ((ia>ib?ib:ia)) - 24);
        //printf("%d\n",p);
        p=my_pow(((ia>ib?ib:ia)) - 24);  
        //printf("%d\n",p);
        r = (1LL * r * (p)) % 1000000007;
        goto exit;
    }
    
exit:    
    printf("%d",r);
    return 0;
}

