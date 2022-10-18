#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int dangerous;
	int dead;
	cin >> dangerous >> dead;
	double res = double(dead) / dangerous * 100.0;
	cout.setf(cout.showpoint);
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << res << "%" << endl;
	//	cout << fixed << setprecision(3) << res << "%" << endl;
	return 0;
}
