#include <cstdint>   // 定宽整型（fixed-width integer）头文件
#include <iostream>

int main() {
    // ========================================================================
    // 一、int_leastN_t：保证"至少 N 位"，代价是最小，宁小勿慢
    //     "least" = 能满足 N 位要求的最小类型。
    //     取值可以 = N，也可能比 N 大（平台里只存在更大的原始类型时）。
    //
    //     用途：不关心性能，只想要"至少有 N 位 + 跨平台可移植"。
    //     例：int_least32_t 可能 = int(4字节)，也可能 = long(8字节)。
    // ========================================================================
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  << " 字节" << std::endl;
    std::cout << "least 16: " << sizeof(std::int_least16_t) << " 字节" << std::endl;
    std::cout << "least 32: " << sizeof(std::int_least32_t) << " 字节" << std::endl;

    std::cout << "" << std::endl;

    // ========================================================================
    // 二、int_fastN_t：保证至少 N 位，且是"最快的"（宁快勿小）
    //     "fast" = CPU 处理最快的类型；可能比 N 大很多（例如 fast8 常常 = long）。
    //     reinterpret_cast 或按字节读时别用它——尺寸不固定。
    //     用途：只关心运行速度的数值计算。
    // ========================================================================
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t)   << " 字节" << std::endl;
    std::cout << "fast 16: " << sizeof(std::int_fast16_t)  << " 字节" << std::endl;
    std::cout << "fast 32: " << sizeof(std::int_fast32_t)  << " 字节" << std::endl;

    std::cout << "" << std::endl;

    // ========================================================================
    // 三、std::size_t：专门表示"大小、长度、元素个数"
    //     是无符号整数，尺寸正好能装下内存中任意对象的大小，
    //     sizeof、数组长度、容器 size() 都返回它。
    //     注意：size_t 不是定宽类型，跨平台宽度不同（这里 8 字节）。
    //     sizeof 返回的就是字节数，直接用，无需换算。
    // ========================================================================
    std::cout << "size_t  " << sizeof(std::size_t) << " 字节" << std::endl;

    return 0;
}