#include <iostream>
#include <vector>

void merge(std::vector<int>& vec,int l,int mid,int r) {
    int temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (vec[i] <= vec[j]) {
            temp[k] = vec[i];
            k++;
            i++;
        }
        else {
            temp[k] = vec[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = vec[i];
        k++;
        i++;
    }
    while (j <= r) {
        temp[k] = vec[j];
        k++;
        j++;
    }
    for (int idx = 0; idx < k; idx++) {
        vec[l + idx] = temp[idx];
    }
}

void mergeSort(std::vector<int> &vec, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(vec, l, mid);
    mergeSort(vec, mid + 1, r);
    merge(vec, l, mid, r);
}

int main() {
    std::vector arr = {60,71,49,11,82,24,3,66};
    std::cout << arr.size() << " vec created" << std::endl;
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    for (const int& i : arr) {
        std::cout << i << std::endl;
    }
}