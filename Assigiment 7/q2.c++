#include <iostream>
#include <algorithm>

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
int minDepth(TreeNode* root) {
if (root == nullptr) {
    return 0;
}


if (root->left == nullptr) {
    return 1 + minDepth(root->right);
}
if (root->right == nullptr) {
    return 1 + minDepth(root->left);
}
return 1 + min(minDepth(root->left),
              minDepth(root->right));
}

int main() {
TreeNode* root = new TreeNode(1);

root->left = new TreeNode(2);
root->right = new TreeNode(3);

root->left->left = new TreeNode(8);
root->left->right = new TreeNode(9);

root->left->left->left = new TreeNode(10);
root->left->left->right = new TreeNode(11);

cout << "Minimum Depth = "
     << minDepth(root) << endl;

return 0;
}
