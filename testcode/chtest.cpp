/*
 * @Author: chamip
 * @Date: 2022-08-31 17:35:38
 * @LastEditTime: 2022-10-18 23:15:49
 * @LastEditors: chamip
 * @FilePath: /vscCpp/chtest.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "\"binary\"";
	string s1 = "binary";
	cout << "s = " << s << endl;
	cout << "s1 = " << s1 << endl;
	char ch = '\"';
	cout << "\" = " << int(ch) << endl;
	cout << "34 = " << char(34) << endl;
	cout << "b = " << int('b') << endl;
	if (s.compare(s1) < 0) {
		cout << "s小于s1." << endl; 
	};
	return 0;
}