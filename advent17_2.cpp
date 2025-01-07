#include <string.h>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

long long A, B, C; 
vector<pair<int, int>> v; 

long long combo (int x) {
    if (x <= 3) {
        return x; 
    }
    if (x == 4) return A; 
    if (x == 5) return B; 
    if (x == 6) return C;
    assert(false);
}

int i = 0; //instruction ptr 

void adv (int x) {//0
    A >>= combo(x); 
}

void bxl (int x) {//1
    B ^= x; 
}

void bst (int x) {//2
    B = combo(x) % 8; 
}

void jnz (int x) {//3
    if (A == 0) {
        return;
    }
    i = x; 
    i--; 
}

void bxc (int x) {//4
    B ^= C; 
}

vector<int> myOut;
void out (int x) {//5
    myOut.push_back(combo(x) % 8);
    // printf("%d,", combo(x) % 8);
}

void bdv (int x) {//6
    B = A>>combo(x);
}

void cdv (int x) {//7
    C = A>>combo(x);
}

vector<int> simulate (long long _A) {
    A = _A; 
    i = 0; 
    myOut.clear();
    while (0 <= i && i < (int) v.size()) {
        int a = v[i].first;
        int x = v[i].second;
        switch(a) {
            case 0: adv(x); break;
            case 1: bxl(x); break;
            case 2: bst(x); break;
            case 3: jnz(x); break;
            case 4: bxc(x); break;
            case 5: out(x); break;
            case 6: bdv(x); break;
            case 7: cdv(x); break;
        }
        i++;
    }
    return myOut;
}

int main() {
    char s[105]; 
    scanf(" %s", s);
    scanf(" %s", s);
    scanf(" %lld", &A);
    for (int i = 0; i < 7; i++) {
        scanf(" %s", s);
    }

    int x, y;
    while (scanf(" %d,%d", &x, &y) != EOF) {
        scanf(",");
        v.emplace_back(x, y);
        // printf("%d %d\n", x, y);
    }

    vector<int> targets; 
    for (pair<int, int> p : v) {
        targets.push_back(p.first);
        targets.push_back(p.second);
    }

    vector<long long> cands;
    for (int i = 0; i < 1024; i++) {
        cands.push_back(i);
    }

    long long pw = 1024; 
    for (int k = 0; k < (int) targets.size(); k++) {
        vector<long long> new_cands; 
        //test each candidate value for A 
        for (long long _A : cands) {
            vector<int> out = simulate(_A); 
            //check if output matches up to position k in target
            bool ok = (out[0] == targets[0]); 
            for (int j = 0; j <= k; j++) {
                if (j >= (int) out.size() || out[j] != targets[j]) {
                    ok = false;
                    break;
                }
            }
            //if it matches, generate new candidates by adding multiples of pw
            if (ok) {
                for (int j = 0; j < 8; j++) {
                    new_cands.push_back(_A + j * pw); 
                }
            } 
        }
        cands = new_cands;
        sort(cands.begin(), cands.end());
        printf("%d %lld\n", (int)cands.size(), cands[0]);
        pw *= 8;
    }

    // for (long long _A : cands) {
    //     if (simulate(_A).size() == targets.size()) {
    //         printf("%lld\n", _A);
    //     }
    // }

    // int cnt = 0;
    // for (long long _A = 0; _A < 1024; _A++) {
    //     vector<int> out = simulate(_A);
    //     vector<int> out2 = simulate(_A + 1024);
    //     assert(out[0] == out2[0]);
    //     if (out[0] == targets[0]) {
    //         cnt++;
    //     }
    //     for (int x : out) {
    //         printf("%d,", x);
    //     }
    //     puts("");
    //     printf("%d", cnt);
    // }

}   