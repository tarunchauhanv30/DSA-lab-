#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void serializeHelper(Node* root, vector<string>& values) {
    if (!root) {
        values.push_back("#");
        return;
    }

    values.push_back(to_string(root->data));
    serializeHelper(root->left, values);
    serializeHelper(root->right, values);
}

string serialize(Node* root) {
    vector<string> values;
    serializeHelper(root, values);

    string result;
    for (int i = 0; i < (int)values.size(); i++) {
        if (i > 0) result += ",";
        result += values[i];
    }

    return result;
}

Node* deserializeHelper(const vector<string>& values, int& index) {
    if (index >= (int)values.size()) return nullptr;

    string token = values[index++];
    if (token == "#") return nullptr;

    Node* root = new Node(stoi(token));
    root->left = deserializeHelper(values, index);
    root->right = deserializeHelper(values, index);

    return root;
}

Node* deserialize(const string& data) {
    if (data.empty()) return nullptr;

    vector<string> values;
    string token;
    stringstream ss(data);

    while (getline(ss, token, ','))
        values.push_back(token);

    int index = 0;
    return deserializeHelper(values, index);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string data = serialize(root);
    cout << "Serialized tree: " << data << endl;

    Node* restoredRoot = deserialize(data);

    cout << "Inorder of reconstructed tree: ";
    inorder(restoredRoot);
    cout << endl;

    return 0;
}
