#include <iomanip>
#include <iostream>
#include <bitset>
//C++20专有头文件format
#include <format>

int main () {
    //下面分别以16，10，8进制输出十进制的114这个数字（整数）
    std::cout << std::hex << 114 << std::endl;
    std::cout << std::dec << 114 << std::endl;
    std::cout << std::oct << 114 << std::endl;
    //输出二进制的在bitset里，不在iomanip里
    //std::bitset的输出有前导0
    std::cout << std::bitset<8>(114) << std::endl;
    std::cout << std::bitset<16>(114) << std::endl;
    std::cout << std::bitset<32>(114) << std::endl;
    //C++20专有：format
    std::cout << std::format("{:b}",114) << std::endl;    //无前导0
    std::cout << std::format("{:#b}",114) << std::endl;   //开头有0b
    std::cout << std::format("{:08b}",114) << std::endl;  //8位。有前导0
    std::cout << std::format("{:016b}",114) << std::endl; //16位，有前导0


    //下面进行浮点数的输出
    std::cout << std::fixed << 0.114 << std::endl;               //固定精度浮点
    std::cout << std::scientific << 0.114 << std::endl;          //科学计数法
    std::cout << std::hexfloat << 0.114 << std::endl;            //16进制浮点
    std::cout << std::defaultfloat << 0.114 << std::endl;        //默认的形式

    //下面尝试一些iomanip的其他操作符
    std::cout << std::setw(10) << 114.514 << std::endl;
    //改变输出域的宽度，若数值小于输出的东西的总长度，则不会有空格，但是输出也不会截断。
    //数值大于输出的东西的长度，则添加空格，空格数为 设置的输出域宽度 - 输出东西的长度
    std::cout << std::setw(10) << std::setfill('+') << 114.514 << std::endl;  //setfill：设置输出域空格为其他字符（char）
    std::cout << std::setprecision(1) << 0.1919810 << std::endl;                //设置浮点数精度（有四舍五入）
    std::cout << std::setprecision(1) << 114.514 << std::endl;                  //setprecision不是设置小数点后多少位，是多少位有效数字
    std::cout << std::setprecision(2) << 114.514 << std::endl;
    std::cout << std::setprecision(3) << 114.514 << std::endl;
    std::cout << std::setprecision(4) << 114.514 << std::endl;
    std::cout << std::setprecision(5) << 114.514 << std::endl;

    return 0;
}
