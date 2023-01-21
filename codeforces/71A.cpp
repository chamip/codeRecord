/*
 * @Author: chamip
 * @Date: 2023-01-20 23:03:19
 * @LastEditTime: 2023-01-21 15:24:19
 * @LastEditors: chamip
 * @FilePath: /codeRecord/codeforces/71A.cpp
 */
/*
 * way too long words
 * location: Yichang,Hubei
 */

#include <ios>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string str;
    while (n--) {
        str.clear();
        std::cin >> str;
        int len = (int)str.size();
        if (len <= 10) std::cout << str << std::endl;
        else std::cout << str[0] << std::to_string(len - 2) << str[len - 1] << std::endl;
    }
    return 0;
}