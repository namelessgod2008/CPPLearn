#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *super;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), super(nullptr) {
    }

    void setLeft(TreeNode *&leftNode) {
        this->left = leftNode;
    }

    void setRight(TreeNode *&rightNode) {
        this->right = rightNode;
    }

    void setSuper(TreeNode *&superNode) {
        this->super = superNode;
    }

    void autoSetLeft(TreeNode *&leftNode) {
        this->left = leftNode;
        leftNode->super = this;
    }

    void autoSetRight(TreeNode *&rightNode) {
        this->right = rightNode;
        rightNode->super = this;
    }
};

class LinkedBinaryTree {
private:
    TreeNode *root;

    LinkedBinaryTree() : root(nullptr) {
    }

    static void preOrderTraversalRecursiveHelper(TreeNode *start, std::vector<TreeNode *> &result) {
        if (start == nullptr) {
            return;
        }
        result.push_back(start);
        preOrderTraversalRecursiveHelper(start->left, result);
        preOrderTraversalRecursiveHelper(start->right, result);
    }

    static void inOrderTraversalRecursiveHelper(TreeNode *start, std::vector<TreeNode *> &result) {
        if (start == nullptr) {
            return;
        }
        inOrderTraversalRecursiveHelper(start->left, result);
        result.push_back(start);
        inOrderTraversalRecursiveHelper(start->right, result);
    }

    static void postOrderTraversalRecursiveHelper(TreeNode *start, std::vector<TreeNode *> &result) {
        if (start == nullptr) {
            return;
        }
        postOrderTraversalRecursiveHelper(start->left, result);
        postOrderTraversalRecursiveHelper(start->right, result);
        result.push_back(start);
    }

public:
    static LinkedBinaryTree *of() {
        return new LinkedBinaryTree();
    };

    static LinkedBinaryTree ofNoHeap() {
        return {};
    }

    ~LinkedBinaryTree() {
        auto i = levelOrderTraversal(root);
        for (TreeNode *&node: i) {
            delete node;
        }
    }

    void setRoot(TreeNode *rootNode) {
        this->root = rootNode;
    }

    static TreeNode *rootOf(TreeNode *current) {
        while (current->super != nullptr) {
            current = current->super;
        }
        return current;
    }

    [[nodiscard]] bool isEmpty() const {
        if (this->root == nullptr) {
            return true;
        }
        return false;
    }

    static bool isNullPointer(const TreeNode *node) {
        if (node == nullptr) {
            return true;
        }
        return false;
    }

    static std::vector<int> toIntVec(std::vector<TreeNode *> &input) {
        std::vector<int> result;
        for (TreeNode *&node: input) {
            result.push_back(node->val);
        }
        return result;
    }

    static void printVal(std::vector<int> &input) {
        for (auto &val: input) {
            std::cout << val;
        }
        std::cout << std::endl;
    }

    static std::vector<TreeNode *> levelOrderTraversal(TreeNode *start) {
        std::vector<TreeNode *> result;
        if (isNullPointer(start)) {
            return result;
        }

        std::queue<TreeNode *> queue;
        queue.push(start);

        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            result.push_back(node);
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        return result;
    }

    static std::vector<TreeNode *> preOrderTraversalIterate(TreeNode *start) {
        std::vector<TreeNode *> result;
        if (isNullPointer(start)) {
            return result;
        }

        std::stack<TreeNode *> stack;
        stack.push(start);

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            stack.pop();
            result.push_back(node);
            if (node->right != nullptr) {
                stack.push(node->right);
            }
            if (node->left != nullptr) {
                stack.push(node->left);
            }
        }
        return result;
    }

    static std::vector<TreeNode *> preOrderTraversalRecursive(TreeNode *start) {
        std::vector<TreeNode *> result;
        if (isNullPointer(start)) {
            return result;
        }
        preOrderTraversalRecursiveHelper(start, result);
        return result;
    }

    static std::vector<TreeNode *> inOrderTraversalRecursive(TreeNode *start) {
        std::vector<TreeNode *> result;
        if (isNullPointer(start)) {
            return result;
        }
        inOrderTraversalRecursiveHelper(start, result);
        return result;
    }

    static std::vector<TreeNode *> postOrderTraversalRecursive(TreeNode *start) {
        std::vector<TreeNode *> result;
        if (isNullPointer(start)) {
            return result;
        }
        postOrderTraversalRecursiveHelper(start, result);
        return result;
    }
};

int main() {
    auto *tree = LinkedBinaryTree::of();
    auto *treeNodeRoot = new TreeNode(1);
    auto *treeNode2 = new TreeNode(2);
    auto *treeNode3 = new TreeNode(3);
    auto *treeNode4 = new TreeNode(4);
    auto *treeNode5 = new TreeNode(5);

    tree->setRoot(treeNodeRoot);

    treeNodeRoot->left = treeNode2;
    treeNodeRoot->right = treeNode3;
    treeNode2->left = treeNode4;
    treeNode2->right = treeNode5;

    treeNode2->super = treeNodeRoot;
    treeNode3->super = treeNodeRoot;
    treeNode4->super = treeNode2;
    treeNode5->super = treeNode2;

    std::cout << treeNodeRoot->val << std::endl;
    std::cout << treeNodeRoot->left->val << std::endl;
    std::cout << treeNodeRoot->right->val << std::endl;
    std::cout << treeNodeRoot->left->left->val << std::endl;
    std::cout << treeNodeRoot->left->right->val << std::endl;

    auto vec = LinkedBinaryTree::levelOrderTraversal(treeNodeRoot);
    auto nums = LinkedBinaryTree::toIntVec(vec);
    LinkedBinaryTree::printVal(nums);

    auto vec2 = LinkedBinaryTree::preOrderTraversalRecursive(treeNodeRoot);
    auto nums2 = LinkedBinaryTree::toIntVec(vec2);
    LinkedBinaryTree::printVal(nums2);

    auto vec3 = LinkedBinaryTree::inOrderTraversalRecursive(treeNodeRoot);
    auto nums3 = LinkedBinaryTree::toIntVec(vec3);
    LinkedBinaryTree::printVal(nums3);

    auto vec4 = LinkedBinaryTree::postOrderTraversalRecursive(treeNodeRoot);
    auto nums4 = LinkedBinaryTree::toIntVec(vec4);
    LinkedBinaryTree::printVal(nums4);

    delete tree;
}
