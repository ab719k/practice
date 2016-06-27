#include <stdio.h>

void printBits(unsigned int num){
    unsigned int size = sizeof(unsigned int);
    unsigned int maxPow = 1<<(size*8-1);
    printf("MAX POW : %u\n",maxPow);
    int i=0,j;
    for(;i<size;++i){
        for(j=0;j<8;++j){
            // print last bit and shift left.
            printf("%u ",num&maxPow);
            num = num<<1;
        }
    }
}

int main()
{

}
