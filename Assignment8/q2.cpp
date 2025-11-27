#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inOrderSuccessor(Node* root, Node* n) {
    if (n->right) return findMin(n->right);
    Node* succ = NULL;
    while (root) {
        if (n->data < root->data) { succ = root; root = root->left; }
        else root = root->right;
    }
    return succ;
}

Node* inOrderPredecessor(Node* root, Node* n) {
    if (n->left) return findMax(n->left);
    Node* pred = NULL;
    while (root) {
        if (n->data > root->data) { pred = root; root = root->right; }
        else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    Node* s1 = searchRecursive(root, 40);
    Node* s2 = searchNonRecursive(root, 60);

    cout << "Search Recursive: " << (s1 ? s1->data : -1) << endl;
    cout << "Search Non-Recursive: " << (s2 ? s2->data : -1) << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inOrderSuccessor(root, s1);
    Node* pred = inOrderPredecessor(root, s2);

    cout << "In-order Successor of " << s1->data << ": " << (succ ? succ->data : -1) << endl;
    cout << "In-order Predecessor of " << s2->data << ": " << (pred ? pred->data : -1) << endl;
}
