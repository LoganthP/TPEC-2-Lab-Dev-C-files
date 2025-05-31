#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int areMirror(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->val == root2->val) &&
           areMirror(root1->left, root2->right) &&
           areMirror(root1->right, root2->left);
}

int main() {
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);

    printf("%s\n", areMirror(root1, root2) ? "true" : "false");

    return 0;
}
