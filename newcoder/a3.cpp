/*
 * @Author: chamip
 * @Date: 2022-04-28 14:46:56
 * @LastEditTime: 2022-04-28 15:16:26
 * @LastEditors: chamip
 * @FilePath: /vscCpp/newcoder/a3.cpp
 */
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
#include <unordered_set>
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

int main(void)
{
 	// #ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    int m, n;
    cin >> m >> n;
    unordered_set<int> s;
	deque<int> dq;
    int x;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> x;
    	if (s.count(x) == 1) {
    		continue;
    	} else {
    		++cnt;
    		if (s.size() >= m) {
    			s.erase(dq.front());
				dq.pop_front();
    		}
    		s.emplace(x);
			dq.push_back(x);
    	}
    }
    cout << cnt << endl;
    cin.get();
    cin.get();
    return 0;
}