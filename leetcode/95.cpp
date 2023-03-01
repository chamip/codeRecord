#include <iostream>
#include <vector>
using namespace std;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<TreeNode*> generatorTree(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> allTrees;
        allTrees.clear();
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTree = generatorTree(start, i - 1);
            vector<TreeNode*> rightTree = generatorTree(i + 1, end);
            for (auto &left : leftTree) {
                for (auto &right : rightTree) {
                    TreeNode *curNode = new TreeNode(i);
                    curNode->left = left;
                    curNode->right = right;
                    allTrees.emplace_back(curNode);
                }
            }
        }
        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return generatorTree(1, n);
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Solution *s = new Solution();
    vector<TreeNode*> res = s->generateTrees(n);
    cout << res.size() << endl;
	return 0;
}
