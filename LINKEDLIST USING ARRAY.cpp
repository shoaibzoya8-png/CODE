#include <iostream>
using namespace std;

const int SIZE = 100;

int dataArr[SIZE];
int nextArr[SIZE];

int head = -1;       
int freeSpot = 0;    

void initialize() {
    for (int i = 0; i < SIZE - 1; i++)
        nextArr[i] = i + 1;

    nextArr[SIZE - 1] = -1;
}

int getFreeNode() {
    if (freeSpot == -1) {
        cout << "No empty ";
        return -1;
    }

    int node = freeSpot;
    freeSpot = nextArr[freeSpot];
    return node;
}

void insertAtStart(int value) {
    int node = getFreeNode();
    if (node == -1) return;

    dataArr[node] = value;
    nextArr[node] = head;
    head = node;
}

void insertAtEnd(int value) {
    int node = getFreeNode();
    if (node == -1) return;

    dataArr[node] = value;
    nextArr[node] = -1;

    if (head == -1) {
        head = node;
        return;
    }

    int temp = head;
    while (nextArr[temp] != -1)
        temp = nextArr[temp];

    nextArr[temp] = node;
}

void insertAtPosition(int pos, int value) {
    int node = getFreeNode();
    if (node == -1) return;

    dataArr[node] = value;

    if (pos == 0) {
        nextArr[node] = head;
        head = node;
        return;
    }

    int temp = head;
    for (int i = 0; i < pos - 1 && temp != -1; i++)
        temp = nextArr[temp];

    if (temp == -1) {
        cout << "Invalid posi";
        return;
    }

    nextArr[node] = nextArr[temp];
    nextArr[temp] = node;
}

void deleteStart() {
    if (head == -1) {
        cout << "List is empty";
        return;
    }

    int temp = head;
    head = nextArr[head];

    nextArr[temp] = freeSpot;
    freeSpot = temp;
}

void deleteEnd() {
    if (head == -1) {
        cout << "List is empty";
        return;
    }

    int temp = head;
    int prev = -1;

    while (nextArr[temp] != -1) {
        prev = temp;
        temp = nextArr[temp];
    }

    if (prev == -1) {
        head = -1;
    } else {
        nextArr[prev] = -1;
    }

    nextArr[temp] = freeSpot;
    freeSpot = temp;
}

void deleteAtPosition(int pos) {
    if (head == -1) {
        cout << "List is empty";
        return;
    }

    int temp = head;
    int prev = -1;

    for (int i = 0; i < pos && temp != -1; i++) {
        prev = temp;
        temp = nextArr[temp];
    }

    if (temp == -1) {
        cout << "Invalid position";
        return;
    }

    nextArr[prev] = nextArr[temp];

    nextArr[temp] = freeSpot;
    freeSpot = temp;
}

void printList() {
    if (head == -1) {
        cout << "List is empty";
        return;
    }

    int temp = head;
    cout << "List: ";
    while (temp != -1) {
        cout << dataArr[temp];
        if (nextArr[temp] != -1) cout << " -> ";
        temp = nextArr[temp];
    }
    cout << endl;
}

int main() {
    initialize();

    insertAtStart(20);
    insertAtEnd(30);
    insertAtPosition(1, 25);

    cout << "\nAfter inserting values";
    printList();

    deleteStart();
    deleteEnd();
    deleteAtPosition(0);

    cout << "\nAfter deleting values";
    printList();
}
