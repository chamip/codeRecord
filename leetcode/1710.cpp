#include <iostream>
#include <vector>
using namespace std;

bool static cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] >= b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int n = boxTypes.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (truckSize >= boxTypes[i][0]) {
            truckSize -= boxTypes[i][0];
            res += boxTypes[i][0] * boxTypes[i][1];
        } else if (truckSize > 0 && truckSize < boxTypes[i][0]) {
            res += truckSize * boxTypes[i][1];
            truckSize = 0;
        }
        if (truckSize == 0) {
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
	int truckSize = 4;
	cout << maximumUnits(boxTypes, truckSize) << endl;
	return 0;
}
