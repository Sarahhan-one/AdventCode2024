#include <stdio.h>
#include <iostream>
#include <vector> 
#include <math.h>
using namespace std;

bool isOK(vector<int> a) { 
    int k = (int) a.size();
    bool ok = true;
    bool only_inc = true;
    bool only_dec = true;
    for (int j=0; j<k-1; j++) {
        int diff = a[j+1] - a[j];
        if (diff > 0) {
            only_dec = false;
        }
        if (diff < 0) {
            only_inc = false;
        }
        if (!(1 <= abs(diff) && abs(diff) <= 3)) {
            ok = false;
            break;
        }
    }
    return ok && (only_inc || only_dec);
}

int main() {
    vector<int> a;
    int answer = 0; 
    int T = 1000;
    while (T--) {
        a.clear();
        
        while (true) {
            int x;
            if (scanf("%d", &x) != 1) {
                break;
            };
            a.push_back(x);
            char c; 
            scanf("%c", &c);
            if (c == '\n') {
                break;
            }
        }
            
        bool anyOK = false; 
        auto consider = [&] (int i) {
            vector<int> b = a; 
            b.erase(b.begin() + i);
            if (isOK(b)) {
                anyOK = true; 
            }
        };

        int k = a.size();
        consider(0);
        for (int i=0; i < k-1; i++) {
            int diff = a[i+1] - a[i];
            if (abs(diff) <1 || abs(diff) > 3) {
                consider(i);
                consider(i+1);
                break;
            }
            if (i+2 < k) {            
                int diff2 = a[i+2] - a[i+1];
                if ((diff > 0) != (diff2 > 0)) {
                    consider(i);
                    consider(i+1);
                    consider(i+2);
                    break; 
                }
            }
        }
        if (anyOK) {
            answer++;
        }
    }
    printf("%d\n", answer);
}