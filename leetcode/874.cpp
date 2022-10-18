#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int dirx[] = {0, 1, 0, -1};
    int diry[] = {1, 0, -1, 0};
    int curx = 0;
    int cury = 0;
    int cur = 0;
    set<pair<int, int>> obstaclesSet;
    for (int i = 0; i < obstacles.size(); ++i) {
        obstaclesSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
    }
    int len = commands.size();
    int res = 0;
    for (int i = 0; i < len; ++i) {
        if (commands[i] == -1) {
            cur = (cur + 1) % 4;
        } else if (commands[i] == -2) {
            cur = (cur + 3) % 4;
        } else {
            for (int j = 0; j < commands[i]; ++j) {
                int x = curx + dirx[cur];
                int y = cury + diry[cur];
                if (obstaclesSet.find(make_pair(x, y)) == obstaclesSet.end()) {
                    curx = x;
                    cury = y;
                    res = max(res, curx * curx + cury * cury);
                } else {
                    break;
                }
            } 
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
//	int n;
//	cin >> n;
//	cout << n * n << endl << "hello, world!" << endl;
	vector<int> commands = {4, -1, 3};
	vector<vector<int>> obstacles = {};
	int res = robotSim(commands, obstacles);
	cout << res << endl;
	return 0;
}
