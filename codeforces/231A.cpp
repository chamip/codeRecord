/*
 * @Author: chamip
 * @Date: 2023-01-21 16:49:37
 * @LastEditTime: 2023-01-21 16:53:48
 * @LastEditors: chamip
 * @FilePath: /codeRecord/codeforces/231A.cpp
 */

#include <ios>
#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int res = 0;
    while (n--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a + b + c >= 2) ++res;
    }
    std::cout << res << std::endl;
    return ;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}