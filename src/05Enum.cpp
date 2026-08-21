#include <iostream>
#include <string>

//枚举不能有方法
//枚举值可以设置对应的整数值
//设置了第一个值以后后面的枚举项对应的值会递增
enum class Day {
    UNKNOWN = 0,
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

std::string getName(Day day) {
    switch (day) {
        case Day::UNKNOWN:
            return "Unknown";
        case Day::MONDAY:
            return "Monday";
        case Day::TUESDAY:
            return "Tuesday";
        case Day::WEDNESDAY:
            return "Wednesday";
        case Day::THURSDAY:
            return "Thursday";
        case Day::FRIDAY:
            return "Friday";
        case Day::SATURDAY:
            return "Saturday";
        case Day::SUNDAY:
            return "Sunday";
        default:
            return "Unknown";
    }
}

int main () {

    Day targetday = Day::MONDAY;

    //输出的分别是Monday，Friday，Unknown，Unknown
    std::cout << getName(targetday) << std::endl;
    std::cout << getName(static_cast<Day>(10)) << std::endl;
    std::cout << getName(static_cast<Day>(5)) << std::endl;
    std::cout << getName(static_cast<Day>(NULL)) << std::endl;

    return 0;
}
