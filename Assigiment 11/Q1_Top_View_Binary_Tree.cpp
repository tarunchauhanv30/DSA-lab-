#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void printTopView(Node* root) {
    if (!root) return;

    map<int, int> topNodes;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        Node* node = current.first;
        int horizontalDistance = current.second;

        if (!topNodes.count(horizontalDistance))
            topNodes[horizontalDistance] = node->data;

        if (node->left)
            q.push({node->left, horizontalDistance - 1});

        if (node->right)
            q.push({node->right, horizontalDistance + 1});
    }

    for (const auto& entry : topNodes)
        cout << entry.second << " ";
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    printTopView(root);
    return 0;
}
