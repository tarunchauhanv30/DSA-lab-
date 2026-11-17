#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    long long sum;
    long long minimum;
    long long maximum;
};

class Solution {
    long long bestSum = LLONG_MIN;

    Info findMaximumBST(Node* root) {
        if (!root)
            return {true, 0, LLONG_MAX, LLONG_MIN};

        Info left = findMaximumBST(root->left);
        Info right = findMaximumBST(root->right);

        if (left.isBST && right.isBST &&
            root->data > left.maximum &&
            root->data < right.minimum) {

            long long currentSum = left.sum + right.sum + root->data;
            bestSum = max(bestSum, currentSum);

            return {
                true,
                currentSum,
                min((long long)root->data, left.minimum),
                max((long long)root->data, right.maximum)
            };
        }

        return {false, 0, LLONG_MIN, LLONG_MAX};
    }

public:
    long long maximumSumBST(Node* root) {
        bestSum = LLONG_MIN;
        findMaximumBST(root);
        return bestSum;
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Solution solution;
    cout << "Maximum BST subtree sum = "
         << solution.maximumSumBST(root) << endl;

    return 0;
}
