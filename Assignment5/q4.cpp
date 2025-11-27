#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insertEnd(Node*& head, int x) {
    Node* n = new Node(x);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }
    head = reverseList(head);
    display(head);
}
