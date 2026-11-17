#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->val) insert(root->left, value);
    else insert(root->right, value);
}

void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(root, value);
    }

    vector<int> sortedValues;
    inorder(root, sortedValues);

    for (int value : sortedValues) cout << value << " ";
    cout << endl;

    return 0;
}
