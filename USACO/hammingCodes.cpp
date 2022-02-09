/*
ID: toronto4
TASK: hamming
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int n_max = 65;
constexpr int b_max = 10;
constexpr int d_max = 10;
constexpr int max_u8 = (1 << 8) + 1;
int N, B, D, searchTo;
int codewords[n_max];
int dist[max_u8][max_u8];

void solve(int curr, int start){
    if (curr == N) {
        for (int i = 0; i < N; i++) {
            if (i%10 != 0) cout << ' ';
            cout << codewords[i];
            if (i%10==9 || i == curr-1) cout << '\n';
        }

        exit(0);
    }
    
    bool ok;
    
    for (int i = start; i < searchTo; ++i) {
        ok = true;

        for (int j = 0; j < curr; ++j) {
            if (dist[codewords[j]][i] < D) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            codewords[curr] = i;
            solve(curr+1, i+1);
        }
    }
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B >> D;
    searchTo = (1 << B);
    codewords[0] = 0;

    for (int i = 0; i < max_u8; ++i) {
        for (int j = 0; j < max_u8; ++j) {
            dist[i][j] = 0;

            for (int k = 0; k < B; ++k) {
                dist[i][j] += ((1 << k) & i) != ((1 << k) & j);
            }
        }
    }
    
    solve(1, 1);

    return 0;
}
