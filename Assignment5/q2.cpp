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

int deleteAll(Node*& head, int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* t = head;
    while (t != NULL && t->next != NULL) {
        if (t->next->data == key) {
            Node* temp = t->next;
            t->next = t->next->next;
            delete temp;
            count++;
        } else {
            t = t->next;
        }
    }
    return count;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int key, n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }
    cin >> key;

    int count = deleteAll(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);
}
