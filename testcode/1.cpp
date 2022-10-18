/*
 * @Author: chamip
 * @Date: 2022-04-21 11:23:34
 * @LastEditTime: 2022-04-21 11:30:26
 * @LastEditors: chamip
 * @FilePath: /vscCpp/projecteuler/1.cpp
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
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
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
    //If we list all the natural numbers below 10 that are multiples of 3 or 5, 
    //we get 3, 5, 6 and 9. The sum of these multiples is 23.
    //Find the sum of all the multiples of 3 or 5 below 1000.
    int sum = 0;
    vector<int> res;
    for (int x = 3; x < 1000; ++x) {
        if ((x % 3 == 0) || (x % 5 == 0)) {
            sum += x;
            res.push_back(x);
        }
    }
    cout << sum << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << res[i] << " ";
    }
    cout << endl;
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    return 0;
}