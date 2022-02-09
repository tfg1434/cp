/*
ID: toronto4
TASK: ttwo
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int line_len = 10;
constexpr int obs = 1;
constexpr int empty = 0;
constexpr int max_min = 160'000; //400*400
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int grid[line_len][line_len];
int fx, fy, cx, cy, fdir = 0, cdir = 0;

void simul() {
    int dfx = fx + dx[fdir];
    int dfy = fy + dy[fdir];
    
    if (dfx < 0 || dfx >= line_len || dfy < 0 || dfy >= line_len || grid[dfx][dfy] == obs) {
        fdir = (fdir + 1) % 4;
    } else {
        fx = dfx;
        fy = dfy;
    }
    
    int dcx = cx + dx[cdir];
    int dcy = cy + dy[cdir];
    
    if (dcx < 0 || dcx >= line_len || dcy < 0 || dcy >= line_len || grid[dcx][dcy] == obs) {
        cdir = (cdir + 1) % 4;
    } else {
        cx = dcx;
        cy = dcy;
    }
}

int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < line_len; ++i) {
        for (int j = 0; j < line_len; ++j) {
            char c;
            cin >> c;

            switch (c) {
                case '*': grid[j][i] = obs; break;
                case '.': grid[j][i] = empty; break;
                case 'F': 
                    fx = j;
                    fy = i;
                    grid[j][i] = empty;
                    break;
                case 'C': 
                    cx = j;
                    cy = i;
                    grid[j][i] = empty;
                    break;
            }
        }
    }

    for (int min = 1; min < max_min; ++min) {
        simul();
        
        if (fx == cx && fy == cy) {
            cout << min << '\n';
            
            return 0;
        }
    }
    
    cout << 0 << '\n';
    
    return 0;
}
