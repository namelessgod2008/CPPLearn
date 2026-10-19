#include <iostream>

class ArrayStack {
private:
    int size;
    int count;
    int* data;

private:
    ArrayStack(int size): size(size),count(0),data(new int[size]) {};

public:
    static ArrayStack* of(int size) {
        return new ArrayStack(size);
    }

    static ArrayStack ofNoHeap(int size) {
        return {size};
    }

    ArrayStack(const ArrayStack& other) {
        this->size = other.size;
        this->count = other.count;
        int* newData = new int[size];
        for (int i = 0; i < size; i++) {
            newData[i] = other.data[i];
        }
        this->data = newData;
    }

    ArrayStack& operator=(const ArrayStack& other) {
        if (this == &other) {
            return *this;
        }
        int* newData = new int[other.size];
        for (int i = 0; i < other.size; i++) {
            newData[i] = other.data[i];
        }
        delete[] this->data;
        this->data = newData;
        this->size = other.size;
        this->count = other.count;
        return *this;
    }

    ~ArrayStack() {
        delete[] data;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    [[nodiscard]] int getCount() const {
        return count;
    }

    [[nodiscard]] bool isEmpty() const {
        if (count == 0) {
            return true;
        }
        return false;
    }

    [[nodiscard]] bool isFull() const {
        if (count == size) {
            return true;
        }
        return false;
    }

    void expand() {
        int newSize = size * 2;
        int* newData = new int[newSize];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void push(int var) {
        if (isFull()) {
            expand();
        }
        data[count] = var;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            return 0;
        }
        int temp = data[count - 1];
        data[count - 1] = 0;
        count--;
        return temp;
    }

    void popWithoutReturn() {
        if (isEmpty()) {
            return;
        }
        data[count - 1] = 0;
        count--;
    }
};

int main() {
    auto* stack = ArrayStack::of(3);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    int* i = new int[stack->getCount()];
    int temp = stack->getCount();
    for (int id = 0; id < temp; id++) {
        i[id] = stack->pop();
    }
    for (int j = 0; j < temp;j++) {
        std::cout << i[j] << std::endl;
    }
    delete stack;
    delete[] i;
    return 0;
}