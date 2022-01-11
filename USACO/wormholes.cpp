/*
ID: toronto4
TASK: wormhole
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_n = 12;
int N;
int X[max_n+1], Y[max_n+1], P[max_n+1];

int solve() {
    for (int i = 0; i <= N; ++i) {
        if (P[i] == 0) break;
    }
}

int main() {
//    freopen("combo.in", "r", stdin);
//    freopen("combo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> X[i] >> Y[i];
    
    cout << solve() << '\n';

    return 0;
}
