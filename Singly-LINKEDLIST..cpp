#include <iostream>
#include <stdexcept> 
using namespace std;

class Node {
private:
    int data;       
    Node* next;     

public:
    
    Node(int x, Node* n = nullptr) {
        data = x;
        next = n;
    }

    
    int retrieve() { return data; }

    friend class list; 
};

class list {
private:
    Node* head;  
    Node* tail;  

public:
    
    list() {
        head = tail = nullptr;
    }

    void push_front(int x) {
        Node* new_node = new Node(x);   
        if (head == nullptr) {          
            head = tail = new_node;     
        } else {
            new_node->next = head;      
            head = new_node;            
        }
    }

    void push_back(int x) {
        Node* new_node = new Node(x);   
        if (head == nullptr) {          
            head = tail = new_node;     
        } else {
            tail->next = new_node;      
            tail = new_node;            
        }
    }

    void push_middle(int x, int pos) {
        if (pos <= 0) {                 
            push_front(x);
            return;
        }

        Node* temp = head;              
        int count = 0;

        // move to position-1
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp == tail) { 
            push_back(x);
            return;
        }

        Node* new_node = new Node(x);
        new_node->next = temp->next;    
        temp->next = new_node;          
    }

    void pop_front() {
        if (head == nullptr){
            throw runtime_error("Error: Cannot pop from empty list.");
        }
        Node* temp = head;              
        head = head->next;              
        if (head == nullptr){
            tail = nullptr;
        }            
        delete temp;                    
    }

    void pop_back() {
        if (head == nullptr)
            throw runtime_error("");

        if (head == tail) {             
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        
        while (temp->next != tail)
            temp = temp->next;

        delete tail;                    
        tail = temp;                    
        tail->next = nullptr;           
    }

    void erase(int pos) {
        if (head == nullptr)
            throw runtime_error("");

        if (pos <= 1) {                 
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr)
            throw runtime_error("");

        Node* delNode = temp->next;     
        temp->next = delNode->next;     
        if (delNode == tail)
            tail = temp;                
        delete delNode;                

    
    void print() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {       
            count++;
            temp = temp->next;
        }
        return count;
    }

    int count(int x) {
        int c = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x)
                c++;
            temp = temp->next;
        }
        return c;
    }
    int get_head() {
        if (head == nullptr)
            throw runtime_error("Error: List is empty, no head element.");
        return head->data;
    }

    void clear() {
        Node* temp = head;              
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;                
            temp = nextNode;            
        }
        head = tail = nullptr;          
        cout << "List cleared successfully." << endl;
    }
};


int main() {
    
        list l;

        l.push_front(1);
        l.push_front(2);
        l.push_front(3);
        l.push_front(4);
        l.push_front(5);
        l.print();

        l.push_back(6);
        l.print();
        l.push_middle(7, 2);
        l.print();
        l.erase(3);
        l.print();

        l.pop_front();
        l.print();

        l.pop_back();
        l.print();
        l.size();

        l.push_back(5);
        l.push_back(5);
        l.push_front(5);
        l.print();
        l.count(5);

        l.get_head(); 

        l.clear();
        l.print();
    
    return 0;
}
