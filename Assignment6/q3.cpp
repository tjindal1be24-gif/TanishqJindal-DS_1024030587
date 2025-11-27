#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) { data = x; prev = next = NULL; }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() { head = NULL; }

    void insertEnd(int x) {
        DNode* n = new DNode(x);
        if (!head) { head = n; return; }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    int size() {
        int count = 0;
        DNode* t = head;
        while (t) { count++; t = t->next; }
        return count;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int x) { data = x; next = NULL; }
};

class CircularList {
public:
    CNode* head;
    CircularList() { head = NULL; }

    void insertEnd(int x) {
        CNode* n = new CNode(x);
        if (!head) { head = n; n->next = n; return; }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 1;
        CNode* t = head->next;
        while (t != head) { count++; t = t->next; }
        return count;
    }
};

int main() {
    DoublyList dl;
    CircularList cl;
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; dl.insertEnd(x); }
    cout << "Doubly Linked List size: " << dl.size() << endl;

    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; cl.insertEnd(x); }
    cout << "Circular Linked List size: " << cl.size() << endl;
}
