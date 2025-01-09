#include <string>
#include <string.h>
#include <vector> 
#include <iostream>


using namespace std; 

int main() {
    vector<string> pats; 

    char s[105];
    while (true) {
        scanf("%s, ", s); 
        char c; 
        scanf("%c", &c);
        if (c != ' ') {
            pats.push_back(string(s));
            break;
        }
        pats.push_back(string(s)); 
        if (pats.back().back() == ',') {
            pats.back().pop_back(); 
        }
        // cout << pats.back() << endl;
    }

    int ans = 0;
    while (scanf("%s", s) != EOF) {
        int L = strlen(s);
        vector<bool> dp(L+1, false); 
        dp[0] = true;
        
        for (int i = 0; i < L; i++) {
            if (dp[i]) {
                for (const string& p : pats) {
                    int k = p.length();
                    if (i + k <= L) {
                        bool ok = true; 
                        for (int j = 0; j < k; j++) {
                            if (s[i+j] != p[j]) {
                                ok = false; 
                                break;
                            }
                        }
                        if (ok) {
                            dp[i+k] = true;
                        }
                    }
                }
            }
        }
        if (dp[L]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    
}