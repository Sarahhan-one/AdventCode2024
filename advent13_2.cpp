#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <cassert>

using namespace std;


int main() {
    long long ans = 0;
    string line;
    while (cin.peek() != EOF) {
        int ax, ay, bx, by;
        int px, py;
        getline(cin, line);
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        getline(cin, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        getline(cin, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &px, &py);
        
        long long x = px + 10000000000000LL;
        long long y = py + 10000000000000LL;

        // i * ax + j*bx = x 
        // i = (x - j*bx) / ax
        // i*ay + j*by = y
        // ((x - j*bx) / ax)*ay + j*by = y 
        // (x - j*bx)*ay + j*by*ax = y*ax
        // x*ay - j*bx*ay + j*by*ax = y*ax
        // j* (by*ax - bx*ay) = y*ax - x*ay

        // j = (A X p) / (A X B);
        // i = (B X p) / (B X A);
        

        long long i, j;
        j = (y*ax - x*ay) / (by*ax - bx*ay);
        i = (y*bx - x*by) / (ay*bx - ax*by);

        
        if (i * ax + j * bx == x) {
            if (i * ay + j * by == y) {
                ans += i * 3 + j;
            }
        }
        
        getline(cin, line);
    }

    printf("%lld", ans);

}