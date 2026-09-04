#include <cstdint>   // 定宽整型（fixed-width integer）头文件
#include <iostream>

int main() {
    // ========================================================================
    // 一、定宽整型的大小（sizeof）
    //     <cstdint> 提供 std::intN_t / std::uintN_t：位数固定，不随平台变化。
    //     跨平台代码优先使用它们，避免 long 在 Windows 上是 4 字节、
    //     Linux 上是 8 字节这类"平台差异"。
    // ========================================================================

    // ---- 16 / 32 / 64 位：都是正常的整型，sizeof 输出没有问题 ----
    std::cout << "sizeof(std::int16_t)  = "
              << sizeof(std::int16_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::uint16_t) = "
              << sizeof(std::uint16_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::int32_t)  = "
              << sizeof(std::int32_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::uint32_t) = "
              << sizeof(std::uint32_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::int64_t)  = "
              << sizeof(std::int64_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::uint64_t) = "
              << sizeof(std::uint64_t) << " 字节" << std::endl;

    // ---- 8 位：sizeof 正常（1 字节），但输出时藏着陷阱（见第二部分）----
    std::cout << "sizeof(std::int8_t)   = "
              << sizeof(std::int8_t) << " 字节" << std::endl;
    std::cout << "sizeof(std::uint8_t)  = "
              << sizeof(std::uint8_t) << " 字节" << std::endl;

    // ========================================================================
    // 二、【陷阱：int8_t / uint8_t 是 char 的别名，不是整数！】
    //
    //   在绝大多数平台上（包括 GCC/MinGW/Cygwin），它们是这样被 typedef 的：
    //     std::uint8_t i1 = 10;   // 等价于 unsigned char i1 = 10;
    //     std::int8_t  i2 = 10;   // 等价于 signed char  i2 = 10;
    //
    //   std::cout 对 char 类型有一组【专门的重载】，把 char 当"字符"打印，
    //   而不是当"整数"打印。
    //
    //   → 数字 10 作为字符 = ASCII 码 10 = 换行符 '\n'
    //   → 所以下面这两行输出的不是数字 10，而是两个"看不见的换行"。
    //   → 在终端里看起来……"什么都没输出"。其实输出了，只是你看不见。
    //
    //   本质原因：
    //     C++ 里 << 选择哪个重载，由【变量的静态类型】决定，
    //     而不是由【里面存的值】决定。
    //     值是 10 或 255 都无所谓——类型是 char，就走字符重载。
    // ========================================================================
    std::uint8_t i1 = 10;
    std::int8_t  i2 = 10;

    std::cout << "直接输出 i1 = " << i1 << "   ← 你以为是 10，其实是字符" << std::endl;
    std::cout << "直接输出 i2 = " << i2 << "   ← 同理（结果看不见）" << std::endl << std::endl;

    // ========================================================================
    // 三、【修复方式】
    //   方式 A：强转成 int，让 << 改走"整数重载"。
    //   方式 B：改用 16 位整型（int16_t 是 short 的别名，不走字符重载）。
    //   实际建议：能用 int/short 就别用 int8_t/uint8_t 存数值，
    //             需要跨平台的定宽字节时才用它，且当"字节"而非"数"来用。
    // ========================================================================

    // ---- 方式 A：强制类型转换 ----
    std::cout << "强转 (int)i1 = " << (int)i1 << std::endl;
    std::cout << "强转 (int)i2 = " << (int)i2 << std::endl << std::endl;

    // ---- 方式 B：改用 16 位类型 ----
    std::int16_t  j1 = 10;
    std::uint16_t j2 = 10;
    std::cout << "int16_t  j1 = " << j1 << std::endl;
    std::cout << "uint16_t j2 = " << j2 << std::endl;

    return 0;
}