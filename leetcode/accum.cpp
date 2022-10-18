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

int main(void)
{
 //    #ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    int n;
    cin >> n;
    vector<int> v;
   	while (n > 0) {
   		v.push_back(n % 2);
   		n /= 2;
   	}
   	// for (int i = 0; i < v.size(); ++i) {
   	// 	cout << v[i] << " ";
   	// }
   	// cout << endl;
   	int res = 0;
   	int left = -1;
   	int right = -1;
   	// cout << v.size() << endl;
   	for (int i = 0; i < v.size(); ++i) {
   		if (v[i] == 1) {
   			if (left == -1) {
   				left = i;
   				// cout << "left = " << left << " ";
   			} else if (right == -1) {
   				right = i;
   				// cout << "right = " << right << " ";
   			}
   			if (left != -1 && right != -1) {
   				res = max(res, right - left);
   				// cout << "right - left = " << right - left << endl;
   				left = i;
   				right = -1;
   			}
   		}
   	}
   	cout << res << endl;
    cin.get();
    cin.get();
    return 0;
}