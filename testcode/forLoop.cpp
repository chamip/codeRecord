/*
 * @Author: chamip
 * @Date: 2023-01-17 11:18:17
 * @LastEditTime: 2023-01-17 11:30:08
 * @LastEditors: chamip
 * @FilePath: /codeRecord/testcode/forLoop.cpp
 */

#include <iostream>
#include <string>

const int NUM = 1e2;

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str = "";
    for (int i = 0; i < NUM; ++i) {
        str += "aa" + std::to_string(i);
    }
    std::cout << str << std::endl;
    return 0;
}