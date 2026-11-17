#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *first = NULL;
struct Node *middle = NULL;
struct Node *last = NULL;
struct Node *prev = NULL;

void findSwappedNodes(struct Node* root) {
    if (root == NULL)
        return;

    findSwappedNodes(root->left);

    if (prev != NULL && root->data < prev->data) {
        if (first == NULL) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }

    prev = root;

    findSwappedNodes(root->right);
}

void recoverBST(struct Node* root) {
    first = middle = last = prev = NULL;

    findSwappedNodes(root);

    if (first != NULL && last != NULL) {
        int temp = first->data;
        first->data = last->data;
        last->data = temp;
    } else if (first != NULL && middle != NULL) {
        int temp = first->data;
        first->data = middle->data;
        middle->data = temp;
    }
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = createNode(6);

    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(7);
    root->right->left = createNode(4);
    root->right->right = createNode(9);

    printf("Before Recovery: ");
    inorder(root);
    recoverBST(root);
    printf("\nAfter Recovery: ");
    inorder(root);
    return 0;
}