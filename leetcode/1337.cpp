#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool static cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> kwr;
    int m = mat.size();
	int n = mat[0].size();
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        int idx = 0;
        while (idx < n && mat[i][idx] == 1) {
            ++cnt;
            ++idx;
        }
        kwr.push_back(make_pair(i, cnt));
    }
    sort(kwr.begin(), kwr.end(), cmp);
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(kwr[i].first);
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> mat = {{1,0,0,0}, {1,1,1,1}, {1,0,0,0}, {1,0,0,0}};
	int k = 2;
	vector<int> res = kWeakestRows(mat, k);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
