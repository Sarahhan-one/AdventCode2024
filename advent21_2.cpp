#include <vector>
#include <cassert>
#include <string>
#include <iostream>
#include <cstring>
#include <set>

#define int long long

using namespace std; 

vector<vector<int>> numpad = {
    {7,8,9},
    {4,5,6},
    {1,2,3},
    {-1,0,10} //A=10;
};

int getInt (char c) {
    if (isdigit(c)) return c - '0'; 
    if (c == 'A') return 10;
    cout << c << endl;
    assert(false);
}

char getChar(int value) {
    if (0 <= value && value < 10) {
        return '0' + value;
    }
    if (value == 10) {
        return 'A';
    }
    return false;
};

const int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3, HIT = 4; 
pair<int, int> dirs[4] = {{-1,0},{0,-1},{1,0},{0,1}};
vector<vector<int>> keypad = {
    {-1, UP, HIT},
    {LEFT, DOWN, RIGHT}
};


const int INF = 1e18 + 5;
int dist[5][5][5][11];
bool vis[5][5][5][11];

const char MOVEMENT = '$';
const char ERROR = '@';

char makeMove(int mv, int& x, vector<vector<int>>& pad) {
    assert(0 <= mv && mv < 4);
    
    int H = pad.size();
    int W = pad[0].size();
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (pad[r][c] == x) {
                r += dirs[mv].first;
                c += dirs[mv].second;
                if (0 <= r && r < H && 0 <= c && c < W && pad[r][c] != -1) {
                    x = pad[r][c];
                    return MOVEMENT;
                }
                else {
                    return ERROR;
                }
            }
        }
    }
    assert(false);
}


const int M = 25; //number of robots using keypads

//dp[robot_id][from][to] .. assuming that previous robots set to 'A', then min number of moves to move this robot from -> to
//dp[0][..] = 0
int dp[M+2][11][11];

//if you want to move 3rd of 3 robots, 
//first robots should point to A and second robot should point to proper movement button
void preprocess() {

    for (int id = 1; id <= M + 1; id++) {
        const int X = (id == M + 1 ? 11 : 5); 
        for (int from = 0; from < X; from++) {
            // small[prev][me]
            vector<vector<int>> small (5, vector<int> (11, INF));
            small[HIT][from] = 0;
            set<pair<int, pair<int, int>>> pq; 
            pq.insert({0, {HIT, from}});

            auto consider = [&] (int prev, int me, int maybe) {
                if (maybe < small[prev][me]) { //then overwrite
                    pq.erase({small[prev][me], {prev, me}});
                    small[prev][me] = maybe;
                    pq.insert({maybe, {prev, me}});
                }
            };

            while (!pq.empty()) {
                int my_dist = pq.begin() -> first; 
                int prev = pq.begin() -> second.first;
                int me = pq.begin() -> second.second;
                pq.erase(pq.begin());
                for (int prev2 = 0; prev2 < 5; prev2++) {
                    int maybe = my_dist + dp[id-1][prev][prev2];
                    consider(prev2, me, maybe);
                }
                if (prev != HIT) {
                   if (MOVEMENT == makeMove(prev, me, (id == M + 1 ? numpad : keypad))) {
                    consider(prev, me, my_dist + 1);
                   } 
                }
            }

            for (int to = 0; to < (id == M + 1 ? 11 : 5); to++) {
                dp[id][from][to] = small[HIT][to];
            }
        }
    }
}

int solve(string& s) {
    char prev = 'A'; 
    int total = 0;
    for (char& c : s) {
        total += dp[M+1][getInt(prev)][getInt(c)] + 1;
        prev = c; 
    }

    return total; 
}

int32_t main() {

    preprocess();
    int ans = 0;
    for (int rep = 0; rep < 5; rep++) {
        string s;
        cin >> s;
        int x = solve(s);
        s.pop_back();
        ans += x * stoi(s);
    }
    cout << ans << endl;
}