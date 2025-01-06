#include <string>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <limits.h>
#include <cassert>


using namespace std; 
char a[505][505];

vector<pair<int, int>> dirs = {{0,1},{-1,0},{0,-1},{1,0}};

struct State { 
    int row, col, dir;
    bool operator < (const State& he) const {
        return make_pair(row, make_pair(col, dir)) < make_pair(he.row, make_pair(he.col, he.dir));
    }
};

int main() {
    int H, W;
    pair<int, int> start, end;
    for (int row = 0; scanf("%s", a[row]) != EOF; row++) {
        H = row + 1; 
        W = strlen(a[row]); 
        for (int col = 0; col < W; col++) {
            if (a[row][col] == 'S') {
                a[row][col] = '.'; 
                start = {row, col};
            }
            if (a[row][col] == 'E') {
                a[row][col] = '.'; 
                end = {row, col};
            }
        }
    } 

    set<pair<int, State>> s; //priority queue (cost, state)
    map<State, int> dist; //min cost at each state 
    State starting_state{start.first, start.second, 0};
    dist[starting_state] = 0; 
    s.insert(make_pair(0, starting_state)); 

    int ans = INT_MAX;

    while (!s.empty()) {
        State state = s.begin() -> second;
        s.erase(s.begin());
        for (int i = 0; i < 3; i++) {
            int maybe = dist[state]; //current cost to reach this state 
            State s2 = state; //new state after move 
            if (i == 0) {
                s2.row += dirs[s2.dir].first;
                s2.col += dirs[s2.dir].second;
                if (a[s2.row][s2.col] == '#') {
                    continue;
                }
                if (!(0 <= s2.row && s2.row < H && 0 <= s2.col && s2.col < W)) {
                    assert(false);
                }
                maybe++;
            }
            else if (i == 1) {
                s2.dir = (s2.dir + 1) % 4; 
                maybe += 1000; 
            }   
            else {
                s2.dir = (s2.dir + 3) % 4;
                maybe += 1000; 
            }
            //if new state is better than this state, update it
            if (!dist.count(s2) || dist[s2] > maybe) {
                if (dist.count(s2)) {
                    s.erase(make_pair(dist[s2], s2));
                }
                dist[s2] = maybe;
                s.insert(make_pair(maybe, s2));
            }
        }
         
        for (int i = 0; i < 4; i++) {
            State e{end.first, end.second, i};
            if (dist.count(e)) {
                ans = min(ans, dist[e]);
            }
        }
    }
    printf("%d\n", ans);
}