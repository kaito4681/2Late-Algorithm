//
// 2023.11.07 D main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
  int value;
  struct node *left,*right;
};

struct node *maketree(int n);
void print_in_order(struct node *root);
int sum(struct node *);


int main(int argc, char *argv[]) {
  int n;
  struct node *root;

  if(argc != 2){
    fprintf(stderr,"\nUsage: %s positive integer\n\n",argv[0]);
    exit(1);
  }
  srandom(time(NULL));
  n = atoi(argv[1]);
  root = maketree(n);
  
  print_in_order(root);
  printf("\n");
  printf("The sum of value = %d\n",sum(root));
  return 0;
}

int sum(struct node *node){
  if(node == NULL){
    return 0;
  }else{
    return node-> + sum(node->left) + sum(node->right);
  }
}

  

struct node *maketree(int n) {
  int i, new_value;
  void add_node(int ,struct node *);
  struct node *new_node(int i);
  struct node *root = NULL;

  if(n > 0){
    printf("Value: ");
    new_value = random() % 10;
    printf(" %d ", new_value);
    root = new_node(new_value);
    for(i = 1;i < n;i++){
      new_value = random() % 10;
      printf(" %d ",new_value);
      add_node(new_value,root);
    }
    printf("\n");
  } 
  return root;
}

void add_node(int num, struct node *node){
  struct node *new_node(int);

  if(node->value >num){
    if(node->left != NULL) add_node(num,node->left);
    else node->left = new_node(num);
  }else{
    if(node->right != NULL) add_node(num,node->right);
    else node->right = new_node(num);
  }
}



struct node *new_node(int i) {
    struct node *new;

    if ((new = malloc(sizeof(struct node))) == NULL) {
        fprintf(stderr, "Error:failure in malloc()\n");
        exit(1);
    }
    new->value = i;
    new->left = NULL;
    new->right = NULL;
    return new;
}


void print_in_order(struct node *root) {
  if (root != NULL) {
    print_in_order(root->left);
    printf("%d ", root->value);
    print_in_order(root->right);
  }else{
    printf(". ");
  }
}
