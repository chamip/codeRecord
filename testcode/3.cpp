/*
 * @Author: chamip
 * @Date: 2022-04-21 11:45:55
 * @LastEditTime: 2022-04-21 11:59:18
 * @LastEditors: chamip
 * @FilePath: /vscCpp/projecteuler/3.cpp
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

bool isPrime(long x) {
    for (long i = 3; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main(void)
{
    //The prime factors of 13195 are 5, 7, 13 and 29.
    //What is the largest prime factor of the number 600851475143 ?
    int res = 0;
    // long num = 13195;
    long num = 600851475143;
    for (long i = 3; i < num; i = i + 2) {
        if (isPrime(i)) {
            while (num % i == 0) {
                num = num / i;
            }
        }
    }
    cout << num << endl;
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    return 0;
}