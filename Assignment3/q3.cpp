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

int main()
{
    stack s;
    char str[10];
    
    cout << "Input paranthesis : ";
    cin >> str;
    
    int i = 0;
    while(str[i] == '[' || str[i] == '{'  || str[i] == '('){
        s.push(str[i]);
        i++;
    }
    while((s.peek() == '{' && str[i] == '}') || (s.peek() == '[' && str[i] == ']') || (s.peek() == '(' && str[i] == ')')){
        s.pop();
        i++;
    }
    if(s.isEmpty() == true){
        cout << "Balanced paranthesis";
    }
    else{
        cout<<"Unbalanced paranthesis";
    }

    return 0;
}