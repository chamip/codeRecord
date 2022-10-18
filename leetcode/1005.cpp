#include <iostream>
#include <vector>
using namespace std;
int findString(vector<string>& words, string s) {
    int left = 0;
    int right = words.size() - 1;
    while (left <= right) {
        if (words[left].size() == 0) {
            ++left;
            continue;
        }
        if (words[right].size() == 0) {
            --right;
            continue;
        }
        int mid = left + (right - left) / 2;
        while (words[mid].size() == 0) {
            ++mid;
            if (mid == right) {
//                  if (words[mid] == s) {
//                      return mid;
//                  }
                right = left + (right - left) / 2;
                continue;
            }
        }
        if (words[mid] == s) {
            return mid;
        } else if (words[mid] > s) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
	vector<string> words {"at", "", "", "", "dad"};
	string s = "dad";
	cout << findString(words, s) << endl;
	return 0;
}
