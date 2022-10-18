/*
 * @Author: chamip
 * @Date: 2022-04-18 09:27:24
 * @LastEditTime: 2022-04-18 09:34:16
 * @LastEditors: chamip
 * @FilePath: /vscCpp/leetcode/386.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};


int main(int argc, char const* argv[])
{
    int n = 13;
    Solution* s = new Solution();
    vector<int> res;
    res = s->lexicalOrder(n);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}