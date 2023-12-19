//
// 2023.11.14 2 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root;
struct node *maketree(int n);
void print_in_order(struct node *list);
struct node *bst_delete(struct node **root, int data);
void print_tree(struct node *root, int d);

int main(int argc, char **argv) {
    int n, m;

    if (argc != 3) {
        fprintf(stderr, "\nUsage : %s two integers of positive number \n\n",
                argv[0]);
        exit(1);
    }

    srandom(time(NULL));
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    root = maketree(n);
    print_in_order(root);
    printf("\n\n");
    print_tree(root, 0);
    printf("\n");
    free(bst_delete(&root, m));
    print_in_order(root);
    printf("\n\n");
    print_tree(root, 0);
    printf("\n");

    return 0;
}

struct node *bst_delete(struct node **root, int data) {
    struct node *bst_delete_min(struct node * *root);
    struct node *p, *q;
    if (*root == NULL) {
        return NULL;
    }
    if ((*root)->value == data) {
        if ((*root)->left == NULL) {
            q = *root;
            *root = (*root)->right;
        } else {
            if ((*root)->right == NULL) {
                q = *root;
                *root = (*root)->left;
            } else {
                p = bst_delete_min(&((*root)->right));
                p->left = (*root)->left;
                p->right = (*root)->right;
                q = *root;
                *root = p;
            }
        }
        return q;
    } else {
        if ((*root)->value > data) {
            return bst_delete(&((*root)->left), data);
        } else {
            return bst_delete(&((*root)->right), data);
        }
    }
}

struct node *bst_delete_min(struct node **root) {
    struct node *p, *pp;

    p = *root;
    pp = NULL;
	while(p->left != NULL){
		pp = p;
		p = p->left;
	}
	if(pp == NULL){
		*root = p->right;
	}else{
		pp->left = p->right;
	}
	return p;

}

struct node *maketree(int n) {
    int i, new_value;
    void add_node(int num, struct node *node);
    struct node *new_node(int i);
    struct node *root = NULL;

    if (n > 0) {
        printf("Value: ");
        new_value = random() % 10;
        printf(" %d ", new_value);
        root = new_node(new_value);
        for (i = 1; i < n; i++) {
            new_value = random() % 10;
            printf(" %d ", new_value);
            add_node(new_value, root);
        }
        printf("\n");
    }
    return root;
}

void add_node(int num, struct node *node) {
    struct node *new_node(int i);

    if (node->value > num) {
        if (node->left != NULL) {
            add_node(num, node->left);
        } else {
            node->left = new_node(num);
        }
    } else {
        if (node->right != NULL) {
            add_node(num, node->right);
        } else {
            node->right = new_node(num);
        }
    }
}

struct node *new_node(int i) {
    struct node *new;

    if ((new = malloc(sizeof(struct node))) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
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
    } else {
        printf(". ");
    }
}

void print_tree(struct node *p, int d) {
    if (p != NULL) {
        d++;
        print_tree(p->right, d);
        printf("%*s%5d\n", 3 * d, " ", p->value);
        print_tree(p->left, d);
    }
}
