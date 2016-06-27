/*

AMITB Library

*/
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef ERROR
#define ERROR -1
#endif

/*c function to check if a character is digit */
char ab_isdigit(char a) {
    int tmp=(a-'0');
    return (tmp < 9) && (tmp > 0);
}



/*Sqrt by babylonian method */
int ab_sqrt(int n) {
    float x=n;
    float y=1;
    float e=0.0001;
    
    while(x-y>e) {
        x=(x+y)/2
        y=x/n;
    }
    return x;
}




int ab_is_prime(int n) {

    if (n<0) {
        return ERROR;
#ifdef DEBUG
    DEBUG_PRINT(ERROR, ("n(%d) should be > 0", n));
#endif   
    
    }
    
    if (n==1)
        return FALSE;
    if (n==2)
        return TRUE;
    if (n%2==0)
        return FALSE;
    int s_n=sqrt(n);
    for (i=0;i<s_n;i+=2) {
        if(n%i==0)
            return FALSE;
    }
}




/* TREE Library */
/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/
void ab_preOrder(node *r) {

    if(r==NULL) 
        return;
    printf("%d ", r->data);
    preOrder(r->left);
    preOrder(r->right);

}

void ab_postOrder(node *r) {

    if(r==NULL) 
        return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->data);
}



void ab_inOrder(node *root) {
    if(r==NULL) 
        return;
    inOrder(r->left);
    printf("%d ", r->data);
    inOrder(r->right);
}

inline int ab_max(int a, b) {
    return a>b?a:b;
}


/* height of the tree is the height of the edges. */
int height(node *r) {
    if (r==NULL) 
        return -1;
    return(1+ab_max(height(r->left),height(r->right)));
}



inline void t_lview(node *r) {
    if(r==NULL) {
        return;
    } 
    t_lview(r->left);
    printf("%d ", r->data);
}
inline t_rview(node *r) {
    if(r==NULL) {
        return;
    }
    printf("%d ", r->data);
    t_rview(r->right);
}

void ab_top_view(node * r)
{
    if(r==NULL) {
        return ;
    } 
    t_lview(r->left);
    printf("%d ", r->data);
    t_rview(r->right);
}




/* height of the tree is the height of the edges. */
int height(node *r) {
    if (r==NULL) 
        return -1;
    return(1+max(height(r->left),height(r->right)));
}

/*
You are given a pointer to the root of a binary tree. 
You need to print the level order traversal of this tree. 
In level order traversal, we visit the nodes level by level from left to right. 
*/
void print_level(node * r, int l) {
    if(r==NULL) {
        return;
    }
    if(height(r)==l) {
         printf("%d ", r->data);
    }
    print_level(r->left, l);
    print_level(r->right, l);
}
    
void LevelOrder(node * r)
{
    for(int i=height(r); i>=0; i--)
        print_level(r,i);
    
    return;
}
