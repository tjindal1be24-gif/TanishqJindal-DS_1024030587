#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    stack<int> s;
    cout << "Enter postfix expression: ";
    cin >> exp;

    for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int b = s.pop(), ignored;
            s.pop();
        }
    }

    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            switch (c) {
                case '+': s.push(b + a); break;
                case '-': s.push(b - a); break;
                case '*': s.push(b * a); break;
                case '/': s.push(b / a); break;
            }
        }
    }

    cout << "Result: " << s.top();
}
