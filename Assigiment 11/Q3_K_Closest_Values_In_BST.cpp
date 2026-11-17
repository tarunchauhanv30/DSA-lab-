#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void buildPredecessorStack(Node* root, int target, stack<Node*>& st) {
    while (root) {
        if (root->data <= target) {
            st.push(root);
            root = root->right;
        } else {
            root = root->left;
        }
    }
}

void buildSuccessorStack(Node* root, int target, stack<Node*>& st) {
    while (root) {
        if (root->data > target) {
            st.push(root);
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

int getPredecessor(stack<Node*>& st) {
    Node* node = st.top();
    st.pop();

    int value = node->data;
    node = node->left;

    while (node) {
        st.push(node);
        node = node->right;
    }

    return value;
}

int getSuccessor(stack<Node*>& st) {
    Node* node = st.top();
    st.pop();

    int value = node->data;
    node = node->right;

    while (node) {
        st.push(node);
        node = node->left;
    }

    return value;
}

vector<int> kClosestValues(Node* root, double target, int k) {
    stack<Node*> predecessors, successors;
    buildPredecessorStack(root, (int)target, predecessors);
    buildSuccessorStack(root, (int)target, successors);

    vector<int> answer;

    while (k-- > 0 && (!predecessors.empty() || !successors.empty())) {
        if (predecessors.empty()) {
            answer.push_back(getSuccessor(successors));
        } else if (successors.empty()) {
            answer.push_back(getPredecessor(predecessors));
        } else {
            double leftDiff = abs(target - predecessors.top()->data);
            double rightDiff = abs(successors.top()->data - target);

            if (leftDiff <= rightDiff)
                answer.push_back(getPredecessor(predecessors));
            else
                answer.push_back(getSuccessor(successors));
        }
    }

    return answer;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);

    double target = 9;
    int k = 4;

    vector<int> result = kClosestValues(root, target, k);

    for (int value : result) cout << value << " ";
    cout << endl;

    return 0;
}
