#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    // Base case: if the tree is empty, return depth as 0
    if (root == NULL) {
        return 0;
    }
    // Recursively calculate the depth of the left subtree
    int leftheight = maxDepth(root->left);
    // Recursively calculate the depth of the right subtree
    int rightheight = maxDepth(root->right);
    // The depth of the current node is the maximum of the depths of its subtrees plus 1
    int height = max(leftheight, rightheight) + 1;
    return height;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Maximum Depth of Binary Tree: " << maxDepth(root) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
