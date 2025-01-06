#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<pair<int, int>> pos, vel;
    const int W = 101;
    const int H = 103;
    int px, py, vx, vy;
    while (scanf(" p=%d,%d v=%d,%d", &px, &py, &vx, &vy) != EOF) {
        pos.emplace_back(px, py);
        vel.emplace_back(vx, vy);
    }

    int turn = 0;
    while (true) {
        turn++;
        vector<string> a(H, string(W, ' '));
        for (int i = 0; i < (int) pos.size(); i++) {
            int &x = pos[i].first;
            int &y = pos[i].second;
            x += vel[i].first;
            x = ((x % W) + W) % W;
            y += vel[i].second;
            y = ((y % H) + H) % H;
            a[y][x] = 'X';
        }

        int cnt = 0; 
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j < W-1-j && a[i][j] == 'X' && a[i][W-1-j] == 'X') {
                    cnt++;
                }
            }
        }

        if (cnt >= 40) {
            cout << turn << endl;

            for (const string& s : a) {
                printf("%s\n ", s.c_str());
            }
            puts("");
            fflush(stdout);
        }
    }
}