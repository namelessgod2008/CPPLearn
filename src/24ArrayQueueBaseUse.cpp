#include<iostream>

class ArrayQueue {
private:
    int size;
    int count;
    int* data;
    int* firstElement;
    int* firstArraySlot;
    int* lastArraySlot;

private:
    ArrayQueue(int size):
    size(size),
    count(0),
    data(new int[size]),
    firstElement(nullptr),
    firstArraySlot(&data[0]),
    lastArraySlot(&data[size - 1])
    {};

public:
    static ArrayQueue* of(int size) {
        return new ArrayQueue(size);
    }

    static ArrayQueue ofNoHeap(int size) {
        return {size};
    }

    ArrayQueue(const ArrayQueue& other) {
        this->size = other.size;
        this->count = other.count;
        int *newData = new int[size];
        int *otherFirstElement = other.firstElement;
        for (int i = 0; i < count; i++) {
            if (otherFirstElement != other.lastArraySlot) {
                newData[i] = *otherFirstElement;
                otherFirstElement++;
            }
            else {
                newData[i] = *otherFirstElement;
                otherFirstElement = other.firstArraySlot;
            }
        }
        this->data = newData;
        this->firstElement = &data[0];
        this->firstArraySlot = &data[0];
        this->lastArraySlot = &data[size - 1];
    }

    ~ArrayQueue() {
        delete[] data;
    }

    int getSize() {
        return size;
    }

    int getCount() {
        return count;
    }

    bool isEmpty() const {
        if (count == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (count == size) {
            return true;
        }
        return false;
    }

    void expand() {
        int newSize = size * 2;
        int *newData = new int[newSize];
        for (int i = 0; i < count; i++) {
            if (firstElement != lastArraySlot) {
                newData[i] = *firstElement;
                firstElement++;
            } else {
                newData[i] = *firstElement;
                firstElement = &data[0];
            }
        }
        delete[] data;
        this->data = newData;
        this->size = newSize;
        this->firstElement = &data[0];
        this->firstArraySlot = &data[0];
        this->lastArraySlot = &data[size - 1];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return *firstElement;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int temp = peek();
        if (firstElement == lastArraySlot) {
            firstElement = firstArraySlot;
        }
        else {
            firstElement++;
        }

        count--;
        return temp;
    }

    void push(int var) {
        if (isFull()) {
            expand();
        }
        int* writePosition = firstElement + count;
        if (writePosition > data + size) {
            writePosition -= size;
        }
        *writePosition = var;
        count++;
    }
};

int main() {

}