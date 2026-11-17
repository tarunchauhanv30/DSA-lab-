#include <iostream>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;
Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

};
Node* insert(Node* root, int value) {
if (root == nullptr) {
    return new Node(value);
}

if (value < root->data) {
    root->left = insert(root->left, value);
} 

else {
    root->right = insert(root->right, value);
}

return root;

}

void inorder(Node* root) {
if (root == nullptr) {
    return;
}

inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

int main() {
int n;

cout << "Enter number of elements: ";
cin >> n;

Node* root = nullptr;
cout << "Enter elements: ";

for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    root = insert(root, value);
}

cout << "Sorted elements: ";
inorder(root);
cout << endl;
return 0;
}
