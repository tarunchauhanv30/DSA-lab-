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
bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {

if (leftNode == nullptr && rightNode == nullptr) {
    return true;
}

if (leftNode == nullptr || rightNode == nullptr) {
    return false;
}

if (leftNode->val != rightNode->val) {
    return false;
}

return isMirror(leftNode->left, rightNode->right) &&
       isMirror(leftNode->right, rightNode->left);
}
bool isSymmetric(TreeNode* root) {
if (root == nullptr) {
    return true;
}
return isMirror(root->left, root->right);
}

int main() {
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(2);
root->left->left = new TreeNode(6);
root->left->right = new TreeNode(7);
root->right->left = new TreeNode(7);
root->right->right = new TreeNode(6);


if (isSymmetric(root)) {
    cout << "Symmetric" << endl;
} else {
    cout << "Not Symmetric" << endl;
}
return 0;
}
