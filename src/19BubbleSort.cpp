#include <filesystem>
#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& arr) {
    for ( int j = static_cast<int>(arr.size()) - 1; j > 0; --j ) {
        for (int i = 0; i < j; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
};

int main() {
    std::vector arr = {60,71,49,11,82,24,3,66};
    std::cout << arr.size() << "vec created" << std::endl;
    BubbleSort(arr);
    for (int& i : arr) {
        std::cout << i << std::endl;
    }
};
