#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		vector<vector<vector<int>>> vvvi(2, vector<vector<int>>(n));
		for (const auto &red : redEdges) {
			vvvi[0][red[0]].emplace_back(red[1]);
		}        
		for (const auto &blue : blueEdges) {
			vvvi[1][blue[0]].emplace_back(blue[1]);
		} 
		vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
		queue<pii> qp;
		dist[0][0] = 0;
		dist[1][0] = 0;
		qp.push({0, 0});
		qp.push({0, 1});
		while (!qp.empty()) {
			auto [node, type] = qp.front();
			qp.pop();
			for (const auto &node1 : vvvi[1 - type][node]) {
				if (dist[1 - type][node1] != INT_MAX) continue;
				dist[1 - type][node1] = dist[type][node] + 1;
				qp.push({node1, 1 - type});
			} 
		}
		vector<int> res(n);
		for (int i = 0; i < n; ++i) {
			res[i] = min(dist[0][i], dist[1][i]);
			if (res[i] == INT_MAX) {
				res[i] = -1;
			}
		}
		return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int n = 3;
	vector<vector<int>> redEdges {{0, 1}, {1, 2}};
	vector<vector<int>> blueEdges {};
	vector<int> res = s->shortestAlternatingPaths(n, redEdges, blueEdges);
	for (const auto x : res) {
		cout << x << " ";
	}
	cout << endl;
	delete s;
	return 0;
}
