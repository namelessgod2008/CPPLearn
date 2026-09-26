#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

template<typename T>
std::string type_name() {
    int status = 0;
    char* demangled = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status);
    std::string result = (status == 0 && demangled) ? demangled : typeid(T).name();
    free(demangled);
    return result;
}

template<class Member,class Container>
Container* container_of(Member *member,Member Container:: *abstract_member_ptr) {
    auto* base = reinterpret_cast<Container*>(nullptr);
    auto offset = reinterpret_cast<std::ptrdiff_t>(&(base->*abstract_member_ptr) - static_cast<char*>(base));
    auto* result = reinterpret_cast<Container*>(reinterpret_cast<char*>(member) - offset);
    std::cout << type_name<decltype(abstract_member_ptr)>();
    return result;
}

struct Node {
    Node* next;
    Node* prev;
};

struct Data {
    int data;
    Node node;
};

class InstructiveDoublyLinkedList {
    Node* head;
    Node* tail;
public:
    InstructiveDoublyLinkedList(): head(nullptr), tail(nullptr) {}
};

int main () {
    auto* list = new InstructiveDoublyLinkedList();
    delete list;
    return 0;
}
