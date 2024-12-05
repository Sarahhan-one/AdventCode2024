#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    string s;
    map<int, vector<int>> edges;
    int ans = 0;
    while (getline(cin, s)) {
        if (s.empty()) {
            continue;
        }
        int len = (int) s.length();
        vector<int> v;
        bool was_pipe = false;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                int x = 0; 
                while (isdigit(s[i])) {
                    x = 10 * x + (s[i] - '0');
                    i++;
                }
                v.push_back(x);   
                if (s[i] == '|') {
                    was_pipe = true;
                }                       
            }
        }

        if (was_pipe) {
            edges[v[0]].push_back(v[1]);
        } else {
            set<int> earlier;
            bool ok = true;
            for (int i = 0; i < (int) v.size(); i++) {
                int x = v[i];
                for (int y : edges[x]) {
                    if (earlier.count(y)) {
                        ok = false;
                    }
                }
                earlier.insert(x);
            }
            if (ok) {
                ans += v[v.size()/2];
            }
        }
    }
    cout << ans << endl;
}                      