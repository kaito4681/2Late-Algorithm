//
//2023.11.14 B.c main
//
#include<stdio.h> 
#include<stdlib.h>

struct node{
  int value;
  struct node *left;
  struct node *right;
};

struct node *maketree();
int num_node(struct node *root);

int main(void){
  printf("Number of nodes = %d\n",num_node(NULL));
  printf("Number of nodes = %d\n",num_node(maketree()));
  
  return 0;
}



struct node *maketree(){
  struct node *root;

  root = malloc(sizeof(struct node));
  root->value = 4;
  root->left = malloc(sizeof(struct node));
  root->right = malloc(sizeof(struct node));

  root->left->value = 2;
  root->left->left = malloc(sizeof(struct node));
  root->left->right = NULL;

  root->left->left->value = 1;
  root->left->left->left = NULL;
  root->left->left->right = NULL;
  
  root->right->value = 5;
  root->right->left = NULL;
  root->right->right = malloc(sizeof(struct node));

  root->right->right->value = 8;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

  return root;
}

int num_node(struct node *root){
  if(root == NULL){
    return 0;
  }else{
    return 1 + num_node(root->left) + num_node(root->right);
  }
}