/*
 * @Author: chamip
 * @Date: 2022-04-04 01:06:03
 * @LastEditTime: 2022-04-06 16:50:19
 * @LastEditors: chamip
 * @FilePath: /vscCpp/codeforces/1660A_VasyaAndCoins.cpp
 */
#include <iostream>

int main()
{
    int t;
    int a, b;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> a >> b;
        if (a == 0) {
        std::cout << 1 << std::endl;
        } else {
            std::cout << a * 1 + b * 2 + 1 << std::endl;
        }
    }
    return 0;
}
