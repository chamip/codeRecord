#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

static const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& heights);

int main(void)
{
 //    #ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> vec[i][j];
    	} 
    }
    cout << endl;
    vector<vector<int>> res = pacificAtlantic(vec);
    int mr = res.size();
    int nr = res[0].size();
    for (int i = 0; i < mr; ++i) {
    	for (int j = 0; j < nr; ++j) {
    		cout << res[i][j] << " ";
    	}
    	cout << endl;
    }
    cin.get();
    cin.get();
    return 0;
}

void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
	if (visited[row][col]) {
		return ;
	}
	visited[row][col] = true;
	for (int i = 0; i < 4; ++i) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (newrow >= 0 && newrow < heights.size() && newcol >= 0 && newcol < heights[0].size() && heights[newrow][newcol] >= heights[row][col]) {
			dfs(newrow, newcol, visited, heights);
		}
	}
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	vector<vector<int>> res;
	int m = heights.size();
	int n = heights[0].size();
	vector<vector<bool>> pacific(m, vector<bool>(n, false));
	vector<vector<bool>> atlantic(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i) {
		dfs(i, 0, pacific, heights);
	}
	for (int j = 1; j < n; ++j) {
		dfs(0, j, pacific, heights);
	}
	for (int i = 0; i < m; ++i) {
		dfs(i, n - 1, atlantic, heights);
	}
	for (int j = 0; j < n; ++j) {
		dfs(m - 1, j, atlantic, heights);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (pacific[i][j] && atlantic[i][j]) {
				res.push_back({i, j});
			}
		}
	}
	return res;
}