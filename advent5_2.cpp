#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, vector<int>> edges;

void topo(int a, vector<int>& order, map<int, int>& in, const set<int>& present) {
    order.push_back(a);
    for (int b : edges[a]) {
        if (present.count(b)) {
            if (--in[b] == 0) { 
                topo(b, order, in, present);
            }
        }
    }
}

int main() {
    string s;
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
            map<int, int> in;
            set<int> present;
            for (int x : v) {
                present.insert(x);
            }
            for (int i = 0; i < (int) v.size(); i++) {
                int x = v[i];
                for (int y : edges[x]) {
                    if (present.count(y)) {
                        ++in[y];
                    }
                    if (earlier.count(y)) {
                        ok = false;
                    }
                }
                earlier.insert(x);
            }
            if (ok) {
                // ans += v[v.size()/2];
            } else {
                vector<int> order;
                vector<int> starting;
                for (int x : v) {
                    if (in[x] == 0) {
                        starting.push_back(x);
                    }
                }
                for (int x : starting) {
                    topo(x, order, in, present);
                }
                ans += order[order.size()/2];
            }
        }
    }
    cout << ans << endl;
}                      