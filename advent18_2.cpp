#include <string>
#include <cassert>
#include <vector>

using namespace std; 

const int INF = 1e9 + 5; 
const int S = 71; 

//finding the most important coordinate that if blocked, would cut off access to the exit

int main() {
    vector<pair<int, int>> in;
    const int N = 3450;
    vector<vector<int>> id (S, vector<int>(S, N+1)); //small number is more important as a potential blocker
    vector<vector<int>> dist (S, vector<int>(S, 0)); //highest numbered coordinate we can avoid while reaching the end

    for (int i = 0; i < N; i++) {
        int x, y; 
        scanf(" %d,%d", &x, &y);
        in.emplace_back(x, y);
        id[x][y] = i + 1; 
    }

    vector<pair<int, int>> inv[N+3]; //inverse 
    dist[0][0] = id[0][0];
    inv[dist[0][0]].emplace_back(0,0);

    for (int v = N+1; v >= 0; v--) {
        for (int z = 0; z < (int) inv[v].size(); z++) {
            pair<int, int> me = inv[v][z];
            int r = me.first;
            int c = me.second; 

            for (pair<int, int> dir : vector<pair<int, int>>{{-1,0},{1,0},{0,1},{0,-1}}) {//neighbors
                int r2 = r + dir.first;
                int c2 = c + dir.second; 
                if (0 <= min(r2, c2) && max(r2, c2) < S) {
                    int x = min(v, id[r2][c2]);
                    if (x > dist[r2][c2]) {//if improved
                        dist[r2][c2] = x;
                        inv[x].emplace_back(r2, c2); 
                    }
                }
            }
        }
    }
    int value = dist[S-1][S-1] - 1;
    printf("%d,%d\n", in[value].first, in[value].second);
}