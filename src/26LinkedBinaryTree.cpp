#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *super;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), super(nullptr) {}
};

class LinkedBinaryTree {
private:
    TreeNode *root;
    LinkedBinaryTree() : root(nullptr){}
public:
    static LinkedBinaryTree* of() {
        return new LinkedBinaryTree();
    };

    static LinkedBinaryTree ofNoHeap() {
        return {};
    }

    ~LinkedBinaryTree() {
        auto i = levelOrderTraversal(root);
        for (TreeNode*& node: i) {
            delete node;
        }
    }

    void setRoot(TreeNode* rootNode) {
        this->root = rootNode;
    }

    [[nodiscard]] bool isEmpty() const {
        if (root == nullptr) {
            return true;
        }
        return false;
    }

    std::vector<TreeNode*> levelOrderTraversal(TreeNode* start) {
        std::vector<TreeNode*> result;
        if (isEmpty()) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(start);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
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
};

int main() {
    auto* tree = LinkedBinaryTree::of();
    auto* treeNodeRoot = new TreeNode(1);
    auto* treeNode2 = new TreeNode(2);
    auto* treeNode3 = new TreeNode(3);
    auto* treeNode4 = new TreeNode(4);
    auto* treeNode5 = new TreeNode(5);

    tree->setRoot(treeNodeRoot);

    treeNodeRoot->left = treeNode2;
    treeNodeRoot->right = treeNode3;
    treeNode2->left = treeNode4;
    treeNode2->right = treeNode5;

    treeNode2->super = treeNodeRoot;
    treeNode3->super = treeNodeRoot;
    treeNode4->super = treeNode2;
    treeNode5->super = treeNode2;

    std::cout<<treeNodeRoot->val<<std::endl;
    std::cout<<treeNodeRoot->left->val<<std::endl;
    std::cout<<treeNodeRoot->right->val<<std::endl;
    std::cout<<treeNodeRoot->left->left->val<<std::endl;
    std::cout<<treeNodeRoot->left->right->val<<std::endl;

    auto vec = tree->levelOrderTraversal(treeNodeRoot);
    std::vector<int> nums;
    for (TreeNode*& node: vec) {
        nums.push_back(node->val);
    }
    for (int& j: nums) {
        std::cout<<j<<std::endl;
    }

    delete tree;
}