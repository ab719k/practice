#include <stdio.h>


typedef struct node {
   int d;
   int *l;
   int *r;
} TREE_NODE;

TREE_NODE* insert(TREE_NODE*, int num) {
   
  if(head->d>num) {
     // insert on the left side
  } else (head->d


}

int main(int argc, char *argv[]) 
{
   TREE_NODE head= (TREE_NODE *) malloc( sizeof(TREE_NODE));
   head->d=-1;
   head->l=NULL;
   head->r=NULL;

   int n;
   int num;
   scanf("%d",&n);
   scanf("%d", &num);
   head->d=num;
   for(int i=1; i<n; i++){
     scanf("%d",&num);
     head=insert(head,num);
   }
}
