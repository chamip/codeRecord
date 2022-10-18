#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> PAIR;

vector<int> frequencySort(vector<int>& nums) {
	unordered_map<int, int> mp;
	for (const auto& x : nums) {
		++mp[x];
	}
	vector<PAIR> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second < b.second;
	});
	vector<int> res;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].second; ++j) {
			res.push_back(v[i].first);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {1,1,2,2,2,3};
	vector<int> res = frequencySort(nums);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
