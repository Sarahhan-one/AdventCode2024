#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

bool vis[141][141];
char s[141][141];
vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 

bool inside(int row, int col) {
    return 0 <= row && row < 140 && 0 <= col && col < 140;
}

void dfs(int row, int col, int& area, int& per) {
    vis[row][col] = true;
    area++;

    auto good = [&] (pair<int, int> dir) {
        int r2  = row + dir.first;
        int c2 = col + dir.second;
        return inside(r2, c2) && s[r2][c2] == s[row][col];
    };

    for (int i = 0; i < 4; i++) {
        pair<int, int> dir = directions[i];
        pair<int, int> dir2 = directions[(i+1)%4];

        if (!good(dir) && !good(dir2)) {
            per++;
        }
        if (good(dir) && good(dir2) && !good(make_pair(dir.first + dir2.first, dir.second + dir2.second))) {
            per++;
        }
    }

    for (pair<int, int> dir : directions) {
        int r2 = row + dir.first;
        int c2 = col + dir.second;

        if (good(dir) && !vis[r2][c2]) {
            dfs(r2, c2, area, per);
        }
    }
}

int main() {
    for (int i = 0; i < 140; i++) {
        scanf("%s", s[i]);
    }
    
    int ans = 0;
    for (int r = 0; r < 140; r++) {
        for (int c = 0; c < 140; c++) {
            if (!vis[r][c]) {
                int area = 0, per = 0;
                dfs(r, c, area, per);
                ans += area * per;
            }
        }
    }

    cout << ans << endl;
}