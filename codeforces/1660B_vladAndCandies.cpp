/*
 * @Author: chamip
 * @Date: 2022-04-06 00:05:07
 * @LastEditTime: 2022-04-06 16:50:26
 * @LastEditors: chamip
 * @FilePath: /vscCpp/codeforces/1660B_vladAndCandies.cpp
 */

#include <iostream>
#include <vector>

bool eatCandies(std::vector<int>& a) {

        if (a.size() == 1) {
            if (a[0] > 1) {
                return false;
            }
            return true;
        }
        int n = a.size();
        sort(a.begin(), a.end());
        // for (int i = 0; i < a.size(); ++i) {
        //     std::cout << a[i] << " ";
        // }
        if (a[n] > a[n - 1] + 1) {
            return false;
        }
        return true;
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> a;
        a.resize(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> a[j];
        }
        if (eatCandies(a)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } 
    return 0;
}