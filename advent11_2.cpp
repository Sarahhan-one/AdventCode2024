#include <string>
#include <vector> 
#include <iostream>
#include <map>

using namespace std; 

int main() {
    map<long long, long long> nums;
    int tmp;
    while (scanf("%d", &tmp) != EOF) {
        nums[tmp]++;
    }
    
    for (int rep = 0; rep < 75; rep++) {
        map<long long, long long> new_nums; 
        for (auto pp : nums) {
            long long num = pp.first;
            long long cnt = pp.second;
            if (num == 0) {
                new_nums[1] += cnt;
            }
            else if (to_string(num).length() % 2 == 0) {
                string s = to_string(num);
                int len = s.length();
                new_nums[stoll(s.substr(0, len/2))] += cnt;
                new_nums[stoll(s.substr(len/2, len/2))] += cnt;
            }
            else {
                new_nums[num * 2024] += cnt;
            }
        }
        nums = new_nums;
    }

    long long ans = 0; 
    for (auto pp : nums) {
        ans += pp.second;
    }
    cout << ans << endl;
}