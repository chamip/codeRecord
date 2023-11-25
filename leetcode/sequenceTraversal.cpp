#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& levelorder) {
    if(levelorder.empty()) return nullptr;
    TreeNode* root = new TreeNode(levelorder[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(i < levelorder.size()) {
        TreeNode* node = q.front();
        q.pop();
        if(levelorder[i] != NULL) {
            node->left = new TreeNode(levelorder[i]);
            q.push(node->left);
        }
        if(i + 1 < levelorder.size() && levelorder[i + 1] != NULL) {
            node->right = new TreeNode(levelorder[i + 1]);
            q.push(node->right);
        }
        i += 2;
    }
    return root;
}

int main() {
    vector<int> levelorder = {2,3,1,3,1,NULL,1};
    TreeNode* root = buildTree(levelorder);
    return 0;
}