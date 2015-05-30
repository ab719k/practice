#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct binary_tree tree_node;

struct binary_tree {
 tree_node *l;
 tree_node *r;
 int val;   
};

enum TREE_CHOICE
{
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

void insert_into(tree_node *root, int num);
void print_tree(tree_node *root);
int print_choice();

int main(int argc, char *argv[])
{
  int count, choice;
  int total_count=0;
  
  int input_numbers[MAX_ARG];
  struct binary_tree *root=NULL;
  struct binary_tree *temp=NULL;

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

   /* Start Creating Tree */
   if (root == NULL)
   {
      root = malloc(sizeof(tree_node));
      root->l = root->r = NULL;
      root->val = input_numbers[total_count--];
   } /* if (root == NULL) */
   while (total_count)
   {
    printf("While Total Count = %d \n", total_count);
    insert_into(root, input_numbers[total_count--]);
   } /* while (total_count) */


   while (choice = print_choice())
   {
      switch(choice)
      {
      case EXIT:
         return;
      case DISPLAY_TREE:
      case INSERT_ELEMENT:
      case FIND_ELEMENT:
      case DELETE_ELEMENT:
      case DEPTH_OF_TREE:
      case IS_EMPTY:
        break;
      case IS_FULL:
         break;
      }
   }
   printf("The command had no other arguments.\n");
       

} /* int main(int argc, char *argv[])*/

#define INSERT_NODE(temp, num)   temp = malloc(sizeof(tree_node)); \
                     temp->l = temp->r = NULL; \
                     temp->val = num


int print_choice()
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

tree_node insert_into(tree_node *root, int num)
{

  struct binary_tree *temp = NULL;
    if (root != NULL)
    {
        
    }
    else
    {
        printf("At node %d Insert into tree the number = %d \n", root->val, num);
        INSERT_NODE(temp,num);
        return temp;
    }
    
    if(root->val > num)
    {
       root->l = insert_into(root->l, num);
    } else if (root->val < num)
    {
      root->r = insert_into(root->r, num);
    }
}







#if 0
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!Code originally from /http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/
!!! Just saved it, cause the website is down.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Printing Binary Trees in Ascii

Here we are not going to discuss what binary trees are (please refer this, if you are looking for binary search trees), or their operations but printing them in ascii.

The below routine prints tree in ascii for a given Tree representation which contains list of nodes, and node structure is this
*/
    struct Tree 
    {
      Tree * left, * right;
      int element;
    };

/*This pic illustrates what the below routine does on canvas..
ascii tree

Here is the printing routine..

    b5855d39a6b8a2735ddcaa04a404c125001 

Auxiliary routines..
*/
    //This function prints the given level of the given tree, assuming
    //that the node has the given x cordinate.
    void print_level(asciinode *node, int x, int level) 
    {
      int i, isleft;
      if (node == NULL) return;
      isleft = (node->parent_dir == -1);
      if (level == 0) 
      {
        for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++) 
        {
          printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
      } 
      else if (node->edge_length >= level) 
      {
        if (node->left != NULL) 
        {
          for (i=0; i<(x-print_next-(level)); i++) 
          {
            printf(" ");
          }
          print_next += i;
          printf("/");
          print_next++;
        }
        if (node->right != NULL) 
        {
          for (i=0; i<(x-print_next+(level)); i++) 
          {
            printf(" ");
          }
          print_next += i;
          printf("\\");
          print_next++;
        }
      } 
      else 
      {
        print_level(node->left, 
                    x-node->edge_length-1, 
                    level-node->edge_length-1);
        print_level(node->right, 
                    x+node->edge_length+1, 
                    level-node->edge_length-1);
      }
    }


    //This function fills in the edge_length and 
    //height fields of the specified tree
    void compute_edge_lengths(asciinode *node) 
    {
      int h, hmin, i, delta;
      if (node == NULL) return;
      compute_edge_lengths(node->left);
      compute_edge_lengths(node->right);

      /* first fill in the edge_length of node */
      if (node->right == NULL && node->left == NULL) 
      {
        node->edge_length = 0;
      } 
      else 
      {
        if (node->left != NULL) 
        {
          for (i=0; i<node->left->height && i < MAX_HEIGHT; i++) 
          {
            rprofile[i] = -INFINITY;
          }
          compute_rprofile(node->left, 0, 0);
          hmin = node->left->height;
        } 
        else 
        {
          hmin = 0;
        }
        if (node->right != NULL) 
        {
          for (i=0; i<node->right->height && i < MAX_HEIGHT; i++) 
          {
            lprofile[i] = INFINITY;
          }
          compute_lprofile(node->right, 0, 0);
          hmin = MIN(node->right->height, hmin);
        } 
        else 
        {
          hmin = 0;
        }
        delta = 4;
        for (i=0; i<hmin; i++) 
        {
          delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }

        //If the node has two children of height 1, then we allow the
        //two leaves to be within 1, instead of 2 
        if (((node->left != NULL && node->left->height == 1) ||
              (node->right != NULL && node->right->height == 1))&&delta>4) 
        {
          delta--;
        }

        node->edge_length = ((delta+1)/2) - 1;
      }

      //now fill in the height of node
      h = 1;
      if (node->left != NULL) 
      {
        h = MAX(node->left->height + node->edge_length + 1, h);
      }
      if (node->right != NULL) 
      {
        h = MAX(node->right->height + node->edge_length + 1, h);
      }
      node->height = h;
    }

    asciinode * build_ascii_tree_recursive(Tree * t) 
    {
      asciinode * node;

      if (t == NULL) return NULL;

      node = malloc(sizeof(asciinode));
      node->left = build_ascii_tree_recursive(t->left);
      node->right = build_ascii_tree_recursive(t->right);

      if (node->left != NULL) 
      {
        node->left->parent_dir = -1;
      }

      if (node->right != NULL) 
      {
        node->right->parent_dir = 1;
      }

      sprintf(node->label, "%d", t->element);
      node->lablen = strlen(node->label);

      return node;
    }


    //Copy the tree into the ascii node structre
    asciinode * build_ascii_tree(Tree * t) 
    {
      asciinode *node;
      if (t == NULL) return NULL;
      node = build_ascii_tree_recursive(t);
      node->parent_dir = 0;
      return node;
    }

    //Free all the nodes of the given tree
    void free_ascii_tree(asciinode *node) 
    {
      if (node == NULL) return;
      free_ascii_tree(node->left);
      free_ascii_tree(node->right);
      free(node);
    }

    //The following function fills in the lprofile array for the given tree.
    //It assumes that the center of the label of the root of this tree
    //is located at a position (x,y).  It assumes that the edge_length
    //fields have been computed for this tree.
    void compute_lprofile(asciinode *node, int x, int y) 
    {
      int i, isleft;
      if (node == NULL) return;
      isleft = (node->parent_dir == -1);
      lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
      if (node->left != NULL) 
      {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
        {
          lprofile[y+i] = MIN(lprofile[y+i], x-i);
        }
      }
      compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
      compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
    }

    void compute_rprofile(asciinode *node, int x, int y) 
    {
      int i, notleft;
      if (node == NULL) return;
      notleft = (node->parent_dir != -1);
      rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
      if (node->right != NULL) 
      {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
        {
          rprofile[y+i] = MAX(rprofile[y+i], x+i);
        }
      }
      compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
      compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
    }

/*
Here is the asciii tree structure…
*/
    struct asciinode_struct
    {
      asciinode * left, * right;

      //length of the edge from this node to its children
      int edge_length; 

      int height;      

      int lablen;

      //-1=I am left, 0=I am root, 1=right   
      int parent_dir;   

      //max supported unit32 in dec, 10 digits max
      char label[11];  
    };

#endif

