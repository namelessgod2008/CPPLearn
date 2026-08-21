#include <iostream>
#include <string>

enum class Day {
    Monday = 0,
    Tuesday = 1,
    Wednesday = 2,
    Thursday = 3,
    Friday = 4,
    Saturday = 5,
    Sunday = 6,
};

std::string getName(Day day) {
    switch (day) {
        case Day::Monday:
            return "Monday";
        case Day::Tuesday:
            return "Tuesday";
        case Day::Wednesday:
            return "Wednesday";
        case Day::Thursday:
            return "Thursday";
        case Day::Friday:
            return "Friday";
        case Day::Saturday:
            return "Saturday";
        case Day::Sunday:
            return "Sunday";
        default:
            return "Unknown";
    }
}

int main () {

    Day targetday = Day::Monday;

    std::cout << getName(targetday) << std::endl;
    std::cout << getName(static_cast<Day>(10)) << std::endl;
    std::cout << getName(static_cast<Day>(NULL)) << std::endl;

    return 0;
}
