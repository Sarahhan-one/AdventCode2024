#include <vector>
#include <string>
#include <iostream> 
#include <sstream>

using namespace std;

bool dfs(long long total, int idx, bool add, long long goal, vector<long long>& nums) {
    long long curr = nums[idx];
    if (add) {
        total += curr; 
    } else {
        total *= curr;
    }

    if (idx == nums.size() - 1) {
        return total == goal; 
    }

    return dfs(total, idx+1, true, goal, nums) || dfs(total, idx+1, false, goal, nums);
}

int main() {
    vector<string> inputs(850);
    long long ans = 0;
    for (int i = 0; i < 850; i++) {
        getline(cin, inputs[i]);
    }

    for (string& input : inputs) {
        int i = 0, idx = 0;
        while (i < input.size()) {
            if (input[i] == ':') {
                idx = i;
                break; 
            }
            i++;
        }

        long long goal = stoll(input.substr(0, idx)); 
        string rest_string = input.substr(idx+1); 
        stringstream rest(rest_string);
        vector<long long> nums; 

        string temp;
        while (rest >> temp) {
            long long num = stoll(temp);
            nums.push_back(num);
        }

        bool isgood = dfs(nums[0], 1, true, goal, nums) || dfs(nums[0], 1, false, goal, nums); 
        if (isgood) {
            // cout << goal << endl;
            ans += goal; 
        }
    }
    cout << ans << endl;
}