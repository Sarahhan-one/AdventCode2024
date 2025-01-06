#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

pair<int, int> solver (int ax, int ay, int bx, int by, int x, int y) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int ix = i * ax + j * bx;
            int iy = i * ay + j * by; 
            if (ix == x && iy == y) {
                return make_pair(i, j);
            }
        }
    }
    return {-1, -1};
}

int main() {

    int ans = 0;
    for (string line; getline(cin, line);) {
        int ax, ay, bx, by, x, y;
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