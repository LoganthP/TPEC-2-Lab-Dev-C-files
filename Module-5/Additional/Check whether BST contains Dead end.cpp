#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int checkDeadEnd(struct Node* root, int min, int max) {
    if (root == NULL)
        return 0;
    if (min == max)
        return 1;
    return checkDeadEnd(root->left, min, root->data - 1) ||
           checkDeadEnd(root->right, root->data + 1, max);
}

int containsDeadEnd(struct Node* root) {
    return checkDeadEnd(root, 1, INT_MAX);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);

    if (containsDeadEnd(root))
        printf("BST contains a dead end\n");
    else
        printf("BST does not contain a dead end\n");

    return 0;
}
