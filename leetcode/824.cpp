/*
 * @Author: chamip
 * @Date: 2022-04-21 12:19:29
 * @LastEditTime: 2022-04-22 09:23:13
 * @LastEditors: chamip
 * @FilePath: /vscCpp/leetcode/824.cpp
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

class Solution {
private:
    bool isAEIOU(char c) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            return true;
        }
        return false;
    }
public:
    string toGoatLatin(string sentence) {
        int idx = 1;
        vector<string> res;
        int len = sentence.size();
        string word;
        for (int i = 0 ; i < len; ++i) {
            if (sentence[i] == ' ') {
                if (isAEIOU(word[0])) {
                    word += "ma";
                } else {
                    word = word.substr(1, word.size() - 1) + word[0] + "ma";
                }
                for (int j = 0; j < len; ++j) {
                    word += 'a';
                }
                ++idx;
                res.push_back(word);
                word.clear();
            } else {
                word += sentence[i];
            }
        }
        if (isAEIOU(word[0])) {
            word += "ma";
        } else {
            word = word.substr(1, word.size() - 1) + word[0] + "ma";
        }
        for (int j = 0; j < len; ++j) {
            word += 'a';
        }
        string ans;
        for (int i = 0; i < res.size() - 1; ++i) {
            ans += res[i] + ' ';
        }
        ans += res[res.size()];
        return ans;
    }
};

int main(void)
{
    Solution* s = new Solution();
    string ans = s->toGoatLatin("apple");
    cout << ans << endl;
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    return 0;
}