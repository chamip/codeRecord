/*
 * @Author: chamip
 * @Date: 2022-07-27 17:47:11
 * @LastEditTime: 2022-10-14 09:54:15
 * @LastEditors: chamip
 * @FilePath: /vscCpp/newcoder/1.cpp
 */
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

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        if (!n) {
            return 0;
        }
        int dp0 = 0, dp1 = nums[0];

        for (int i = 1; i < n; ++i){
            int tdp0 = max(dp0, dp1); // 计算 dp[i][0]
            int tdp1 = dp0 + nums[i]; // 计算 dp[i][1]

            dp0 = tdp0; // 用 dp[i][0] 更新 dp_0
            dp1 = tdp1; // 用 dp[i][1] 更新 dp_1
        }
        return max(dp0, dp1);
    }
};

int main(void)
{
	using std::cout;
	using std::endl;
	std::vector<string> v{"zhe", "shi", "yi", "dao", "qian", "dao", "ti"};
	for (auto str : v) {
		cout << str << endl;
	}
    return 0;
}
