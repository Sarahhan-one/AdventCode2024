#include <string>
#include <vector>

using namespace std;

int K[7][7][7][7][7];

void prefSums() {
    //2D prefix sums 
    //Sum over subsets
    for (int w = 0; w < 5; w++) {
        for (int a = 0; a < 6; a++) {
            for (int b = 0; b < 6; b++) {
                for (int c = 0; c < 6; c++) {
                    for (int d = 0; d < 6; d++) {
                        for (int e = 0; e < 6; e++) {
                            K[a+(w==0)][b+(w==1)][c+(w==2)][d+(w==3)][e+(w==4)] += K[a][b][c][d][e];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> L;
    char s[10];
    while (scanf("%s", s) != EOF) {
        vector<string> grid;
        grid.push_back(s);
        for (int i = 0; i < 6; i++) {
            scanf(" %s", s);
            grid.push_back(string(s));
        }
        vector<int> v;
        for (int col = 0; col < 5; col++) {
            int cnt = 0;
            for (int row = 0; row < 7; row++) {
                if (grid[row][col] == '#') {
                    cnt++;
                }
            }
            v.push_back(cnt - 1); 
            // (0, 5, 3, 4, 3)
        }
        
        if (grid[0][0] == '#') {
            L.push_back(v);
        } 
        else {
            K[v[0]][v[1]][v[2]][v[3]][v[4]]++;
        }
    }

    prefSums(); 
    int ans = 0; 
    for (vector<int> v : L) {
        ans += K[5-v[0]][5-v[1]][5-v[2]][5-v[3]][5-v[4]];
    }
    printf("%d\n", ans);
}