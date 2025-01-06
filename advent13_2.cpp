#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;

pair<long long, long long> solver (int& ax, int& ay, int& bx, int& by, long long& x, long long& y) {
    long long diff = 10000000000000;
    x += diff; y += diff;
    long long i = (y * bx - x * by) / (ay * bx - ax * by);
    long long j = (y * ax - x * ay) / (by * ax - bx * ay);
    cout << i << endl;
    if ((i*ax + j*bx == x) && (i*ay + j*by == y)) {
        return make_pair(i, j);
    }
    return {-1, -1};
}

int main() {

    long long ans = 0;
    for (string line; getline(cin, line);) {
        int ax, ay, bx, by;
        long long x, y;
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        getline(cin, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        getline(cin, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &x, &y);
        
        auto temp = solver(ax, ay, bx, by, x, y); 
        if (temp.first >= 0 && temp.second >= 0) {
            ans += temp.first * 3 + temp.second;
        }
        getline(cin, line);
    }

    cout << ans << endl;

}