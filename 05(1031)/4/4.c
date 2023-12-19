//
// 2023.10.31 4 main
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *maketree();
void pre_order(struct node *root);
void in_order(struct node *root);
void post_order(struct node *root);

int main(void) {
    struct node *root;

    root = maketree();

    pre_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    post_order(root);
    printf("\n");
    return 0;
}

struct node *maketree() {
    struct node *new_node(int i);
	struct node *root = new_node(1);

    root->left = new_node(3);
    root->right = new_node(7);
    root->left->right = new_node(4);
    root->left->right->left = new_node(5);
    return root;
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

void pre_order(struct node *root) {
    if (root == NULL) {
        printf(". ");
    } else {
        printf("%d ",root->value);
        pre_order(root->left);
        pre_order(root->right);
    }
}
void in_order(struct node *root) {
    if (root == NULL) {
        printf(". ");
    } else {
        in_order(root->left);
        printf("%d ", root->value);
        in_order(root->right);
    }
}

void post_order(struct node *root) {
    if (root == NULL) {
        printf(". ");
    } else {
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->value);
    }
}