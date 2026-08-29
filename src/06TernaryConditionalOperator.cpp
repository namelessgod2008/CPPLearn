#include <iostream>
#include <string>

int main() {

    int a = 10;

    int b = 5;

    //三元运算符
    //condition ？ ifTrue : ifFalse
    std::string c = a > b ? "true" : "false" ;

    std::cout << c << std::endl;

    return 0;
}
