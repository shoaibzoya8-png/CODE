#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      
    int capacity;  
    int topIndex;  

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; 

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (topIndex >= capacity - 1) {
            cout << "Stack error " << value << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "stack error " << endl;
            return;
        }
        cout << "Popped: " << arr[topIndex--] << endl;
    }

    void peek() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[topIndex] << endl;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void display() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);  

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop();  
    return 0;
}
