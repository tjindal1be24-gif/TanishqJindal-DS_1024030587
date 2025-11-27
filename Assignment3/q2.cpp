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
    void peek(){
        cout << arr[top];
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
    char str[] = "DataStructure";
    int i = 0;
    while(str[i]!='\0'){
        s.push(str[i]);
        i++;
    }
    while(!s.isEmpty()){
        s.peek();
        s.pop();
        
    }
    //s.display();
    

    return 0;
}