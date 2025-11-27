#include <iostream>
using namespace std;

class DNode {
public:
    char data;
    DNode* prev;
    DNode* next;
    DNode(char x) { data = x; prev = next = NULL; }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() { head = NULL; }

    void insertEnd(char x) {
        DNode* n = new DNode(x);
        if (!head) { head = n; return; }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    bool isPalindrome() {
        if (!head) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next) right = right->next;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dl;
    string s;
    cin >> s;
    for (char c : s) dl.insertEnd(c);
    if (dl.isPalindrome()) cout << "Palindrome";
    else cout << "Not Palindrome";
}
