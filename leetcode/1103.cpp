#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people, 0);
    int i = 0;
    int t = 1;
    while (candies > 0) {
        if (candies >= t) {
            res[i] += t;
            candies -= t;
        } else {
            res[i] += candies;
//            candies = 0;
			break;
        }
        ++i;
		++t;
        if (i == num_people) {
            i = 0;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
//	int n;
//	cin >> n;
//	cout << n * n << endl << "hello, world!" << endl;
	int candies = 10;
	int num_people = 3;
	vector<int> res = distributeCandies(candies, num_people);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
