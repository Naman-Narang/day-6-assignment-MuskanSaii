#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversalHelper(root->left, result);

    result.push_back(root->val);

    inorderTraversalHelper(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderTraversalHelper(root, result);
    return result;
}

TreeNode* buildTree(const vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) { 
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}
int main() {
    vector<int> treeNodes1 = {1, -1, 2, -1, -1, 3}; 
    TreeNode* root1 = buildTree(treeNodes1, 0);
    vector<int> result1 = inorderTraversal(root1);
    cout << "Inorder Traversal: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

 
    vector<int> treeNodes2 = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    TreeNode* root2 = buildTree(treeNodes2, 0);
    vector<int> result2 = inorderTraversal(root2);
    cout << "Inorder Traversal: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
