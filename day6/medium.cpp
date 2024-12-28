#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }
    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inorderMap[rootVal];
    root->left = buildTreeHelper(preorder, inorder, preorderIndex, inorderStart, rootIndex - 1, inorderMap);
    root->right = buildTreeHelper(preorder, inorder, preorderIndex, rootIndex + 1, inorderEnd, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;

    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }

    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;

    vector<TreeNode*> queue = {root};
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.erase(queue.begin());
        if (node) {
            cout << node->val << " ";
            queue.push_back(node->left);
            queue.push_back(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}
int main() {
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = buildTree(preorder1, inorder1);
    cout << "Level Order Traversal of Constructed Tree: ";
    printLevelOrder(root1);

    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = buildTree(preorder2, inorder2);
    cout << "Level Order Traversal of Constructed Tree: ";
    printLevelOrder(root2);

    return 0;
}
