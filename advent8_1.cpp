#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std; 

int main() {
    long long ans = 0;

    vector<string> inputs(50);
    for (int i = 0; i < 50; i++) {
        getline(cin, inputs[i]);
    }

    unordered_map<char, vector<pair<int, int>>> m; 
    for (int row = 0; row < inputs.size(); row++) {
        for (int col = 0; col < inputs[0].size(); col++) {
            char curr = inputs[row][col];
            if (curr != '.') {
                m[curr].push_back({row, col});
            }
        }
    }

    // for (const auto& x: m) {
    //     cout << x.first << endl;
    //     for (const auto& p : x.second) {
    //         cout << p.first << " " << p.second << endl;
    //     }
    // }

    for (const auto& x : m) {
        const auto& pos = x.second;
        for (int i = 0; i < pos.size(); i++) {
            for (int j = 0; j < pos.size(); j++) {
                if (i == j) {
                    continue;
                }
                pair<int, int> p1 = pos[i];
                pair<int, int> p2 = pos[j];
                int r_diff = p2.first - p1.first;
                int c_diff = p2.second - p1.second;
                int new_r = p2.first + r_diff;
                int new_c = p2.second + c_diff;

                if (new_r >= 0 && new_c >= 0 && new_r < inputs.size() && new_c < inputs[0].size()) {
                    inputs[new_r][new_c] = '#'; 
                }
            }
        }
    }

    for (int row = 0; row < inputs.size(); row++) {
        for (int col = 0; col < inputs[0].size(); col++) {
            char curr = inputs[row][col]; 
            if (curr == '#') {
                ans++;
            }
        } 
    }

    cout << ans <<endl;
}