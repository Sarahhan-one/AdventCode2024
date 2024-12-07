#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std; 

vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0, -1}};

int main() {
    int H = 130;
    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    } 
    int W = a[0].length();

    pair<int, int> start_me{-1, -1};
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (a[row][col] == '^') {
                start_me = {row, col};
                a[row][col] = '.';
            }
        }
    }
    
    auto solveCycle = [&] () {
        pair<int, int> me = start_me;
        int dir = 0;

        set<pair<pair<int,int>, int>> vis;
        while (true) {

            if (vis.count({me, dir})) {
                return true;
            }
            vis.insert({me, dir});
            int r2 = me.first + dirs[dir].first;
            int c2 = me.second + dirs[dir].second;
            if (0 > r2 || 0 > c2 || H <= r2 || W <= c2) {
                return false;
            }
            if (a[r2][c2] == '.') {
                me = {r2, c2};
            }else {
                dir = (dir + 1) % 4;
            }
        }
    };



    int ans = 0;
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (a[row][col] == '.' && start_me != make_pair(row, col)) {
                a[row][col] = '#';
                if (solveCycle()) {
                    cout << row << " " << col <<endl;
                    ans++;
                }
                a[row][col] = '.';
            }
        }
    }
    cout << ans << endl;
}