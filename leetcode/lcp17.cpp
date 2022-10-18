#include <iostream>
#include <vector>
#include <string>

using namespace std;
int calculate(string s) {
    int x = 1;
    int y = 0;
    for (char c : s) {
        if (x == 'A') {
            x = 2 * x + y; 
        } else {
            y = 2 * y + x;
        }
    }
    return x + y;
}

int main(int argc, char const *argv[])
{
//	int n;
//	cin >> n;
//	cout << n * n << endl << "hello, world!" << endl;
	string s = "AB";
	cout << calculate(s) << endl;
	return 0;
}
