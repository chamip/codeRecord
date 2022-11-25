#include <iostream>
#include <vector>
using namespace std;
int findJudge(int n, vector<vector<int>>& trust) {
	vector<int> inDegree(n + 1, 0);
	vector<int> outDegree(n + 1, 0);
	for (auto x : trust) {
		++outDegree[x[0]];
		++inDegree[x[1]];
	}
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == n - 1 && outDegree[i] == 0) {
			return i;
		}
	}
    return -1;
}

int main(int argc, char const *argv[])
{
	int n = 3;
	vector<vector<int>> trust {{1,2}, {2,3}};
	cout << findJudge(n, trust) << endl;
	return 0;
}
