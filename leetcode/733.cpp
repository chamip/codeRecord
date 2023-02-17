#include <iostream>
#include <vector>
using namespace std;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

class Solution {
private:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int tag) {
        int m = (int)image.size(), n = (int)image[0].size();
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != tag) return ;
        image[sr][sc] = color;
        //up
        dfs(image, sr - 1, sc, color, tag);
        //down
        dfs(image, sr + 1, sc, color, tag);
        //left
        dfs(image, sr, sc - 1, color, tag);
        //right
        dfs(image, sr, sc + 1, color, tag);
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = (int)image.size(), n = (int)image[0].size();
        int tag = image[sr][sc];
        if (tag != color) dfs(image, sr, sc, color, tag);
        return image;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fileIO();
    int m, n;
    cin >> m >> n;
    vector<vector<int>> image(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;
    Solution *s = new Solution();
    vector<vector<int>> res = s->floodFill(image, sr, sc, color);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}

/*
case:
3 3
1 1 1
1 1 0
1 0 1
1 1 2
expect:
2 2 2 
2 2 0 
2 0 1 
*/
