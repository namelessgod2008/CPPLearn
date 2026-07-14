#include <iostream>

// ====================================================================
// 【sizeof 的要点】
// 1. sizeof 是编译期运算符，不是函数——结果在编译时就确定了。
// 2. sizeof(变量) 或 sizeof(类型) 都可以。
// 3. sizeof(指针) 永远是 8（64位）/ 4（32位），不等于对象本身的大小。
// 4. 空类大小为 1 字节（C++ 保证每个对象有唯一地址，最小单位 1）。
// 5. ? 同一个类的所有对象 sizeof 完全相同——类定义决定了内存布局，
//    无论你用哪个构造函数创建对象，所有成员字段都存在，大小不变。
// ====================================================================

class Base {
private:
    int         field1;   // 4 字节
    float       field2;   // 4 字节
    bool        field3;   // 1 字节
    long        field4;   // 4 或 8 字节（取决于平台）
    long long   field5;   // 8 字节
    double      field6;   // 8 字节
    long double field7;   // 16 字节（g++/MinGW 下）

public:
    // ==================== 重载构造函数 ====================
    // 构造函数可以重载——名字相同，参数不同，编译器根据实参类型自动匹配。

    Base(int v) : field1(v) {            // 单参：int
        std::cout << "Base(int)       被调用" << std::endl;
    }
    Base(float v) : field2(v) {          // 单参：float（注意：Base b = 1.0f 会调用这个）
        std::cout << "Base(float)     被调用" << std::endl;
    }
    Base(bool v) : field3(v) {           // 单参：bool
        std::cout << "Base(bool)      被调用" << std::endl;
    }
    Base(long v) : field4(v) {           // 单参：long
        std::cout << "Base(long)      被调用" << std::endl;
    }
    Base(long long v) : field5(v) {      // 单参：long long
        std::cout << "Base(long long) 被调用" << std::endl;
    }
    Base(double v) : field6(v) {         // 单参：double
        std::cout << "Base(double)    被调用" << std::endl;
    }
    Base(long double v) : field7(v) {    // 单参：long double
        std::cout << "Base(long double)被调用" << std::endl;
    }

    // 原有双参构造函数
    Base(int f1, float f2) : field1(f1), field2(f2) {
        std::cout << "Base(int,float) 被调用" << std::endl;
    }

    ~Base() {}
};

int main() {
    // ==================== 基础类型 sizeof ====================
    std::cout << "========== 基础类型 sizeof ==========" << std::endl;
    std::cout << "short:       " << sizeof(short)       << " 字节" << std::endl;
    std::cout << "int:         " << sizeof(int)         << " 字节" << std::endl;
    std::cout << "long:        " << sizeof(long)        << " 字节" << std::endl;
    std::cout << "long long:   " << sizeof(long long)   << " 字节" << std::endl;
    std::cout << "float:       " << sizeof(float)       << " 字节" << std::endl;
    std::cout << "double:      " << sizeof(double)      << " 字节" << std::endl;
    std::cout << "long double: " << sizeof(long double) << " 字节" << std::endl;
    std::cout << "bool:        " << sizeof(bool)        << " 字节" << std::endl;
    std::cout << "char:        " << sizeof(char)        << " 字节" << std::endl;

    // ==================== Base 对象（栈上创建）====================
    std::cout << "\n========== 构造 Base 对象 ==========" << std::endl;

    Base base1(42);                  // int
    Base base2(3.14f);               // float
    Base base3(true);                // bool
    Base base4(100L);                // long
    Base base5(999LL);               // long long
    Base base6(2.718);               // double
    Base base7(1.618L);              // long double

    // ==================== 输出 sizeof ====================
    std::cout << "\n========== Base 对象 sizeof ==========" << std::endl;
    std::cout << "base1 (int):         sizeof = " << sizeof(base1) << " 字节" << std::endl;
    std::cout << "base2 (float):       sizeof = " << sizeof(base2) << " 字节" << std::endl;
    std::cout << "base3 (bool):        sizeof = " << sizeof(base3) << " 字节" << std::endl;
    std::cout << "base4 (long):        sizeof = " << sizeof(base4) << " 字节" << std::endl;
    std::cout << "base5 (long long):   sizeof = " << sizeof(base5) << " 字节" << std::endl;
    std::cout << "base6 (double):      sizeof = " << sizeof(base6) << " 字节" << std::endl;
    std::cout << "base7 (long double): sizeof = " << sizeof(base7) << " 字节" << std::endl;

    // 关键结论：全部相等！
    // 原因：sizeof 只看"类定义中声明了哪些字段"，不看"用了哪个构造函数"。
    //      所有 Base 对象含同样 7 个字段 → 大小恒为 48 字节（含内存对齐填充）。

    std::cout << "\n========== 类型级别 sizeof ==========" << std::endl;
    std::cout << "sizeof(Base) = " << sizeof(Base)
              << " 字节  ← 与所有 base1~base7 相同" << std::endl;

    return 0;
}
