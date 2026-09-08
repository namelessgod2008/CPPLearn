#include <iostream>

//普通双向链表
// ========================================================================
// Node（节点）：双向链表的"一格"
//     prev → 指向前一个节点（没有则为 nullptr）
//     next → 指向后一个节点（没有则为 nullptr）
//     data → 存的数据
//
//     Node(int data) 是构造函数：
//       用参数 data 初始化 data 字段，并把 prev/next 都置为 nullptr
//       （新节点刚创建时"两头空空"，谁都不连）
// ========================================================================
struct Node {
    Node *prev;
    Node *next;
    int data;

    Node(int data) : prev(nullptr), next(nullptr), data(data) {}
};

// ========================================================================
// DoublyLinkedList（双向链表）
//     head → 指向第一个节点；tail → 指向最后一个节点
//     空表时 head 和 tail 都是 nullptr
//     通过 head/tail + 每个节点的 prev/next，可以从两头遍历
// ========================================================================
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // ---- 构造函数：初始化为空表 ----
    DoublyLinkedList() : head(nullptr), tail(nullptr) {};

    // ---- 析构函数：逐个释放所有节点，防止内存泄漏 ----
    // 从头开始，用临时指针 temp 记住当前，再移到 next，
    // 然后 delete temp——这样删当前节点不影响继续往下走
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // ====================================================================
    // addAtHead：头插法 —— 在链表【最前面】插入新节点
    //     分两种情况：
    //       a) 空表：新节点是唯一节点，head/tail 都指向它
    //       b) 非空：三步——① 新节点.next = 原head
    //                       ② 原head.prev = 新节点
    //                       ③ head 更新为新节点
    //     注意：尾 tail 只有在空表时才动；非空插头不影响尾
    // ====================================================================
    void addAtHead (int data) {
        Node* newNode = new Node (data);
        if (head == nullptr) {          // 空表：既是头也是尾
            head = newNode;
            tail = newNode;
        }
        else {                          // 非空：接到原头之前
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // ====================================================================
    // addAtTail：尾插法 —— 在链表【最后面】插入新节点
    //     和 addAtHead 对称，不过动的是 tail：
    //       a) 空表：同上
    //       b) 非空：① 新节点.prev = 原tail
    //                ② 原tail.next = 新节点
    //                ③ tail 更新为新节点
    // ====================================================================
    void addAtTail (int data) {
        Node* newNode = new Node (data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // ====================================================================
    // isEmpty：判断链表是否为空
    //     双向链表中 head/tail 同生共死（都 null 或都非 null），
    //     其实只查 head == nullptr 即可，多查 tail 是更"保险"的写法
    // ====================================================================
    bool isEmpty () {
        if (head == nullptr || tail == nullptr) {
            return true;
        }
        return false;
    }

    // ====================================================================
    // getNodeCount：数一数链表里有多少个节点
    //     从 head 开始沿 next 一路走到 nullptr，边走边数
    //     空表返回 0，否则 count 从 1 起（当前节点自己算一个）
    // ====================================================================
    int getNodeCount() {
        int count = 1;
        Node* current = head;
        if (isEmpty()) {
            return 0;
        }
        while (current->next != nullptr) {
            current = current->next;
            count++;
        }
        return count;
    }

    // ====================================================================
    // insertAfter：在"下标为 indexbias 的节点"【之后】插入新节点
    //     indexbias = 0  → 插到第 0 个节点后（即第1个节点后面）
    //     indexbias 很大 → 越界，此时追加到链表【尾部】
    //
    //     注意本类的下标约定：
    //       getData(0) 返回第 1 个节点(head)的值
    //       所以 indexbias=1 指"第 2 个节点"，即 head->next
    //       遍历用 do-while 走到目标位；到末尾(cur->next==null)就停
    // ====================================================================
    void insertAfter (int data, unsigned int indexbias) {
        Node* newNode = new Node (data);
        if (isEmpty()) {                // 空表：唯一节点
            head = newNode;
            tail = newNode;
            return;
        }

        Node* current = head;

        if (getNodeCount() == 1) {      // 只有一个节点：直接挂到 head 后面
            head->next = newNode;
            newNode->prev = head;
            tail = newNode;
            return;
        }

        if (indexbias == 0) {           // 插到 head 之后 = 第二个位置
            Node* currentnext = current->next;
            current->next = newNode;
            currentnext->prev = newNode;
            newNode->prev = current;
            newNode->next = currentnext;
            return;
        }

        // 从 head 往后走 indexbias 步；一旦走到末尾就停（防越界）
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        } while (indexbias > 0);

        if (current->next == nullptr) {
            // 已到末尾（越界或刚好走完）：追加到尾部，更新 tail
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
            return;
        }

        // 正常中插：在 current 之后插入（四步接上前后两根链）
        Node* currentnext = current->next;
        current->next = newNode;
        currentnext->prev = newNode;
        newNode->prev = current;
        newNode->next = currentnext;
    }

    // ====================================================================
    // insertbefore：在"下标为 indexbias 的节点"【之前】插入新节点
    //     和 insertAfter 相反，接线时动的是 prev 链
    //
    //     特别约定（你自己定义的行为）：
    //       indexbias 太大（越界）时，current 会停在【最后一个节点】，
    //       于是把新节点插到"最后一个节点前面"——不是追加到末尾！
    //       例：{10,20,30,40}  insertbefore(99, 100) → {10,20,30,99,40}
    // ====================================================================
    void insertBefore (int data, unsigned int indexbias) {
        Node* newNode = new Node (data);
        if (isEmpty()) {                // 空表：唯一节点
            head = newNode;
            tail = newNode;
            return;
        }

        Node* current = head;

        if (getNodeCount() == 1) {      // 只有一个节点：前插到 head 前面，成为新 head
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }

        if (indexbias == 0) {           // 插到头部之前，同样是换 head
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }

        // 从 head 往后走 indexbias 步；到末尾就停（停在最后一个节点上）
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        } while (indexbias > 0);

        // 中插：把 newNode 插到 current 前面
        //（current 如果是尾节点也没关系——正好实现"插到最后一个前面"）
        Node* currentprev = current->prev;
        currentprev->next = newNode;
        newNode->prev = currentprev;
        newNode->next = current;
        current->prev = newNode;
    }

    // ====================================================================
    // getData：按下标(indexbias)读取第 indexbias 个节点的值
    //     indexbias = 0 → 返回第 1 个节点(head)的值
    //     越界时 current 会停在最后一个节点，返回它的值（没有报错）
    //     空表返回 0（没有可读数据）
    // ====================================================================
    int getData(unsigned int indexbias) {
        if (isEmpty()) {
            return 0;
        }
        Node* current = head;
        if (getNodeCount() == 1) {
            return current->data;
        }
        if (indexbias == 0) {
            return current->data;
        }
        // 沿 next 走 indexbias 步；到末尾就停，返回末位节点的值
        do {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        } while (indexbias > 0);
        return current->data;
    }

    void deleteIndexBias (unsigned int indexbias) {
        if (isEmpty()) {
            return;
        }
        Node* current = head;
        if (getNodeCount() == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        while (indexbias > 0) {
            current = current->next;
            indexbias--;
            if (current->next == nullptr) {
                break;
            }
        }
        Node* cachedcurrentprev = current->prev;
        Node* cachedcurrentnext = current->next;
        if (cachedcurrentnext == nullptr) {
            delete tail;
            tail = cachedcurrentprev;
            tail->next = nullptr;
            return;
        }
        if (cachedcurrentprev == nullptr) {
            delete head;
            head = cachedcurrentnext;
            head->prev = nullptr;
            return;
        }
        Node* currentprev = current->prev;
        Node* currentnext = current->next;
        delete current;
        currentprev->next = currentnext;
        currentnext->prev = currentprev;
    }
};

// ========================================================================
// main：演示用
//     建空表 → 头插10 → 尾插20/30/40 → 在超大下标处插114
//     （insertAfter 越界会追加到尾部，所以 114 会到最末尾）
//     然后打印节点数、下标3的值、超大下标的值
// ========================================================================
int main () {
    auto* list = new DoublyLinkedList();
    list->addAtHead(10);
    list->addAtTail(20);
    list->addAtTail(30);
    list->addAtTail(40);
    list->insertAfter(114,100);   // 越界 → 114 追加到尾部

    int count = list->getNodeCount();
    std::cout << count << std::endl;

    std::cout << list->getData(3) << std::endl;

    std::cout << list->getData(1000) << std::endl;   // 越界 → 返回末尾值

    delete list;
    return 0;
}
