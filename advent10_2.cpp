#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void dfs(int r, int c, int& ans, vector<vector<int>>& nums) {
    int curr = nums[r][c];
    if (curr == 9) {
        ans++;
        return;
    }

    for (auto& dir : directions) {
        int new_r = r + dir.first;
        int new_c = c + dir.second;
        if (new_r >= 0 && new_c >= 0 && new_r < nums.size() && new_c < nums[0].size()) {
            if ((curr + 1) == nums[new_r][new_c]) {
                dfs(new_r, new_c, ans, nums);
            }
        }
    }
    
    return;
}

int main() {
    vector<string> input(42);
    for (int i = 0; i < 42; i++) {
        getline(cin, input[i]);
    }

    vector<pair<int, int>> starts; 
    vector<vector<int>> nums(input.size(), vector<int> (input[0].size()));
    for (int r = 0; r < input.size(); r++) {
        for (int c = 0; c < input[0].size(); c++) {
            int curr = input[r][c] - '0';
            if (curr == 0) {
                starts.push_back({r, c});
            }
            nums[r][c] = curr;
        }
    }

    int ans = 0;
    for (auto& start : starts) {
        dfs(start.first, start.second, ans, nums);
    }

    cout << ans << endl;

}


