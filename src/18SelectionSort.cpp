#include <iostream>
#include <array>

void selectionSort(std::array<int,8>& arr) {
    auto* minp = &arr[0];
    for (int i = 8;i > 0; i--) {
        minp = &arr[8 - i];
        for (int j = 8 - i;j < 8;j++) {
            if (arr[j] < *minp) {
                minp = &arr[j];
            }
        }
        std::swap(arr[8-i],*minp);
    }
}

int main() {
    std::array arr = {60,71,49,11,82,24,3,66};
    selectionSort(arr);
    for (int & it : arr) {
        std::cout << it << std::endl;
    }
    return 0;
}
