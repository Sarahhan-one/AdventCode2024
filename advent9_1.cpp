#include <vector>
#include <string>
#include <iostream>

using namespace std; 

int main() {
    string input;
    cin >> input;

    vector<int> nums; 
    int id = 0;
    for (int i = 0; i < input.size(); i++) {
        int curr = input[i] - '0';
        if (i % 2 == 0) {
            for (int j = 0; j < curr; j++) {
                nums.push_back(id); 
            }
            id++; 
        }
        else {
            for(int j = 0; j < curr; j++) {
                nums.push_back(-1);
            }
        }
    }

    int l = 0, r = nums.size() - 1;
    while (l < r) {
        while (l < nums.size() && (nums[l] != -1)) {
            l++;
        }
        while (r >= 0 && (nums[r] == -1)) {
            r--;
        }

        if (l < r) {
            nums[l] = nums[r];
            nums[r] = -1; 
            l++;
            r--; 
        }
    }

    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            break;
        }
        else {
            ans += (i * nums[i]);

        }
    }

    cout << ans << endl;

}