#include <iostream>
#include <vector>
using namespace std;
int minTimeToType(string word) {
    int sec = 0;
    int n = word.size();
    char cur = 'a';
    for (int i = 0; i < n; ++i) {
        int step = min({abs(word[i] - cur), ('z' - cur) + (word[i] - 'a') + 1, ('z' - word[i]) + (cur - 'a') + 1});
        sec += step + 1;
        cur = word[i];
    }
    return sec;
}

int main(int argc, char const *argv[])
{
	string word = "bza";
	cout << minTimeToType(word) << endl;
	return 0;
}
