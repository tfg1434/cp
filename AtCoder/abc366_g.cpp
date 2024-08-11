#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

bool ans;
const int N = 60;
int n, m;
bitset<N> a[N], basis[N];

void print_a() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << " \n"[j==n-1];
    }
}

void print_basis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << basis[i][j] << " \n"[j==n-1];
    }
}

void make_ref() {
    for (int i=0, j=0; j < n; i++, j++) {
        for (int I = i; I < n; I++) if (a[I][j]) {
            swap(a[I], a[i]);
            break;
        }
        if (!a[i][j]) continue;
        for (int I = 0; I < n; I++) if (I != i && a[I][j]) {
            a[I] ^= a[i];
        }
    }
}

void find_basis() {
    V<bool> is_free(n, true);
    for (int i = 0; i < n; i++) {
        int col = 0;
        for (; col < n; col++) if (a[i][col]) break;
        if (col == n) continue;
        is_free[col] = false;
        for (int j = col+1; j < n; j++) if (a[i][j]) {
            basis[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) if (is_free[i]) {
        basis[i][i] = 1;
    }
}

void check_or() {
    for (int i = 0; i < n; i++) {
        if (!basis[i].count()) {
            ans = false;
        }
    }
}

void solve() {
    ans = true;
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v; u--; v--;
        a[u][v] = a[v][u] = 1;
    }
    make_ref();
    find_basis();
    check_or();
    if (!ans) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    V<ll> sol(n);
    for (int bit = 0; bit < n; bit++) {
        for (int i = 0; i < n; i++) if (basis[i][bit]) {
            sol[i] |= (1LL << bit);
        }
    }
    for (int i = 0; i < n; i++) cout << sol[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
