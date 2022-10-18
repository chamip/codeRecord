#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;			
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

void solve(int p1, int p2, int p3, string& str) {
	for (int i = 0; i < str.size();) {
		if (str[i] == '-' && i > 0 && i < str.size() - 1) {
			if ((islower(str[i - 1]) && islower(str[i + 1])) || (isdigit(str[i - 1]) && isdigit(str[i + 1]))) {
				if (str[i - 1] < str[i + 1]) {
					int left = i - 1;
					int right = i + 1;
					if (str[i - 1] + 1 == str[i + 1]) {
						str = str.substr(0, left + 1) + str.substr(right, str.size() - right);
					} else {
						string temp;
						if (p1 == 1) {
							if (isalpha(str[i - 1]) || isdigit(str[i - 1])) {
								for (char ch = str[i - 1] + 1; ch != str[i + 1]; ++ch) {
									for (int j = 0; j < p2; ++j) {
										temp += ch;
									}
								}		
							}
						} else if (p1 == 2) {
							if (isalpha(str[i - 1])) {
								for (char ch = str[i - 1] + 1; ch != str[i + 1]; ++ch) {
									for (int j = 0; j < p2; ++j) {
										temp += toupper(ch);
									}
								}	
							} else if (isdigit(str[i - 1])) {
								for (char ch = str[i - 1] + 1; ch != str[i + 1]; ++ch) {
									for (int j = 0; j < p2; ++j) {
										temp += ch;
									}
								}	
							}
						} else if (p1 == 3) {
							for (char ch = str[i - 1] + 1; ch != str[i + 1]; ++ch) {
								for (int j = 0; j < p2; ++j) {
									temp += '*';
								}
							}
						}
						if (p3 == 2) {
							reverse(temp.begin(), temp.end());
						}
						int size = temp.size();
						str = str.substr(0, left + 1) + temp + str.substr(right, str.size() - right);
						i = left + size + 2;  
					}
				} else {
					++i;
				}
			} else {
				++i;
			}
		} else {
			++i;
		}
	}
	return ;
}

int main(void)
{
 	// #ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    int p1, p2, p3;
    string str;
    scanf("%d %d %d", &p1, &p2, &p3);
    cin >> str;
    solve(p1, p2, p3, str);
    cout << str << endl;
    cin.get();
    cin.get();
    return 0;
}