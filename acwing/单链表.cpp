#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar)      memset(ar,0,sizeof(ar))
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define sz(a)       (int)a.size()

//#define lowbit(x) (x&(-x))
typedef long long LL;
// typedef unsigned long long ULL;
// const int    prime = 999983;
// const int    INF = 0x7FFFFFFF;
// const LL     INFF =0x7FFFFFFFFFFFFFFF;
// const double pi = acos(-1.0);
// const double inf = 1e18;
// const double eps = 1e-6;
const LL     mod = 1e9 + 7;
//const int    NUM = 2e5 + 10;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int t;
const int NUM = 1e5 + 10;
int head, e[NUM], ne[NUM], idx;

void init() {
	head = -1;
	idx = 0;
	return ;
}

void add_to_head(int x) {
	e[idx] = x;
	ne[idx] = head;
	head = idx++;
	return ;
}

void remove(int k) {
	if (k == -1) head = ne[head];
	else ne[k] = ne[ne[k]];
	return ;
}

void add(int k, int x) {
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
	return ; 
}

void solve() {
    char op;
    int k, x;
    std::cin >> op;
    if (op == 'H') {
    	std::cin >> x;
    	add_to_head(x);
    } else if(op == 'D') {
    	std::cin >> k;
    	remove(k - 1);
    } else if (op == 'I') {
    	std::cin >> k >> x;
    	add(k - 1, x);
    }
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cin >> t;
    init();
    while (t--) {
      solve();
    }
    for (int i = head; i != -1; i = ne[i]) {
    	std::cout << e[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
