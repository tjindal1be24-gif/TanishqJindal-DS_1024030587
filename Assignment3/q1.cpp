#include <iostream>
using namespace std;

#define MAX 100

class stack{
    private:
    int top;
    int arr[MAX];
    
    public:
    
    stack(){
        top = -1;
    }
    
    bool isFull(){
        return top == MAX-1;
    }
    
    bool isEmpty(){
        return top == -1;
    }
    void push(int data){
        if(top<MAX-1){
            arr[top++] = data;
        }
        else{
            cout << "Overflow Condition";
        }
    }
    void pop(){
        if(top>0){
            top--;
        }
        else{
            cout << "Underflow Condition";
        }
    }
    int peek(){
        return arr[top];
    }
    void display(){
        if(top > 0){
            for(int i = top-1; i>=0;i++){
                cout << arr[i] << endl;
            }
        }
        else{
            cout << "Underflow Condition";
        }
    }
};

int main()
{
    stack s;
    s.push(7);
    s.push(4);
    s.push(6);
    s.push(3);
    cout << s.peek();

    return 0;
}