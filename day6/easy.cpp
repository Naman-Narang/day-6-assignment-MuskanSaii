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
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true; 
    if (!p || !q) return false; 
    if (p->val != q->val) return false; 
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    vector<int> treeNodesP1 = {1, 2, 3};
    vector<int> treeNodesQ1 = {1, 2, 3};
    TreeNode* p1 = buildTree(treeNodesP1, 0);
    TreeNode* q1 = buildTree(treeNodesQ1, 0);
    cout << "Are trees the same? " << (isSameTree(p1, q1) ? "true" : "false") << endl;

    vector<int> treeNodesP2 = {1, 2};
    vector<int> treeNodesQ2 = {1, -1, 2}; 
    TreeNode* p2 = buildTree(treeNodesP2, 0);
    TreeNode* q2 = buildTree(treeNodesQ2, 0);
    cout << "Are trees the same? " << (isSameTree(p2, q2) ? "true" : "false") << endl;
    return 0;
}
