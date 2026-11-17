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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

#define MAX 100
struct Stack {
    struct Node* arr[MAX];
    int top;
};

void push(struct Stack* s, struct Node* node) {
    if (s->top < MAX - 1)
        s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    if (s->top == -1)
        return NULL;

    return s->arr[s->top--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void initialize(struct Stack* s) {
    s->top = -1;
}

void initializePredecessor(struct Stack* s,
                           struct Node* root, int x) {
    while (root != NULL) {
        if (root->data <= x) {
            push(s, root);
            root = root->right;
        } else {
            root = root->left;
        }
    }
}
void initializeSuccessor(struct Stack* s,
                         struct Node* root, int x) {
    while (root != NULL) {
        if (root->data > x) {
            push(s, root);
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

struct Node* getPredecessor(struct Stack* s) {
    struct Node* node = pop(s);
    if (node != NULL) {
        initializePredecessor(s, node->left, node->data - 1);
    }
    return node;
}

struct Node* getSuccessor(struct Stack* s) {
    struct Node* node = pop(s);
    if (node != NULL) {
        initializeSuccessor(s, node->right, node->data);
    }
    return node;
}

void findClosest(struct Node* root, int x, int k) {
    struct Stack pred, succ;
    initialize(&pred);
    initialize(&succ);
    initializePredecessor(&pred, root, x);
    initializeSuccessor(&succ, root, x);

    for (int i = 0; i < k; i++) {
        if (isEmpty(&pred) && isEmpty(&succ))
            break;
        if (isEmpty(&pred)) {
            struct Node* s = getSuccessor(&succ);
            printf("%d ", s->data);
        } else if (isEmpty(&succ)) {
            struct Node* p = getPredecessor(&pred);
            printf("%d ", p->data);
        } else {

            struct Node* p = pred.arr[pred.top];
            struct Node* s = succ.arr[succ.top];
            int d1 = abs(p->data - x);
            int d2 = abs(s->data - x);

            if (d1 <= d2) {
                printf("%d ", getPredecessor(&pred)->data);
            } else {
                printf("%d ", getSuccessor(&succ)->data);
            }
        }
    }
}

int main() {

    struct Node* root = NULL;
    int values[] = {10, 5, 15, 2, 7, 12, 20, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    int x = 9;
    int k = 4;
    printf("K Closest Values: ");
    findClosest(root, x, k);

    return 0;
}