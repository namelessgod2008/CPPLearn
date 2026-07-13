#include <iostream>

class Student {

private:
    std::string name = "Unknown";
    int age = 0;

public:
    // ========================================================================
    // 【static 成员 — 声明】
    // static 数据成员属于"类本身"，不属于任何实例（对象）。
    // 所有 Student 对象共享同一份 isAtSchool，存储在全局数据区，不占用对象内存。
    //
    // 这里只是"声明"（declaration），告诉编译器这个成员存在，
    // 但此时不分配内存——声明不产生存储空间。
    //
    // 类内直接写 = false 需要 C++17 的 inline static（见下方定义处的注释）。
    // ========================================================================
    static bool isAtSchool;

    int height = 180;

    // ========================================================================
    // 【this 指针】
    // C++ 的 this 是"指针"（Student*），不是 Java 的引用（Student）。
    // 因此访问成员用 this->name（指针解引用），而不是 Java 的 this.name。
    //
    // this->name  等价于  (*this).name
    //   "->" 是语法糖：先解引用指针得到对象，再访问其成员。
    //
    // 历史原因：C++ 的 this 在 1979 年就已设计为指针，
    // 比 C++ 正式引入"引用"（1985）早了六年，是历史遗留设计。
    //
    // 当成员变量和形参同名时（如这里的 name），this->name 特指成员变量，
    // 不加 this 的 name 指的是形参——this 用于消除歧义。
    // ========================================================================
    void setName(std::string name) { this->name = name; }

    void setAge(int age) { this->age = age; }

    std::string getName() { return this->name; }

    int getAge() { return this->age; }

    void playBasketBall() {
        std::cout << "Basket Ball Played" << std::endl;
    }
};

// ========================================================================
// 【static 成员 — 定义（分配内存）】
// 这是"定义"（definition），在全局作用域中为 isAtSchool 分配实际内存。
// 整个程序中这个定义只能出现一次（ODR，一次定义规则），否则链接器报错。
//
// 为什么不能写在类内？
//   类定义通常在头文件（.hpp）中，会被多个 .cpp include。
//   如果类内写了 = false，每个翻译单元都会尝试分配一块内存 →
//   链接器发现多个同名符号 → ODR 冲突 → "multiple definition" 错误。
//   const static 整型例外：编译器直接做值替换，不产生地址，所以不受此限制。
//
// C++17 的替代写法（可直接写在类内，不需要下面这行）：
//   inline static bool isAtSchool = false;
//   ↑ inline 告诉链接器："多个定义中只保留一份"，解决了 ODR 问题。
// ========================================================================
bool Student::isAtSchool = false;

int main() {
    Student student;
    student.setName("fishbee");
    student.setAge(114514);
    student.playBasketBall();

    // ========================================================================
    // 【static 成员 — 访问方式】
    // 通过 类名::成员名 访问，不需要对象。
    // 也可以用对象访问（student.isAtSchool），但不推荐——语义上它不属于某个对象。
    // ========================================================================
    Student::isAtSchool = true;
    Student::isAtSchool = false;

    std::cout << student.height << student.getName() << student.getAge() << std::endl;
    system("pause");
    return 0;
}