#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
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
    int n;
	cin >> n;
	while (n--) {
		int nums;
		cin >> nums;
		int *candies = new int[nums];
		for (int i = 0; i < nums; ++i) {
			cin >> candies[i];
		}
		int minCan = candies[0];
		int sum = candies[0];
		for (int j = 1; j < nums; ++j) {
			sum += candies[j];
			if (minCan > candies[j]) {
				minCan = candies[j];
			}
		}
		sum -= nums * minCan;
		cout << sum << endl;
		delete [] candies;
	}
	return 0;
}
