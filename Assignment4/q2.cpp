#include <iostream>
using namespace std;

#define MAX 50

class CQueue {
    int arr[MAX];
    int front, rear;

public:
    CQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full\n";
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            cout << "Enqueued " << x << "\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
        } else {
            cout << "Dequeued: " << arr[front] << "\n";
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
        } else {
            int i = front;
            cout << "Queue: ";
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % MAX;
            }
            cout << "\n";
        }
    }
};

int main() {
    CQueue q;
    int choice, val;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                if (q.isEmpty()) cout << "Queue Empty\n";
                else cout << "Queue Not Empty\n";
                break;
            case 5:
                if (q.isFull()) cout << "Queue Full\n";
                else cout << "Queue Not Full\n";
                break;
            case 6:
                q.display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
