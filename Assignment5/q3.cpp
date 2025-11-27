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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node* head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }
    cout << findMiddle(head);
}
