#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

int main(int argc, char const *argv[])
{
	std::string str;
	std::cin >> str;
	int n = str.size();
	std::unordered_set<char> usc;
	std::stack<char> sc;
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		char ch = str[i];
		if (isalpha(ch) || ch == '(') {
			sc.push(ch);
			if (isalpha(ch)) {
				if (usc.count(ch)) {
					flag = false;
					break;
				} else {
					usc.emplace(ch);
				}
			}
		} else if (ch == ')') {
			while (!sc.empty()) {
				char tmp = sc.top();
				sc.pop();
				if (isalpha(tmp)) usc.erase(tmp);
				else if (tmp == '(') break;
			}
		}
	}
	if (flag) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	return 0;
}