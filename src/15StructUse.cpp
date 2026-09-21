#include <iostream>

struct Student {
    int id;
    std::string name;
    float score;
    Student(int id, std::string name, float score) : id(id), name(name), score(score) {};
};

int main() {
    Student *student = new Student(666,"Jason",99.5);
    student->id = 42;
    std::cout << student->id << std::endl;
    return 0;
}
