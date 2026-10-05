#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    float score;
    Student(int id, std::string name, float score) : id(id), name(name), score(score) {};
    void setScore(float score) {
        this->score = score;
    }
};

int main() {
    Student *student = new Student(666,"Jason",99.5);
    student->id = 42;
    student->setScore(11.5);
    std::cout << student->id << std::endl;
    std::cout << student->score << std::endl;
    return 0;
}
