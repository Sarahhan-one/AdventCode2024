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

        pats.push_back(string(s)); 
        if (pats.back().back() == ',') {
            pats.back().pop_back(); 
        }

        if (c != ' ') {
            break;
        }
    }

    long long ans = 0;
    while (scanf("%s", s) != EOF) {
        int L = strlen(s);
        vector<long long> dp(L+1, 0); 
        dp[0] = 1;
        
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
                            dp[i+k] += dp[i];
                        }
                    }
                }
            }
        }
        if (dp[L]) {
            ans += dp[L];
        }
    }
    printf("%lld\n", ans);
    
}