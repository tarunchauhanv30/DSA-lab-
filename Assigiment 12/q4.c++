#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root, int k, int &count, int &ans) {

    if (root == NULL)
        return;

    // Step 1: Visit left subtree
    inorder(root->left, k, count, ans);

    // Step 2: Visit root
    count++;

    if (count == k) {
        ans = root->data;
        return;
    }

    // Step 3: Visit right subtree
    inorder(root->right, k, count, ans);
}

int kthSmallest(Node* root, int k) {

    if (root == NULL || k <= 0)
        return -1;

    int count = 0;
    int ans = -1;

    inorder(root, k, count, ans);

    return ans;
}

int main() {

    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    int k;

    cout << "Enter k: ";
    cin >> k;

    int result = kthSmallest(root, k);

    if (result == -1)
        cout << "Invalid k";
    else
        cout << "Kth smallest element: " << result;

    return 0;
}