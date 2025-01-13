#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
map<string, vector<string>> edges;
set<string> vis;
set<pair<string, string>> pairs;
vector<string> big;

void rec(string a, int i, vector<string> clique) { 
    if (i == (int)edges[a].size()) {
        if (clique.size() > big.size()) {
            big = clique;
        }
        // cout << clique.size() << endl;
        return;
    }
    
    rec(a, i+1, clique); //skip the current edge to track all possibilities 

    string b = edges[a][i];
    for (string s : clique) {
        if (!pairs.count({b,s})) { //verify if the current node has all edges in current clique
            return;
        }
    }
    clique.push_back(b);
    rec(a, i+1, clique);
}



int main() {
    char s[7];
    set<string> nodes; 
     //set of edges

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

    for (string a : nodes) {
        rec(a, 0, {a});
    }

    // cout << big.size() << endl;

    sort(big.begin(), big.end()); 
    for (string s : big) {
        cout << s << ",";
    }
}