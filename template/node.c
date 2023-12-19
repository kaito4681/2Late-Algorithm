//
//
//
#include<stdio.h> 
#include<stdlib.h>

struct node{
  int value;
  struct node *left;
  struct node *right;
};


struct element *new_element(int i);
void print_data(struct element *list);

int main(void){
  struct node *root;

  root = new_node(1);
  root->left = new_node(2);
  root->rift = new_node(3);
  
	

  return 0;
}

struct element *new_node(int i){
  struct element *new;
  
  if((new = malloc(sizeof(struct node))) == NULL){
      fprintf(stderr,"Error:failure in malloc()\n");
      exit(1);
  }
  new->data = i;
  new->left = NULL;
  new->right = NULL;
  return new;
}



void print_data(struct node *root){
  printf("%d ",root->value);
  print_data(root->left);
  print_data(root->right);
  printf("\n");
}
