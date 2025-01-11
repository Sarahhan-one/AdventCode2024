#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    char s[7];
    set<string> nodes; 
    map<string, vector<string>> edges; //adjacency list 
    set<pair<string, string>> pairs; //set of edges

    while (scanf("%s", s) != EOF) {
        string a(s, s+2);
        string b(s+3, s+5);

        nodes.insert(a);
        nodes.insert(b);
        edges[a].push_back(b);
        edges[b].push_back(a);
        pairs.insert({a, b});
        pairs.insert({b, a});
    }

    int ans = 0;
    for (string a : nodes) {
        for (string b : edges[a]) {
            for (string c : edges[b]) {
                if (pairs.count({a, c})) {
                    if (a[0] == 't' || b[0] == 't' || c[0] == 't') {
                        ans++;
                    }
                }
            }
        }
    }
    // (a,b,c) (3*2*1)
    assert(ans % 6 == 0);
    printf("%d\n", ans/6);
}