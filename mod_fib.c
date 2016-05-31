#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>


int print=0;



int main() {
    
    int n,i;
    unsigned long int f;
    unsigned long int s=0;
        
    scanf("%lu %lu %d", &f, &s, &n);
    //unsigned long long int a[n+1];
    //unsigned long long int b[n+1];
 
   mpz_t a[n+1];

   mpz_init_set_ui (a[0], f);
   mpz_init_set_ui (a[1], s);

   for( i=2; i<=n;i++) {
      mpz_init (a[i]);    
   }
    
    for( i=2; i<n;i++) {
     mpz_t tmp;
     mpz_init(tmp);
     mpz_mul(&tmp, &a[i-1] , &a[i-1]);
     // void mpz_add (MP_INT *sum, MP_INT *addend1, MP_INT *addend2)        
     mpz_add (&a[i],tmp , &a[i-2]);
 //    gmp_printf ("i(%d) %Zd\n", i,  a[i]);

    }
i--;
    gmp_printf ("%Zd\n", a[i]);

        //printf("%llu\n", fib(n-1));
    //printf("%llu\n", a[i-1]);
    return 0;
    
}

