#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;

    Node* left;
    Node* right;

    bool lthread;
    bool rthread;

    Node(int val) {
        data = val;

        left = NULL;
        right = NULL;

        lthread = true;
        rthread = true;
    }
};

class ThreadedBST {

    Node* root;

public:

    ThreadedBST() {
        root = NULL;
    }

    // BUILD: Insert into normal BST
    void insert(int val) {

        Node* ptr = new Node(val);

        if (root == NULL) {
            root = ptr;
            return;
        }

        Node* curr = root;
        Node* parent = NULL;

        while (curr != NULL) {

            if (val == curr->data)
                return;

            parent = curr;

            if (val < curr->data)
                curr = curr->left;

            else
                curr = curr->right;
        }

        if (val < parent->data) {
            parent->left = ptr;
            parent->lthread = false;
        }

        else {
            parent->right = ptr;
            parent->rthread = false;
        }
    }

    // Find leftmost node
    Node* leftMost(Node* ptr) {

        if (ptr == NULL)
            return NULL;

        while (!ptr->lthread)
            ptr = ptr->left;

        return ptr;
    }

    // Find rightmost node
    Node* rightMost(Node* ptr) {

        if (ptr == NULL)
            return NULL;

        while (!ptr->rthread)
            ptr = ptr->right;

        return ptr;
    }

    // CONVERT: Convert BST into double threaded BST
    void convert() {

        vector<Node*> nodes;

        // Collect inorder nodes
        vector<Node*> st;
        Node* curr = root;

        while (curr != NULL || !st.empty()) {

            while (curr != NULL) {
                st.push_back(curr);
                curr = curr->left;
            }

            curr = st.back();
            st.pop_back();

            nodes.push_back(curr);

            curr = curr->right;
        }

        // Create predecessor and successor threads
        for (int i = 0; i < (int)nodes.size(); i++) {

            Node* ptr = nodes[i];

            if (ptr->left == NULL) {

                ptr->lthread = true;

                if (i == 0)
                    ptr->left = NULL;
                else
                    ptr->left = nodes[i - 1];
            }

            if (ptr->right == NULL) {

                ptr->rthread = true;

                if (i == (int)nodes.size() - 1)
                    ptr->right = NULL;
                else
                    ptr->right = nodes[i + 1];
            }
        }
    }

    // Find inorder successor
    Node* successor(Node* ptr) {

        if (ptr == NULL)
            return NULL;

        if (ptr->rthread)
            return ptr->right;

        return leftMost(ptr->right);
    }

    // Find inorder predecessor
    Node* predecessor(Node* ptr) {

        if (ptr == NULL)
            return NULL;

        if (ptr->lthread)
            return ptr->left;

        return rightMost(ptr->left);
    }

    // Search a value
    Node* search(int key) {

        Node* curr = root;

        while (curr != NULL) {

            if (key == curr->data)
                return curr;

            if (key < curr->data) {

                if (curr->lthread)
                    return NULL;

                curr = curr->left;
            }

            else {

                if (curr->rthread)
                    return NULL;

                curr = curr->right;
            }
        }

        return NULL;
    }

    // NEXT operation
    void NEXT(int x) {

        Node* ptr = search(x);

        if (ptr == NULL) {
            cout << "NEXT " << x << " = NULL\n";
            return;
        }

        Node* ans = successor(ptr);

        if (ans == NULL)
            cout << "NEXT " << x << " = NULL\n";

        else
            cout << "NEXT " << x << " = "
                 << ans->data << "\n";
    }

    // PREV operation
    void PREV(int x) {

        Node* ptr = search(x);

        if (ptr == NULL) {
            cout << "PREV " << x << " = NULL\n";
            return;
        }

        Node* ans = predecessor(ptr);

        if (ans == NULL)
            cout << "PREV " << x << " = NULL\n";

        else
            cout << "PREV " << x << " = "
                 << ans->data << "\n";
    }

    // RANGE operation
    void RANGE(int L, int R) {

        cout << "RANGE = [";

        if (L > R) {
            cout << "]\n";
            return;
        }

        // Find smallest value >= L
        Node* curr = root;
        Node* candidate = NULL;

        while (curr != NULL) {

            if (curr->data >= L) {

                candidate = curr;

                if (curr->lthread)
                    break;

                curr = curr->left;
            }

            else {

                if (curr->rthread)
                    break;

                curr = curr->right;
            }
        }

        // Move using successor threads
        bool first = true;

        while (candidate != NULL &&
               candidate->data <= R) {

            if (!first)
                cout << ",";

            cout << candidate->data;

            first = false;

            candidate = successor(candidate);
        }

        cout << "]\n";
    }

    // KTH operation
    void KTH(int k) {

        if (k <= 0) {
            cout << "KTH " << k << " = NULL\n";
            return;
        }

        Node* curr = leftMost(root);

        int count = 1;

        while (curr != NULL && count < k) {

            curr = successor(curr);

            count++;
        }

        if (curr == NULL)
            cout << "KTH " << k << " = NULL\n";

        else
            cout << "KTH " << k << " = "
                 << curr->data << "\n";
    }
};

int main() {

    ThreadedBST tree;

    // BUILD
    int values[] = {40, 20, 60, 10, 30, 50, 70};

    for (int x : values)
        tree.insert(x);

    cout << "BST Created Successfully\n";

    // CONVERT
    tree.convert();

    cout << "Converted into Double Threaded BST\n";

    // Queries
    tree.NEXT(30);

    tree.PREV(30);

    tree.RANGE(25, 60);

    tree.KTH(5);

    return 0;
}