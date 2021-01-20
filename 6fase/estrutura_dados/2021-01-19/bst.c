#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 10


/* STRUCTS */

struct integer {
    int value;
    struct integer *left;
    struct integer *right;
};

typedef struct integer Node;

typedef struct {
    Node *root;
} Tree;


/* METHODS */

Tree* initialize() {
    Tree *tree = malloc(sizeof(tree));

    tree->root = NULL;
    
    return tree;
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        Node *new = malloc(sizeof(Node));

        new->value = value;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }

    return root;
}

Node* search(Node *node, int value) {
    if (node->value == value || node->value == '\0') {
        return node;
    } else if (value > node->value) {
        return search(node->right, value);
    } else {
        return search(node->left, value);
    }
}

void print_preo(Node *node) {
    if (node != NULL) {
        printf("|%d|", node->value);
        print_preo(node->left);
        print_preo(node->right);
    }
}

void print_ino(Node *node) {
    if (node != NULL) {
        print_ino(node->left);
        printf("|%d|", node->value);
        print_ino(node->right);
    }
}

void print_poso(Node *node) {
    if (node != NULL) {
        print_poso(node->left);
        print_poso(node->right);
        printf("|%d|", node->value);
    }
}

void print_zeroes(int count) {
    for (int i = 0; i < count; ++i) {
        printf("0");
    }
}

void free_tree(Tree *tree) {
    free(tree);
}


int main() {
    int n = 0, o = 0, i = 0;
    char input[MAX];

    Tree *tree;

    scanf("%d\n", &n);

    do {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        o = atoi(&input[0]);

        switch (o) {
            case 1:
                tree = initialize(tree);
                break;

            case 2:
                tree->root = insert(tree->root, atoi(&input[2]));
                i++;
                break;

            case 3:
                print_preo(tree->root);
                printf("\n");
                break;

            case 4:
                print_ino(tree->root);
                printf("\n");
                break;

            case 5:
                print_poso(tree->root);
                printf("\n");
                break;

            case 6:
                free_tree(tree);
                break;

            default:
                return 1;
        }
    } while (o != 6);
    
    print_zeroes(i);
    printf("\n");

    return 0;
}
