#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next_node;
public:
    Node(int d = 0, Node* next = nullptr) : data(d), next_node(next) {}
    int retrieve() const { return data; }
    Node* next() const { return next_node; }
    void setnext(Node* n) { next_node = n; }
};

class CircularList {
    Node* list_head;
public:
    CircularList() : list_head(nullptr) {}

    ~CircularList() {
        while (!empty())
            pop_front();
    }

    bool empty() const {
        return list_head == nullptr;
    }

    void front() const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        cout << list_head->retrieve() << endl;
    }

    void end() const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        Node* ptr = list_head;
        while (ptr->next() != list_head)
            ptr = ptr->next();
        cout << ptr->retrieve() << endl;
    }

    void size() const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        int count = 0;
        Node* ptr = list_head;
        do {
            count++;
            ptr = ptr->next();
        } while (ptr != list_head);
        cout << count << endl;
    }

    void count_value(int value) const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        int c = 0;
        Node* ptr = list_head;
        do {
            if (ptr->retrieve() == value)
                c++;
            ptr = ptr->next();
        } while (ptr != list_head);
        cout << c << endl;
    }

    void push_front(int n) {
        Node* p = new Node(n);
        if (empty()) {
            p->setnext(p);
            list_head = p;
        } else {
            Node* last = list_head;
            while (last->next() != list_head)
                last = last->next();
            p->setnext(list_head);
            last->setnext(p);
            list_head = p;
        }
    }

    void push_end(int n) {
        Node* p = new Node(n);
        if (empty()) {
            p->setnext(p);
            list_head = p;
        } else {
            Node* last = list_head;
            while (last->next() != list_head)
                last = last->next();
            last->setnext(p);
            p->setnext(list_head);
        }
    }

    void pop_front() {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        if (list_head->next() == list_head) {
            delete list_head;
            list_head = nullptr;
            return;
        }
        Node* last = list_head;
        while (last->next() != list_head)
            last = last->next();
        Node* temp = list_head;
        list_head = list_head->next();
        last->setnext(list_head);
        delete temp;
    }

    void pop_end() {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }
        if (list_head->next() == list_head) {
            delete list_head;
            list_head = nullptr;
            return;
        }
        Node* ptr = list_head;
        Node* prev = nullptr;
        while (ptr->next() != list_head) {
            prev = ptr;
            ptr = ptr->next();
        }
        prev->setnext(list_head);
        delete ptr;
    }

    void erase(int value) {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        Node* curr = list_head;
        Node* prev = nullptr;

        do {
            if (curr->retrieve() == value) {
                if (curr->next() == curr) {
                    delete curr;
                    list_head = nullptr;
                    break;
                }
                if (prev == nullptr) {
                    prev = list_head;
                    while (prev->next() != list_head)
                        prev = prev->next();
                }
                prev->setnext(curr->next());
                if (curr == list_head)
                    list_head = curr->next();
                Node* del = curr;
                curr = curr->next();
                delete del;
            } else {
                prev = curr;
                curr = curr->next();
            }
        } while (curr != list_head);
    }

    void display() const {
        if (empty()) {
            cout << "List is empty";
            return;
        }
        Node* ptr = list_head;
        do {
            cout << ptr->retrieve() << " ";
            ptr = ptr->next();
        } while (ptr != list_head);
        cout << endl;
    }
};

int main() {
    CircularList cl;

    cl.push_front(81);
    cl.push_front(70);
    cl.display();

    cl.push_end(50);
    cl.push_end(100);
    cl.display();

    cl.front();
    cl.end();
    cl.size();
    cl.count_value(81);

    cl.pop_front();
    cl.display();

    cl.pop_end();
    cl.display();

    cl.erase(81);
    cl.display();
}

