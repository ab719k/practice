#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COMPACT

typedef struct binary_tree tnode;

struct binary_tree {
    tnode *l;
    tnode *r;
    int val;   
};

enum TREE_CHOICE {
    EXIT,
    DISPLAY_TREE,
    INSERT_ELEMENT,
    FIND_ELEMENT,
    DELETE_ELEMENT,
    DEPTH_OF_TREE,
    DEPTH_OF_ELEM,
    IS_EMPTY,
    IS_FULL
};

#define MAX_ARG 21

/* Local Functions */

tnode *insert_into(tnode *root, int num);
void printTree(tnode *node);
int enter_choice();
int input_handling(int argc, char *argv[]);
tnode * present(tnode *node, int val);
int maxDepth(tnode* node);
int _print_t(tnode *tree, int is_left, int offset, int depth, char s[20][255]);
int print_t(tnode *tree);
tnode * delete_t(tnode *tree, int val);
tnode* get_min_node(tnode *temp);

/*Global Variables*/
int choice;
int count;
int total_count;

int input_numbers[MAX_ARG];


#define SUCCESS 1
#define FAIL -1


int main(int argc, char *argv[])
{

    tnode *root=NULL;
    tnode *temp=NULL;
    int value=0;
    
    
    choice = input_handling(argc,argv) ;
    if( choice != SUCCESS)
       return choice;

   /* Start Creating Tree */
    while (total_count) {
        printf("While Total Count = %d, Inserting %d \n", total_count, input_numbers[total_count-1]);
        root = insert_into(root, input_numbers[total_count-1]);
        total_count--;
    } /* while (total_count) */
    
    printf("\n\nThe tree so far \n\n");
    //printTree(root);
    //printf("\n\nAnother version of The tree so far \n\n");
    print_t(root);
    //printf("\n\n");
    choice = 1;
    while (choice) {
        choice = enter_choice();
        switch(choice) {
            case EXIT:
                return 0;
            case DISPLAY_TREE:
                printf("\n\n Printing Tree \n\n");
                //printTree(root);
                print_t(root);
                break;
            case INSERT_ELEMENT:
                printf("\n\n Insert Element : ");
                scanf("%d", &value);
                root = insert_into(root,value);
                break;
            case FIND_ELEMENT:
                printf("\n\n Find Element : \n\n");
                scanf("%d", &value);
                if (NULL==present(root,value)) {
                    printf("\nElement not found, ");
                }
                break;
            case DELETE_ELEMENT:
                print_t(root);
                printf("\nElement to delete: ");
                scanf("%d",&value);
                root = delete_t(root,value);
                printTree(root);
                printf("\nElement Deleted\n");
                print_t(root);
                break;
            case DEPTH_OF_TREE:
                printf("The max depth of tree is: %d", maxDepth(root));
                break;
            case IS_EMPTY:
                
                break;
            case IS_FULL:
                
                break;
            default:
                
                break;
      }
       
    }
    printf("The command had no other arguments.\n");

    return choice;
    
} /* int main(int argc, char *argv[])*/



tnode* get_min_node(tnode *temp)
{
    tnode *mn;
    mn=temp;
    while (mn->l != NULL)
        mn=mn->l;
    return mn;
}


tnode * delete_t(tnode *node, int val)
{
    tnode *mn;
    tnode *temp;
    
    if (node==NULL) {
        printf("\n\nElement not found");
        return node;
    }
    
    if (val < node->val) {
        node = delete_t(node->l,val);
    } else if(val > node->val){
        node = delete_t(node->r,val);
    } else {
        printf("\n\n Element Found");
        /* delete the node */
        if ( node->l == NULL) {
            mn=node->r;
            free(node);
            return mn;
        } else if (node->r == NULL) {
            mn=node->l;
            free(node);
            return mn;
        }
        mn=node;
        while (mn->l != NULL)
            mn=mn->l;
        node->val=mn->l->val;
        
        free(mn->l);
        mn->l=NULL;
    }
    return node;
}


int _print_t(tnode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;
    
    if (!tree) return 0;
    
    sprintf(b, "(%03d)", tree->val);
    
    int left  = _print_t(tree->l,  1, offset,                depth + 1, s);
    int right = _print_t(tree->r, 0, offset + left + width, depth + 1, s);
    
#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    
    if (depth && is_left) {
        
        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';
        
        s[depth - 1][offset + left + width/2] = '.';
        
    } else if (depth && !is_left) {
        
        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';
        
        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];
    
    if (depth && is_left) {
        
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';
        
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';
        
    } else if (depth && !is_left) {
        
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';
        
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif
    
    return left + width + right;
}

int print_t(tnode *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");
    
    _print_t(tree, 0, 0, 0, s);
    
    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
    return 0;
}


/* This function handles the input */
int input_handling(int argc, char *argv[])
{
    printf ("This program was called with argc = %d && argv[0] = \"%s\".\n",argc, argv[0]);
    if (argc > MAX_ARG + 1)
    {
        printf("Incorrect usage: overflow parameters \n");
        return -1;
    }
    
    if (argc == 1)
    {
        printf("Incorrect usage: unsufficient parameters \n");
        return -1;
    }
    if (argc > 1)
    {
        for (count = 1; count < argc; count++)
        {
            printf("argv[%d] = %s\n", count, argv[count]);
            input_numbers[total_count++] = atoi(argv[count]);
        }
    }
    else
    {
        printf("The command had no other arguments.\n");
    }
    
    printf("Total Count = %d \n", total_count);
    return 1;


} /* end of input_handling */


#if 0
inline temp_node * new_node()
{
    temp_node *node;
    
    temp = malloc(sizeof(tnode));
    temp->l = temp->r = NULL;
    temp->val = num;
}
#else

#define INSERT_NODE(temp, num)   temp = malloc(sizeof(tnode)); \
temp->l = temp->r = NULL; \
temp->val = num

#endif

int enter_choice()
{
  int choice;
  printf("Choose one of the following or 0 to exit\n");
  printf("1 to DISPLAY_TREE\n");
  printf("2 to INSERT_ELEMENT\n");
  printf("3 to FIND_ELEMENT\n");
  printf("4 to DELETE_ELEMENT\n");
  printf("5 to DEPTH_OF_TREE\n");
  printf("6 to DEPT_OF_ELEM\n");
  printf("7 to IS_EMPTY\n");
  printf("8 to IS_FULL\n");
  printf("Enter your choice :");

  scanf("%d", &choice);

  return choice;
}

tnode * insert_into(tnode *node, int num)
{
    
  struct binary_tree *temp = NULL;
    if (node != NULL)
    {
        printf("At %d\n", node->val);
    }
    else
    {
        INSERT_NODE(temp,num);
        return temp;
    }
    
    if(node->val > num)
    {
       node->l = insert_into(node->l, num);
    } else if (node->val < num)
    {
      node->r = insert_into(node->r, num);
    }
    else
    {
        printf("Duplicate Entry Not added!");
    }
    return node;
}


/*
 Given a binary search tree, print out
 its data elements in increasing
 sorted order.
 */
void printTree(tnode *node) {
    
    if (node == NULL) return;
    printTree(node->l);
    if (node != NULL)
    printf("%d ", node->val);
    else printf(" NULL ");
    printTree(node->r);
    //printf("/n");
}


/*
 Given a binary search tree, find out
 if data elements is present.
 */
tnode * present(tnode *node, int val)
{
    tnode* temp = node;
    
    while (temp != NULL) {
        if (temp->val == val) {
            printf("Element Found");
            return temp;
        }
        else if (val < temp->val) {
            temp=temp->l;
        }
        else {
            temp=temp->r;
        }
        
    }
    return temp;
}

/*
 Compute the "maxDepth" of a tree -- the number of nodes along
 the longest path from the root node down to the farthest leaf node.
 */
int maxDepth(tnode* node) {
    if (node==NULL) {
        return(0);
    }
    else {
        // compute the depth of each subtree
        int lD = maxDepth(node->l);
        int rD = maxDepth(node->r);
        // use the larger one
        if (lD > rD)
            return(lD+1);
        else
            return(rD+1);
  
    }
    return 0;
}
