#include <iostream>
using namespace std;

#define MAX 20

class stack{
    int top;
    char arr[MAX];
    
    public:
    stack(){
        top = -1;
    }
    bool isFull(){
        return top == MAX - 1;
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(char data){
        if(isFull()){
            cout << "Overflow Condition";
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "Underflow Condition";
        }
        else{
            top--;
        }
    }
    char peek(){
        return arr[top];
    }
    void display(){
        for(int i = top; i>=0; i--){
            cout << arr[i];
        }
    }
};

int precedence(char a){
        if(a =='^') return 4;
        if(a =='*') return 3;
        if(a =='/') return 2;
        if(a =='+') return 1;
        if(a =='-') return 0;
        return -1;
}

stack s;

int main()
{
    char t[15];
    cout << "Write infix expression : ";
    cin.getline(t, 15);
    int i = 0;
    while(t[i]!='\0'){
        if(t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/' || t[i] == '^'){
            if(precedence(s.peek()) >= precedence(t[i])){
                cout << s.peek();
                s.pop();
            }
            s.push(t[i]);
        }
        else{
            cout << t[i];
        }
        
        i++;
    }
    while(!s.isEmpty()){
        cout<< s.peek();
        s.pop();
    }
    

    return 0;
}