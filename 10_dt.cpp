#include <iostream>
// 把 10DoublyLinkedList.cpp 整个 include，但屏蔽它的 main
#define main real_main_dont_use
#include "src/10DoublyLinkedList.cpp"
#undef main

// 临时替换 main 为测试
int test_main() {
    auto* list = new DoublyLinkedList();
    list->addAtHead(10); list->addAtTail(20); list->addAtTail(30); list->addAtTail(40);
    list->deleteIndexBias(0);   // 删头
    delete list;
    return 0;
}
