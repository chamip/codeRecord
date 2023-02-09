#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;

std::stack<int> num;
std::stack<char> op;
unordered_map<char, int> cmp {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
    int b = num.top(); num.pop();
    char oper = op.top(); op.pop();
    int a = num.top(); num.pop();
    int x = 0;
    if (oper == '+') {
        x = a + b;
    } else if (oper == '-') {
        x = a - b;
    } else if (oper == '*') {
        x = a * b;
    } else if (oper == '/') {
        x = a / b;
    }
    num.push(x);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        char ch = str[i];
        if (isdigit(ch)) {
            int x = 0, j = i;
            while (j < n && isdigit(str[j])) {
                x = x * 10 + (str[j++] - '0');
            }
            num.push(x);
            i = j - 1;
        } else if (ch == '(') {
            op.push(ch);
        } else if(ch == ')') {
            while (!op.empty() && op.top() != '(') eval();
            op.pop();
        } else {
            while (!op.empty() && cmp[op.top()] >= cmp[ch]) eval();
            op.push(ch);
        }
    }
    while (!op.empty()) eval();
    std::cout << num.top() << std::endl;
    return 0;
}
