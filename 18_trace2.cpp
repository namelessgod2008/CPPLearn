#include <iostream>
#include <array>

// 和你的代码完全相同的结构，只加了打印
void selectionSort(std::array<int,8>& arr) {
    auto* minp = &arr[0];
    for (int i = 8; i > 0; i--) {
        std::cout << "=== 外层 i=" << i << "  待填位置 7-i=" << (7-i)
                  << "  进入时 minp 指向 arr[" << (minp - arr.data()) << "]=" << *minp
                  << " ===\n";
        for (int j = 7 - i; j < 8; j++) {
            long idx = j;
            if (idx == -1)
                std::cout << "   !! j=-1，读到的是数组前的栈内存，其值 = " << arr[j] << "\n";
            if (arr[j] < *minp) {
                minp = &arr[j];
                std::cout << "   j=" << idx << ": arr[" << idx << "]=" << arr[j]
                          << " 比当前最小值小 -> minp 改指向 arr[" << idx << "]\n";
            }
        }
        std::cout << "   扫描结束: minp 指向 arr[" << (minp - arr.data()) << "]=" << *minp
                  << "，执行 swap(arr[" << (7-i) << "], *minp)\n";
        std::swap(arr[7-i], *minp);
        std::cout << "   交换后数组: [ ";
        for (int v : arr) std::cout << v << " ";
        std::cout << "]   (数组外的 arr[-1] 现在 = " << arr[-1] << ")\n\n";
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
