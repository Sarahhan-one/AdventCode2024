#include <vector>
#include <string>
#include <iostream>

using namespace std; 

int main() {
    string input;
    cin >> input;

    vector<int> nums; 
    vector<pair<int, int>> free_blocks;
    vector<pair<int, int>> used_blocks; 
    int id = 0;
    for (int i = 0; i < input.size(); i++) {
        int curr = input[i] - '0';
        if (i % 2 == 0) {
            used_blocks.push_back({nums.size(), curr});
            for (int j = 0; j < curr; j++) {
                nums.push_back(id); 
            }
            id++; 
        }
        else {
            free_blocks.push_back({nums.size(), curr});
            for(int j = 0; j < curr; j++) {
                nums.push_back(-1);
            }
        }
    }

    for (int i = used_blocks.size() - 1; i >= 0; i--) {
        pair<int, int> block = used_blocks[i];
        int used_idx = block.first;
        int used_len = block.second;

        for (int j = 0; j < free_blocks.size(); j++) {
            pair<int, int> space = free_blocks[j];
            int free_idx = space.first;
            int free_len = space.second;

            if (free_len + free_idx > used_idx) {
                break;
            }

            if (free_len >= used_len) {
                for (int k = free_idx; k < free_idx+ used_len; k++) {
                    nums[k] = nums[used_idx]; 
                }
                for (int k = used_idx; k < used_idx + used_len; k++) {
                    nums[k] = -1; 
                }

                free_blocks = {}; 
                int x = 0;
                while (x < nums.size()) {
                    if (nums[x] == -1) {
                        int start = x;
                        int cnt = 0;

                        while (x < nums.size() && (nums[x] == -1)) {
                        cnt++;
                        x++;
                        }  
                        free_blocks.push_back({start, cnt});
                    } else {
                        x++;
                    }

                }
                break;
            }

        }
    }
    
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != -1) {
            ans += (i * nums[i]);
        }
    }

    cout << ans << endl;
}







