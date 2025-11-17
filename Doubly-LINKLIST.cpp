#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next_node;
    Node* prev_node;
public:
    
    Node(int d = 0, Node* next = nullptr, Node* prev = nullptr)
        : data(d), next_node(next), prev_node(prev) {}
    
    int retrieve() const { 
        return data; 
    }
    Node* next() const { 
        return next_node; 
    }
    Node* prev() const { 
        return prev_node; 
    }
    
    void setnext(Node* n) { 
        next_node = n; 
    }
    void setprevious(Node* p) { 
        prev_node = p; 
    }
};

 class DList {
private:
    Node* list_head;
public:
    
    DList(){
        list_head=nullptr;
    }
    
    ~DList() {
        while (!empty()) {
            pop_front();
        }
    }

    bool empty() const {
        return list_head == nullptr;
    }

    Node* head() const {
        return list_head;
    }

    int front() const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        return list_head->retrieve();
    }
    int end() const {
        if (empty()) {
            cout << "List is empty";
            return ;
        }
        Node* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        return ptr->retrieve();
    }
    int size() const {
        int count = 0;
        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return count;
    }
    int count(int value) const {
        int count = 0;
        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            if (ptr->retrieve() == value)
                count++;
        }
        return count;
    }
    
    void push_front(int n) {
    Node* p = new Node(n, list_head, nullptr);

    if (list_head != nullptr) {
        list_head->setprevious(p);
    }

    list_head = p;
}
    void push_end(int n) {
        if (empty()) {
            push_front(n);
            return;
        }
        Node* last = list_head;
        while (last->next() != nullptr) {
            last = last->next();
        }
        Node* newnode = new Node(n, nullptr, last);
        last->setnext(newnode);
    }

    int pop_front() {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        int e = list_head->retrieve();
        Node* temp = list_head;
        list_head = list_head->next();

        if (list_head != nullptr)
            list_head->setprev(nullptr);

        delete temp;
        return e;
    }

    int pop_end() {
        if (empty()) {
            cout << "List is empty";
            return -1;
        }
        Node* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        int e = ptr->retrieve();
        if (ptr->prev() != nullptr)
            ptr->prev()->setnext(nullptr);
        else
            list_head = nullptr; 
        delete ptr;
        return e;
    }
    int erase(int value) {
        int removed = 0;
        Node* ptr = list_head;
        while (ptr != nullptr) {
            if (ptr->retrieve() == value) {
                Node* to_delete = ptr;
                if (ptr->prev() != nullptr)
                    ptr->prev()->setnext(ptr->next());
                else
                    list_head = ptr->next(); 

                if (ptr->next() != nullptr)
                    ptr->next()->setprev(ptr->prev());
                ptr = ptr->next();
                delete to_delete;
                removed++;
            } else {
                ptr = ptr->next();
            }
        }
        return removed;
    }
    
    void display() const {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* ptr = list_head;
        cout << "List contents: ";
        while (ptr != nullptr) {
            cout << ptr->retrieve() << " ";
            ptr = ptr->next();
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    cout << "Adding to front: 81, 70\n";
    dl.push_front(81);
    dl.push_front(70);
    dl.display();
    cout << "Adding to end: 50, 100\n";
    dl.push_end(50);
    dl.push_end(100);
    dl.display();
    cout << "Front element: " << dl.front() << endl;
    cout << "End element: " << dl.end() << endl;
    cout << "List size: " << dl.size() << endl;
    cout << "Count of 81: " << dl.count(81) << endl;
    cout << "Pop front: " << dl.pop_front() << endl;
    dl.display();
    cout << "Pop end: " << dl.pop_end() << endl;
    dl.display();
    cout << "Erase all 81s: " << dl.erase(81) << " removed.\n";
    dl.display();
    cout << "List size now: " << dl.size() << endl;
    return 0;
}
