#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution {
    Node* first;
    Node* middle;
    Node* last;
    Node* previous;

    void findSwappedNodes(Node* root) {
        if (!root) return;

        findSwappedNodes(root->left);

        if (previous && root->data < previous->data) {
            if (!first) {
                first = previous;
                middle = root;
            } else {
                last = root;
            }
        }

        previous = root;
        findSwappedNodes(root->right);
    }

public:
    void recoverTree(Node* root) {
        first = middle = last = previous = nullptr;
        findSwappedNodes(root);

        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(4);
    root->right->right = new Node(9);

    Solution solution;
    solution.recoverTree(root);

    cout << "Corrected inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
