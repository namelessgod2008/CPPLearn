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
    
    return 0;
}
