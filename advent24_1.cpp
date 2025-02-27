#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std; 

int main() {
    map<string, int> value;
    for (int i = 0; i < 90; i++) {
        char s[7];
        scanf(" %s", s);
        int d;
        scanf(" %d", &d);
        value[string(s, s+3)] = d; 
    }

    char a[5], op[5], b[5], ig[5], c[5];
    vector<vector<string>> ops; 
    while (scanf(" %s", a) != EOF) {
        scanf(" %s %s %s %s", op, b, ig, c);
        vector<string> v {string(a), string(b), string(c), string(op)};
        ops.push_back(v);
    }
    cout << ops.size() <<endl;
    
    for (int rep = 0; rep < (int) ops.size(); rep++) {
        for (vector<string> op : ops) {
            if (value.count(op[0]) && value.count(op[1]) && !value.count(op[2])) {
                int x = value[op[0]];
                int y = value[op[1]];
                string o = op[3];
                value[op[2]] = (o == "XOR" ? x^y : ((o == "OR") ? x|y : x&y));
            }
        }
    }

    long long ans = 0;
    int i = 0;
    for (auto p : value) {
        if (p.first[0] == 'z') {
            ans += ((long long) p.second) << i;
            i++;
            // cout << p.first << " " << p.second << endl;
        }
    }
    printf("%lld", ans);
}