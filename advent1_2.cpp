#include <vector>
#include <iostream>
#include <map>

using namespace std; 

int main() {
    vector<int> a, b;
    for (int i=0; i < 1000; i++) {
        int x, y;
        cin >> x >> y; 
        a.push_back(x);
        b.push_back(y);
    }

    map<int, int> freq; 
    for (int x : b) {
        freq[x]++;
    }


    long long sum = 0;
    for (int x : a) {
        sum += (long long) x * freq[x];
    } 
    cout << sum << "\n";
}