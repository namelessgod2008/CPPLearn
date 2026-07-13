// ====================================================================
// 【#define 的注意事项】
// 1. #define 是纯文本替换，发生在编译之前（预处理阶段），无视作用域。
// 2. 千万不要 #define C++ 关键字（如 final, class, virtual 等）——
//    这会把 #include 进来的所有标准库代码也一并污染，导致莫名其妙的编译错误。
// 3. 宏名通常用 ALL_CAPS 风格，减少和普通标识符冲突的概率。
// 4. C++ 中优先用 const / constexpr / inline 替代宏常量，类型安全且可调试。
// ====================================================================

// #define final const   ← 错误！final 是 C++11 关键字，会污染标准库

#define MY_CONST const    //用自定义前缀/全大写命名，避免冲突
#include <iostream>

int main() {
    // 对比三种定义常量的方式：
    #define PI 3.14159                     // C 风格宏：无类型检查，纯文本替换
    const double E1 = 2.71828;
    MY_CONST double E2 = 2.71828;// C++ const：有类型，编译期检查
    constexpr double GOLDEN = 1.61803;     // C++ constexpr：强制编译期求值

    std::cout << "PI     = " << PI << std::endl;
    std::cout << "E1     = " << E1 << std::endl;
    std::cout << "E2     = " << E2 << std::endl;
    std::cout << "GOLDEN = " << GOLDEN << std::endl;

    return 0;
}
