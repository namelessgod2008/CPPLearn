#include <iostream>
#include <array>

void selectionSort(std::array<int,8>& arr) {
    auto* minp = &arr[0];
    for (int i = 8; i > 0; i--) {
        minp = &arr[8 - i];
        std::cout << "=== i=" << i << " | minp重置到 arr[" << (8-i) << "] | 本轮【交换目标】arr[7-i]=arr[" << (7-i) << "] ===\n";
        for (int j = 8 - i; j < 8; j++) {
            if (arr[j] < *minp) minp = &arr[j];
        }
        std::cout << "  扫描区间 [" << (8-i) << ", 7] 找到最小值 " << *minp
                  << " 在 arr[" << (minp - arr.data()) << "]\n";
        std::cout << "  执行 swap(arr[" << (7-i) << "], arr[" << (minp - arr.data()) << "])\n";
        std::swap(arr[7 - i], *minp);
        std::cout << "  数组: [ ";
        for (int v : arr) std::cout << v << " ";
        std::cout << "]   arr[-1] = " << arr[-1] << "\n\n";
    }
}

int main() {
    std::array<int,8> arr = {60,71,49,11,82,24,3,66};
    std::cout << "初始: [ 60 71 49 11 82 24 3 66 ]\n\n";
    selectionSort(arr);
    std::cout << "最终: [ ";
    for (int v : arr) std::cout << v << " ";
    std::cout << "]\n";
    return 0;
}
