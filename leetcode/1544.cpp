#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string makeGood(string s) {
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (!st.empty()) {
            if ((s[i] - st.top() == 32) || (st.top() - s[i] == 32)) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    if (s.size() != 0) {
        reverse(res.begin(), res.end());
    }
    return res;
}
int main(int argc, char const *argv[])
{
//	string s = "leEeetcode";
	string s = "abBAcC";
	cout << makeGood(s) << endl;
	return 0;
}
