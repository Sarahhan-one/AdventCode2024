#include <vector>
#include <iostream>
#include <string>

using namespace std;


vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0},
                              {-1,-1}, {-1,1}, {1,-1}, {1,1}};
string xmas = "XMAS";

void dfs (int r, int c, int idx, pair<int, int> dir, int& ans, const vector<string>& input) {
    if (r < 0 || c < 0 || r >= input.size() || c >= input[0].size()) {
        return;
    }
    
    char cur = input[r][c];
    char to_find = xmas[idx];
    if (cur != to_find) {
        return;
    }
    if (idx == 3 && cur == 'S') {
        ans++;
        return;
    }

    int new_r = r + dir.first;
    int new_c = c + dir.second; 
    dfs(new_r, new_c, idx+1, dir, ans, input);
}

int main() {
    vector<string> input;
    string s;
    for (int i = 0; i < 140 && getline(cin, s); i++) {
        input.push_back(s); 
    }

    int r = input.size();
    int c = input[0].size();
    int ans = 0;

    for (int i = 0; i < r; i++ ) {
        for (int j = 0; j < c; j++) {
            char cur = input[i][j];
            if (cur == 'X') {
                for (const auto& dir : directions) {
                    dfs(i, j, 0, dir, ans, input);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}