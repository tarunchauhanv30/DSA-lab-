#include <iostream>
#include <queue>
#include <map>
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

void topView(Node* root) {
    if (root == NULL)
        return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        if (node->left != NULL) {
            q.push({node->left, hd - 1});
        }

        if (node->right != NULL) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto p : mp) {
        cout << p.second << " ";
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout << "Top View: ";
    topView(root);
    return 0;
}