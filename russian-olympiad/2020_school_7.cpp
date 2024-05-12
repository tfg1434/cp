// unfinished recursive bruteforce problem

#include <bits/stdc++.h>
using namespace std;

const int n = 9;
const int m = 9;
char a[n][m];

void rec(int x, int y) {
    if (y == m) {
        y = 0;
        x++;
    }
    if (x == n) {
         ... print...
        exit(0);
    }

    for (int i = 0; i < 3; i++) {
        col[x][y] = i+1;
        bool ok = true;
        for (int x0 = 0; x0 < x; x0++) {
            for (int y0 = 0; y0 < y; y0++) {
                if (col[x0][y0] == col[x][y] && col[x0][y] == col[x][y] && col[x][y0] == col[x][y])
                    ok = false;
            }
        }

        if (ok) {
            rec(x+1, y);
        }
        col[x][y] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}


