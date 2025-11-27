#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class CircularList {
public:
    Node* head;
    CircularList() { head = NULL; }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; n->next = n; return; }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void display() {
        if (!head) return;
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << head->data;
    }
};

int main() {
    CircularList cl;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cl.insertEnd(x);
    }
    cl.display();
}
