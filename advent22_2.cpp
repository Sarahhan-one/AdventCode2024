#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std; 

const int MOD = 1 << 24;
void f(long long& x) {
    x ^= x * 64;
    x %= MOD;
    x ^= x / 32; 
    x %= MOD;
    x ^= x *2048LL;
    x %= MOD; 
}

map<vector<int>, int> m; 

int main() {
    long long x;
    while (scanf("%lld", &x) != EOF) {
        vector<int> v; 
        set<vector<int>> s;
        for (int i = 0; i < 2000; i++) {
            f(x);
            v.push_back(x % 10);
            if (i >= 4) {
                vector<int> d;
                for (int j = 0; j < 4; j++) {
                    d.push_back(v[i-4+1+j] - v[i-4+j]);
                }
                if (!s.count(d)) {
                    s.insert(d);
                    m[d] += x % 10;
                }
            }
        }
    }
    int ans = 0;
    for (auto p : m) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
}