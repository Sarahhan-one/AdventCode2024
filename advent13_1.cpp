#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


int main() {
    int ans = 0;
    string line;
    while (cin.peek() != EOF) {
        int ax, ay, bx, by;
        int x, y;
        getline(cin, line);
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        getline(cin, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        getline(cin, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &x, &y);
        
        for (int i = 0; i * ax <= x; i++) {
            int j = (x - i * ax) / bx;
            if (i * ax + j * bx == x) {
                if (i * ay + j * by == y) {
                    ans += i * 3 + j;
                }
            }
        }
        
        getline(cin, line);
    }

    cout << ans << endl;

}