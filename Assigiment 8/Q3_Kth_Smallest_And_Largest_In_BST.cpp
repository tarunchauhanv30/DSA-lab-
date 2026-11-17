#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, vector<int>& values) {
    if (!root) return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
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
    vector<int> values;
    inorder(root, values);

    if (k < 1 || k > (int)values.size()) {
        cout << "Invalid k" << endl;
        return 0;
    }

    cout << "Kth smallest: " << values[k - 1] << endl;
    cout << "Kth largest: " << values[values.size() - k] << endl;

    return 0;
}
