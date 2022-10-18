#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
	cin >> a >> b >> c >> d;
    int total = a + b + c + d;
    int mi = min({a, b, c, d});
    int ma = max({a, b, c, d});
    cout << abs((mi + ma) - (total - mi - ma)) << endl;
    return 0;
}
