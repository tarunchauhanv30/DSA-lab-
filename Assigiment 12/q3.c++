#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int>& arr)
{
    if (arr.empty() || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        Node* current = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Store Parent of Every Node
void markParents(Node* root,
                 unordered_map<Node*, Node*>& parent)
{
    queue<Node*> q;

    q.push(root);
    parent[root] = NULL;

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if (current->left)
        {
            parent[current->left] = current;
            q.push(current->left);
        }

        if (current->right)
        {
            parent[current->right] = current;
            q.push(current->right);
        }
    }
}

// Find Target Node
Node* findTarget(Node* root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
        return root;

    Node* left = findTarget(root->left, target);

    if (left != NULL)
        return left;

    return findTarget(root->right, target);
}

// Find Nodes at Distance K
vector<int> distanceK(Node* root, int target, int k)
{
    unordered_map<Node*, Node*> parent;

    markParents(root, parent);

    Node* targetNode = findTarget(root, target);

    queue<Node*> q;
    unordered_set<Node*> visited;

    q.push(targetNode);
    visited.insert(targetNode);

    int distance = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (distance == k)
            break;

        distance++;

        for (int i = 0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            if (current->left &&
                !visited.count(current->left))
            {
                q.push(current->left);
                visited.insert(current->left);
            }

            if (current->right &&
                !visited.count(current->right))
            {
                q.push(current->right);
                visited.insert(current->right);
            }

            if (parent[current] &&
                !visited.count(parent[current]))
            {
                q.push(parent[current]);
                visited.insert(parent[current]);
            }
        }
    }

    vector<int> ans;

    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
}

int main()
{
    vector<int> arr =
    {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};

    int target = 5;
    int k = 2;

    Node* root = buildTree(arr);

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << ": ";

    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]";
    return 0;
}