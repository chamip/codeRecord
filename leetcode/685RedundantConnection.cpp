/*
 * @Author: chamip
 * @Date: 2022-10-21 16:01:52
 * @LastEditTime: 2022-10-21 17:46:14
 * @LastEditors: chamip
 * @FilePath: /codeRecord/leetcode/685RedundantConnection.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    static const int N = 1010;
    int n;
    int parent[N];
    
    void Init() {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int Find(int idx) {
        return parent[idx] == idx ? parent[idx] : parent[idx] = Find(parent[idx]);
    }

    void Union(int idx1, int idx2) {
        parent[Find(idx2)] = Find(idx1);
    }

    bool same(int idx1, int idx2) {
        return Find(idx1) == Find(idx2);
    }

    vector<int> getRemovedEdge(const vector<vector<int>>& edges) {
        Init();
        for (int i = 0; i < n; ++i) {
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            Union(edges[i][0], edges[i][1]);
        }
        return vector<int>{};
    }

    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int delEdge) {
        Init();
        for (int i = 0; i < n; ++i) {
            if (i == delEdge) {
                continue;
            }
            if (same(edges[i][0], edges[i][1])) {
                return false;
            }
            Union(edges[i][0], edges[i][1]);
        }
        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        int inDegrees[N] = {0};
        for (int i = 0; i < n; ++i) {
            ++inDegrees[edges[i][1]];//入度
        }
        vector<int> vec;
        for (int i = n - 1; i >= 0; --i) {
            if (inDegrees[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }
        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0])) {
                return edges[vec[0]];
            } else {
                return edges[vec[1]];
            }
        }
        return getRemovedEdge(edges);
    }
};

int main(int argc, char const *argv[]) 
{
    Solution* s = new Solution();
    vector<vector<int> > edges = {{2,1},{3,1},{4,2},{1,4}};
    vector<int> res = s->findRedundantDirectedConnection(edges);
    for (int x : res) {
        cout << x << endl;
    }
    return 0;
}