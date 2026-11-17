#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Info {
    int isBST, sum, min, max;
};

int maxSum = INT_MIN;
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Info solve(struct Node* root) {
    if (root == NULL)
        return (struct Info){1, 0, INT_MAX, INT_MIN};
    struct Info l = solve(root->left);
    struct Info r = solve(root->right);
    struct Info t;

    if (l.isBST && r.isBST &&
        root->data > l.max && root->data < r.min) {

        t.isBST = 1;
        t.sum = l.sum + r.sum + root->data;
        t.min = root->left ? l.min : root->data;
        t.max = root->right ? r.max : root->data;

        if (t.sum > maxSum)
            maxSum = t.sum;
    } else {
        t = (struct Info){0, 0, INT_MIN, INT_MAX};
    }

    return t;
}

int main() {
    struct Node* root = newNode(5);

    root->left = newNode(4);
    root->right = newNode(8);

    root->left->left = newNode(3);
    root->left->right = newNode(6);

    root->right->left = newNode(7);
    root->right->right = newNode(9);

    solve(root);

    printf("Maximum BST subtree sum = %d\n", maxSum);

    return 0;
}