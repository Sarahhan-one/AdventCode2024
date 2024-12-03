#include <iostream> 
#include <stdio.h>

using namespace std; 

int main() {
    string s; 
    char c;
    while(scanf("%c", &c) != EOF) {
        s += c;
    }
    int n = (int) s.length();

    auto getNumber = [&] (int& i) {
        int x = 0;
        while (isdigit(s[i])) {
            x = 10 * x + (s[i] - '0');
            i++;
        }
        return x; 
    };

    bool enable = true; 

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 4) == "do()") {
            enable = true;
        }
        if (s.substr(i, 7) == "don\'t()") {
            enable = false;
        }
        if (enable && s[i] == 'm') {
            if (s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
                i += 4;
                int x = getNumber(i);
                if (s[i] == ',') {
                    i += 1;
                    int y = getNumber(i);
                    if (s[i] == ')') {
                        answer += x * y;
                    }
                }
            }
        }
    }
    printf("%d\n", answer);
}