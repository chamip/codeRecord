
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node, int &res, vector<int>& cnt) {
        if (node == nullptr) {
            return ;
        }
        ++cnt[node->val];
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->val << " ;";
            int tmp = 0;
            for (int i = 1; i < 10; ++i) {
                cout << cnt[i] << " ";
                if (cnt[i] % 2) {
                    ++tmp;
                }
            }
            if (tmp <= 1) {
                ++res;
            }
            cout << "| " << res << endl;
        }else {
            dfs(node->left, res, cnt);
            dfs(node->right, res, cnt);
        }
        --cnt[node->val];
        return ;

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        vector<int> cnt(10);
        dfs(root, res, cnt);
        return res;
    }
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
    vector<int> preorder = {2,3,1,3,1,NULL,1};
    TreeNode* root = buildTree(preorder);
    Solution* s = new Solution();
    cout << s->pseudoPalindromicPaths(root) << endl;
    return 0;
}