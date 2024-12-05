#include <vector>
#include <iostream>
#include <string>

using namespace std;


vector<pair<int, int>> directions = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};
string xmas = "MAS";

void dfs (int r, int c, int idx, pair<int, int> dir, int& ans, const vector<string>& input, int start_r, int start_c) {
    if (r < 0 || c < 0 || r >= input.size() || c >= input[0].size()) {
        return;
    }
    
    char cur = input[r][c];
    char to_find = xmas[idx];

    if (cur != to_find) {
        return;
    }
    if (idx == 2 && cur == 'S') {
        int r1 = r;
        int c1 = start_c; 

        int r2 = start_r;
        int c2 = c;

        char char_1 = input[r1][c1];
        char char_2 = input[r2][c2];

        if ((char_1 == 'S' || char_2 == 'S') && (char_1 == 'M' || char_2 == 'M')) {
            ans++;
            return;
        }
        
    }

    int new_r = r + dir.first;
    int new_c = c + dir.second; 
    dfs(new_r, new_c, idx+1, dir, ans, input, start_r, start_c);
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
            if (cur == 'M') {
                for (const auto& dir : directions) {
                    dfs(i, j, 0, dir, ans, input, i, j);
                }
            }
        }
    }

    cout << ans/2 << endl;
    return 0;
}