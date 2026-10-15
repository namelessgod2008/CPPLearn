#include <iostream>
#include <vector>

int partition(std::vector<int>& arr,int left,int right) {
    int& pivot = arr[right];
    int i = left;
    int j = right;
    while (true) {
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(arr[i], arr[j]);
    }
    std::swap(pivot, arr[i]);
    return i;
};

void quicksort(std::vector<int>& arr,int left,int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(arr,left,right);
    quicksort(arr,left,pivot - 1);
    quicksort(arr,pivot + 1,right);
}

int main () {
    std::vector arr = {60,71,49,11,82,24,3,66};
    std::cout << arr.size() << " vec created" << std::endl;
    partition(arr, 0, static_cast<int>(arr.size()) - 1);
    for (const int& i : arr) {
        std::cout << i << std::endl;
    };
    quicksort(arr, 0, static_cast<int>(arr.size()) - 1);
    for (const int& i : arr) {
        std::cout << i << std::endl;
    }
};