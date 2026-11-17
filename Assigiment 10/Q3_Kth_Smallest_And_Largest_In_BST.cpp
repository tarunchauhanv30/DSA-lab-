#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;

    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int k = 2;
    vector<int> values;
    inorderTraversal(root, values);

    if (k < 1 || k > (int)values.size()) {
        cout << "Invalid value of k\n";
        return 0;
    }

    cout << "Inorder array: ";
    for (int value : values) cout << value << " ";

    cout << "\nKth smallest = " << values[k - 1];
    cout << "\nKth largest = " << values[values.size() - k] << '\n';

    return 0;
}
