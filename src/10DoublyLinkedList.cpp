#include <iostream>

struct Node {
    Node* prev;
    Node* next;
    int data;

    Node ( int data ) : prev(nullptr), next(nullptr), data(data) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addAtHead (int data) {
        Node* newNode = new Node (data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAtTail (int data) {
        Node* newNode = new Node (data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool isEmpty () {
        if (head == nullptr || tail == nullptr) {
            return true;
        }
        return false;
    }

    int getNodeCount() {
        int count = 1;
        Node* current = head;
        if (isEmpty()) {
            return 0;
        }
        while (current->next != nullptr) {
            current = current->next;
            count++;
        }
        return count;
    }

    void insertAfter (int data, unsigned int indexbias) {
        Node* newNode = new Node (data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            return;
        }
        Node* current = head;
        if (getNodeCount() == 1) {
            head->next = newNode;
            newNode->prev = head;
            tail = newNode;
            return;
        }
        if (indexbias == 0) {
            Node* currentnext = current->next;
            current->next = newNode;
            currentnext->prev = newNode;
            newNode->prev = current;
            newNode->next = currentnext;
            return;
        }
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        } while (indexbias > 0);
        if (current->next == nullptr) {
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
            return;
        }
        Node* currentnext = current->next;
        current->next = newNode;
        currentnext->prev = newNode;
        newNode->prev = current;
        newNode->next = currentnext;
    }

    void insertbefore (int data, unsigned int indexbias) {
        Node* newNode = new Node (data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            return;
        }
        Node* current = head;
        if (getNodeCount() == 1) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        if (indexbias == 0) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        }while (indexbias > 0);
        Node* currentprev = current->prev;
        currentprev->next = newNode;
        newNode->prev = currentprev;
        newNode->next = current;
        current->prev = newNode;
    }

    int getData(unsigned int indexbias) {
        if (isEmpty()) {
            return 0;
        }
        Node* current = head;
        if (getNodeCount() == 1) {
            return current->data;
        }
        if (indexbias == 0) {
            return current->data;
        }
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        }while (indexbias > 0);
        return current->data;
    }
};

int main () {
    auto* list = new DoublyLinkedList();
    list->addAtHead(10);
    list->addAtTail(20);
    list->addAtTail(30);
    list->addAtTail(40);
    list->insertAfter(114,100);

    int count = list->getNodeCount();
    std::cout << count << std::endl;

    std::cout << list->getData(3) << std::endl;

    std::cout << list->getData(1000) << std::endl;

    delete list;
    return 0;
}

