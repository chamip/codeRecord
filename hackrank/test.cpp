/*
 * @Author: chamip
 * @Date: 2022-04-13 10:08:46
 * @LastEditTime: 2022-04-13 10:08:47
 * @LastEditors: chamip
 * @FilePath: /vscCpp/hackrank/test.cpp
 */
#include <iostream>

int main()
{
    using namespace std;
    using namespace boost::typeindex;

    auto p = std::make_pair(1, 2);
    cout << type_id_with_cvr<decltype(p)>().pretty_name();
}