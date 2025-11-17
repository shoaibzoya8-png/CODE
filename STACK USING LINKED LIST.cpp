#include <iostream>
using namespace std;

class ListClass {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
public:
    ListClass() { head = nullptr; }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    int removeFront() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1; 
        }
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }

    int front() {
        if (head == nullptr) {
            cout << "List is empty! No front element." << endl;
            return -1; 
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~ListClass() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Stack {
private:
    ListClass list; 

public:
    void push(int value) {
        list.insertFront(value);
        cout << "Pushed: " << value << endl;
    }

    int pop() {
        if (list.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = list.removeFront();
        cout << "Popped: " << val << endl;
        return val;
    }

    int peek() {
        if (list.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return list.front();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void display() {
        cout << "Stack elements: ";
        list.display();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); 
    
    return 0;
}
