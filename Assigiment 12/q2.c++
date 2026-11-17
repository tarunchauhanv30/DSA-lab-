#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    // 0 = Child, 1 = Thread
    bool lthread, rthread;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = false;
    newNode->rthread = false;
    return newNode;
}

// Insert into normal Binary Search Tree
Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else
        root->right = insert(root->right, value);
    return root;
}

// Convert BST into Double Threaded Binary Tree
void convertToThreaded(Node* root, Node*& prev)
{
    if (root == NULL)
        return;

    // Process left subtree
    convertToThreaded(root->left, prev);
    // Create left thread
    if (root->left == NULL)
    {
        root->left = prev;
        root->lthread = true;
    }

    // Create right thread of previous node
    if (prev != NULL && prev->right == NULL)
    {
        prev->right = root;
        prev->rthread = true;
    }
    prev = root; 
    // Process right subtree
    convertToThreaded(root->right, prev);
}

// Find leftmost node
Node* leftMost(Node* root)
{
    if (root == NULL)
        return NULL;
    while (root->lthread == false && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Inorder traversal without recursion or stack
void inorder(Node* root)
{
    Node* current = leftMost(root);
    while (current != NULL)
    {
        cout << current->data << " ";
        // If right pointer is a thread
        if (current->rthread == true)
        {
            current = current->right;
        }
        // Otherwise move to leftmost node of right subtree
        else
        {
            current = leftMost(current->right);
        }
    }
}

int main()
{
    Node* root = NULL;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }
    Node* prev = NULL;

    // Convert into threaded tree
    convertToThreaded(root, prev);
    cout << "\nInorder Traversal: ";
    inorder(root);
    return 0;
}