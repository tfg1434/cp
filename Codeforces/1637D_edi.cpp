//https://codeforces.com/contest/1637/problem/D

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") //avx2, bmi2, lzcnt (?), known to fail on usaco. others work, and so do sse

//vars
using ll = long long;
using db = long double;
using str = string;

//pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

//vector
template<class T> using vec = vector<T>;
//template<class T, size_t SZ> using arr = array<T, SZ>;
#define pb push_back
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(false);

    /*FILES
    freopen("INPUTNAME", "r", stdin);
    freopen("INPUTNAME", "w", stdout);
    */

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int a[N], b[N];
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];

        /*if (N == 1) {
            cout << 0 << "\n";
            continue;
        }*/

        int sum = 0;
        for (int i = 0; i < N; i++) sum += a[i] + b[i];

        bool ach[N+1][100*N+1]; //first i terms, can we achieve j sum
        for (int i = 0; i <= N; i++) fill(ach[i], ach[i]+100*N, false);

        ach[0][0] = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= 100*N; j++) {
                if (j >= a[i-1]) ach[i][j] = ach[i][j] || ach[i-1][j-a[i-1]];
                if (j >= b[i-1]) ach[i][j] = ach[i][j] || ach[i-1][j-b[i-1]];
            }
        }

        int closest = -1;
        for (int i = 0; i <= 100*N; i++) {
            if (!ach[N][i]) continue;
            if (closest == -1) {closest = i; continue;}
            if (abs(sum - 2*i) < abs(sum - 2*closest)) closest = i;
        }
        cout << (sum - 2*closest) << '\n';

        ll ans = 0;
        for (int i = 0; i < N; i++) ans += (N-2)*(a[i]*a[i] + b[i]*b[i]);
        ans += (ll)closest * closest;
        ans += (ll)(sum - closest) * (sum - closest);
        cout << ans << "\n";
    }
}
