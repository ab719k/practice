#include <stdio.h>
#include <stdlib.h>


const int MAX_ARRAY 1000


void swap(int x, int y) {
  x=x^y;
  y=x^y;
  x=x^y;
}

typedef struct Maze_cell {
  int state;
  int visited;
  int blocked;
} MCell;

int maze(int M, int x, int y, int Nx,Ny);
int create_random_blocks(int **M,int x, int y);

int main(int argc, char *argv[]) 
{
  int Nx,Ny;
  int x,y;
  scanf("%d %d", &x, &y);
  scanf("%d %d", &Nx, &Ny);
  

  if(Nx<x)
    swap(&Nx,&x);
  if(Ny<y)
    swap(&Ny,&y);

  int M[Nx][Ny];

  create_random_blocks(M,Nx,Ny);
  int d=maze(M,x,y,Nx,Ny);

  printf("The distance is %d", d);

}



int maze(int M, int x, int y, int Nx,Ny) {  
  return 0;
}

int create_random_blocks(int **M,int x, int y) {
  int i,j;

  for(int i=0; i<x;i++)
  {
    if((random()%2)==0) {
        
    }
  }
}

