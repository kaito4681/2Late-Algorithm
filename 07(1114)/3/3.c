//
// 2023.11.14 3 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root, *ans;
struct node *maketree(int n);
void print_in_order(struct node *list);
struct node *bst_search(struct node *p, int data);
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
    ans = bst_search(root, m);
    if (ans == NULL) {
        printf("Miss\n");
    } else {
        printf("Hit\n");
    }

    return 0;
}

struct node *bst_search(struct node *p, int data) {
    if (p == NULL) {
        return NULL;
    }

    if (p->value == data) {
        return p;
    } else if (data < p->value) {
        return bst_search(p->left, data);
    } else {
        return bst_search(p->right, data);
    }
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

void add_node(int num, struct node *root) {
    struct node *new_node(int i);

    while (root != NULL) {
        if (num < root->value) {
            if (root->left == NULL) {
                root->left = new_node(num);
                return;
            }
            root = root->left;
        } else {
            if (root->right == NULL) {
                root->right = new_node(num);
                return;
            }
            root = root->right;
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
