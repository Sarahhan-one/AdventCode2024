#include <string>
#include <vector> 
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std; 

int main() {
    vector<long long> nums; 
    int tmp;
    while (scanf("%d", &tmp) != EOF) {
        nums.push_back(tmp);
    }
    
    for (int rep = 0; rep < 25; rep++) {
        vector<long long> new_nums; 
        for (long long num : nums) {
            if (num == 0) {
                new_nums.push_back(1);
            }
            else if (to_string(num).length() % 2 == 0) {
                string s = to_string(num);
                int len = s.length();
                new_nums.push_back(stoll(s.substr(0, len/2)));
                new_nums.push_back(stoll(s.substr(len/2, len/2)));
            }
            else {
                new_nums.push_back(num * 2024);
            }
        }
        nums = new_nums;
    }

    cout << nums.size() << endl;
}