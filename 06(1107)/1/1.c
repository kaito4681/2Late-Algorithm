//
// 2023.11.07 1 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int value;
    struct node *left, *right;
};

void print_in_order(struct node *root);
struct node *make_tree(int n);
int highest_tree(struct node *node);

int main(int argc, char *argv[]) {
    int n;
    struct node *root;

    if (argc != 2) {
        fprintf(stderr, "\nUsage: %s positive integer\n\n", argv[0]);
        exit(1);
    }
    srandom(time(NULL));
    n = atoi(argv[1]);
    root = make_tree(n);

    print_in_order(root);
    printf("\n");
    printf("highest of tree = %d\n", highest_tree(root));
    return 0;
}

int highest_tree(struct node *node) {
    int left, right;

    if (node == NULL) {
        return 0;
    } else {
        left = highest_tree(node->left);
        right = highest_tree(node->right);
        if (left + right == 0) {
            return 1;
        } else {
            if (left > right) {
                return 1 + left;
            } else {
                return 1 + right;
            }
        }
    }
}

struct node *make_tree(int n) {
    int i, new_value;
    void add_node(int, struct node *);
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
    struct node *new_node(int);

    if (node->value > num) {
        if (node->left != NULL)
            add_node(num, node->left);
        else
            node->left = new_node(num);
    } else {
        if (node->right != NULL)
            add_node(num, node->right);
        else
            node->right = new_node(num);
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
    } else {
        printf(". ");
    }
}
