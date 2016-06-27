/**?
 * What is the purpose of this file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

typdef struct Node node;

struct Node {
  int v;
  node *n;
};
  

void error(const char *msg)
{
    perror(msg);
    exit(1);
}


node * insert(node *head, int val)
{
  node *temp=head;
  
  while(temp->n) 
    temp=temp->n;
  temp->n = (node *) malloc(sizeof(node));
  temp->v=val;
  temp->n->n=NULL;

  return head;

}


void main()
{
  node *head;
  int n;

  //initialize variables
  head=(node *) malloc(sizeof(node));
  scanf("%d", &n);


  
}
