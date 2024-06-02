#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

constexpr int MAX_SIEVE = 1e6;
vi primes;
void sieve() {
    vector<bool> isPrime(MAX_SIEVE+1, true);
    for (int i = 2; i*i <= MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (int j = i*i; j <= MAX_SIEVE; j += i)
                isPrime[j] = false;
    }
    for (int i = 2; i <= MAX_SIEVE; i++) if (isPrime[i])
        primes.pb(i);
}
int max_pairs(int k) {
    // if (k % 2) return k*(k-1)/2;
    // return k*(k-2)/2 + 1;
    if (k % 2) return k*(k+1)/2;
    return k*(k-2)/2 + 1 + k;
}
V<V<bool>> g;

void solve() {
    int n; cin >> n;
    int lo = 1, hi = n;
    while (hi-lo > 1) {
        int mi = (lo+hi)/2;
        max_pairs(mi) < n-1 ? lo = mi : hi = mi;
    }

    g.assign(hi, V<bool>(hi));
    for (int i = 0; i < hi; i++) for (int j = 0; j < hi; j++) 
        if (i != j) g[i][j] = g[j][i] = true;
    if (hi % 2 == 0)
        for (int i = 2; i < hi; i += 2) g[i][i+1] = g[i+1][i] = false;
    vi nxt(hi);
    for (int i = 0; i < hi; i++) while (!g[i][nxt[i]]) nxt[i]++;

    vi s, epath;
    s.pb(0);
    while (s.size()) {
        int u = s.back(); 

        // int v;
        // for (v = 0; v < hi; v++) {
            // if (g[u][v]) break;
        // }
        // if (v == hi) {
            // epath.pb(u);
            // s.pop_back();
        // } else {
            // s.pb(v);
            // g[u][v] = g[v][u] = false;
        // }
        // continue;

        if (nxt[u] == hi) {
            epath.pb(u);
            s.pop_back();
        } else {
            s.pb(nxt[u]);
            g[u][nxt[u]] = g[nxt[u]][u] = false;
            while (nxt[u] < hi && !g[u][nxt[u]]) nxt[u]++;
        }
    }
    
    V<bool> used(hi);
    vi ans;
    for (int u : epath) {
        ans.pb(u);
        if (!used[u]) {
            used[u] = true;
            ans.pb(u);
        }
    }
    for (int i = 0; i < n; i++) 
        cout << primes[ans[i]] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();
    int t; cin >> t; while (t--) solve();
    return 0;
}

