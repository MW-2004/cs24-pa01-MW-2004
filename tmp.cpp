
/*
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    class Iterator {
    public:
        std::vector<TreeNode*> nodeStack;
        TreeNode* current;

        Iterator(TreeNode* root) {
            current = root;
            operator++();
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current || !nodeStack.empty();
        }

        Iterator& operator++() {
            while (current != nullptr || !nodeStack.empty()) {
                while (current != nullptr) {
                    nodeStack.push_back(current);
                    current = current->left;
                }
                current = nodeStack.back();
                nodeStack.pop_back();
                break;
            }
            return *this;
        }

        TreeNode *operator*()  {
            auto tmp=current;
            current=current->right;
            return tmp;
        }
    };

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    // Example usage
    BST myBST;
    myBST.root = new TreeNode(5);
    myBST.root->left = new TreeNode(3);
    myBST.root->right = new TreeNode(8);
    myBST.root->left->left = new TreeNode(2);
    myBST.root->left->right = new TreeNode(4);
    myBST.root->right->left = new TreeNode(6);
    myBST.root->right->right = new TreeNode(9);

    // Use in a range-based for loop
    for (auto value : myBST) {
        std::cout<<"out: " << value->value << "\n";
        delete value;
    }

    std::cout << std::endl;

    return 0;
}*/
