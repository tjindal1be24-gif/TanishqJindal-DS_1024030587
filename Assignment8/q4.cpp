#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data < minVal || root->data > maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if (isBST(root)) cout << "BST";
    else cout << "Not BST";
}
