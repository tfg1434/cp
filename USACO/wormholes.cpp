/*
ID: toronto4
TASK: wormhole
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_n = 12;
constexpr int yes = 1, no = 0;
int N;
int X[max_n+1], Y[max_n+1], P[max_n+1];
int nextRight[max_n+1];

bool check(){
    for (int i = 1; i <= N; ++i) {
        int pos = i;
        
        for (int steps = 0; steps < N; ++steps) {
            pos = nextRight[P[pos]];
        }
        //cool, a cycle!
        if (pos != 0) return true;
    }
    
    return false;
}

int solve() {
    int i;
    
    for (i = 1; i <= N; ++i)
        if (P[i] == 0) break;
    
    //trivial case
    if (i > N) return check() ? yes : no;

    int total = 0;
    //try pair i for other holes; call; backtrack
    for (int ii = i+1; ii <= N; ++ii) {
        if (P[ii] == 0) {
            P[i] = ii;
            P[ii] = i;
            total += solve();
            
            P[i] = P[ii] = 0;
        }
    }
    
    return total;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> X[i] >> Y[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (X[j] > X[i] && Y[i] == Y[j]) {
                if (nextRight[i] == 0 || X[j] < X[nextRight[i]])
                    nextRight[i] = j;
            }
        }
    }
    
    cout << solve() << '\n';

    return 0;
}
