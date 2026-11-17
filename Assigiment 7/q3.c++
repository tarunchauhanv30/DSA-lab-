#include <iostream>
using namespace std;

struct TreeNode {
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
}
};
void kthSmallest(TreeNode* root, int& k, int& result) {
if (root == nullptr)
    return;

kthSmallest(root->left, k, result);
k--;

if (k == 0) {
    result = root->val;
    return;
}

kthSmallest(root->right, k, result);
}

void kthLargest(TreeNode* root, int& k, int& result) {
if (root == nullptr)
    return;

kthLargest(root->right, k, result);

k--;

if (k == 0) {
    result = root->val;
    return;
}

kthLargest(root->left, k, result);
}
int main() {
TreeNode* root = new TreeNode(5);

root->left = new TreeNode(3);
root->right = new TreeNode(7);

root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);

root->right->left = new TreeNode(6);
root->right->right = new TreeNode(8);

int k = 3;
int k1 = k;
int k2 = k;
int smallest = -1;
int largest = -1;
kthSmallest(root, k1, smallest);
kthLargest(root, k2, largest);
cout << "Kth Smallest = " << smallest << endl;
cout << "Kth Largest = " << largest << endl;
return 0;
}
