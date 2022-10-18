/*
 * @Author: chamip
 * @Date: 2022-04-14 11:27:32
 * @LastEditTime: 2022-04-14 11:57:04
 * @LastEditors: chamip
 * @FilePath: /vscCpp/leetcode/1.cpp
 */
/*
 * 用户名的首字符必须是大写或者小写字母。
 * 用户名只能包含大小写字母，数字。
 * 用户名需要包含至少一个字母和一个数字。
 * 如果用户名合法，请输出 "Accept"，反之输出 "Wrong"。
 */
#include <iostream>
#include <string>
// #include <cstring>

const std::string s[2] = {"Accept", "Wrong"};

void check(const std::string& str) {
    int len = str.size();
    if (len == 0) {
        std::cout << s[1] << std::endl;
        return ;
    }
    if (!isalpha(str[0])) {
        std::cout << s[1] << std::endl;
        return ;
    }
    int cntNum = 0;
    int cntAlp = 0;
    for (int j = 0; j < len; ++j) {
        if (isalpha(str[j])) {
            ++cntAlp;
        } else if (isdigit((str[j]))) {
            ++cntNum;
        } else {
            std::cout << s[1] << std::endl;
            return ;
        }
    }
    if (cntAlp > 0 && cntNum > 0) {
        std::cout << s[0] << std::endl;
    } else {
        std::cout << s[1] << std::endl;
    }
    return ;
}

int main(int argc, char const *argv[])
{
    int t; //number of test cases.
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::string str;
        std::cin >> str;
        check(str);
    }
    return 0;
}