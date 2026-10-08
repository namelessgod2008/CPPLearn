#include <iostream>
#include <vector>

void insertSort(std::vector<int> &arr) {
    int size = static_cast<int>(arr.size());
    for (int i = 0; i < size - 1; i++) {
        int j = size - i - 1;
        int base = arr[j - 1];
        int k = j;
        while (k <= size - 1 && arr[k] < base) {
            arr[k - 1] = arr[k];
            k++;
        }
        arr[k - 1] = base;
    }
}

int main () {
    std::vector arr = {60,71,49,11,82,24,3,66};
    std::cout << arr.size() << " vec created" << std::endl;
    insertSort(arr);
    for ( int & i : arr) {
        std::cout << i << std::endl;
    }
}