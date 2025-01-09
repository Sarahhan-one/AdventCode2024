#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
// #include <algorithm>


using namespace std; 

const int NAX = 142;
char a[NAX][NAX];
int H,W;
const int INF = 1e9 + 5;

bool inside (int row, int col) {
    return 0 <= min(row, col) && row < H && col < W;
}

vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

vector<vector<int>> bfs(pair<int, int> start) {
    vector<vector<int>> dist(H, vector<int>(W, INF));
    dist[start.first][start.second] = 0;
    vector<pair<int, int>> q; 
    q.push_back(start);

    for (int z = 0; z < (int) q.size(); z++) {
        int r = q[z].first;
        int c = q[z].second;
        if (a[r][c] == '#') {
            continue;
        }
        for (pair<int, int> dir : dirs) {
            int r2 = r + dir.first;
            int c2 = c + dir.second;
            if (inside(r2, c2) && dist[r2][c2] == INF) {
                dist[r2][c2] = dist[r][c] + 1;
                q.emplace_back(r2, c2);
            }
        }
    }
    return dist;
}

int main() {
    for (int row = 0; scanf("%s", a[row]) != EOF; row++) {
        H = row + 1;
        W = strlen(a[row]);
    }

    pair<int, int> start, end;
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (a[row][col] == 'S') {
                start = {row, col};
                a[row][col] = '.';
            }
            if (a[row][col] == 'E') {
                end = {row, col};
                a[row][col] = '.';
            }
        }
    }

    vector<vector<int>> A = bfs(start), B = bfs(end);
    int ans = 0;
    int normal = A[end.first][end.second];
    map<int, int> freq; 

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (a[r][c] != '.') {
                continue;
            }
            const int T = 20; 
            for (int r2 = max(0, r-T); r2 <= min(H-1, r+T); r2++) {
                for (int c2 = max(0, c-T); c2 <= min(W-1, c+T); c2++) {
                    if (abs(r-r2) + abs(c-c2) <= T) {
                        if (inside(r2, c2) && a[r2][c2] != '#') {
                            int here = A[r][c] + B[r2][c2] + abs(r-r2) + abs(c-c2);
                            // ++freq[normal-here];

                            if (here <= normal - 100) {
                                ans++;
                            }

                        }
                    }
                }
            }
        }
    }

    // for (pair<int, int> f : freq) {
    //     printf("%d: %d\n", f.first, f.second);
    // }

    // cout << normal << endl;
    printf("%d\n", ans);
}