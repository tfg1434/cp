#include <bits/stdc++.h>
using namespace std;

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

const int max_n = 3e5;
int n, m;
using u64 = unsigned long long;
const int base = 1e9+7, mod = 1e9+123;
int pow1[max_n];
u64 pow2[max_n];
void init() {
    pow1[0] = 1;
    for (int i = 1; i < max_n; i++) pow1[i] = 1LL*pow1[i-1]*base%mod;
    pow2[0] = 1;
    for (int i = 1; i < max_n; i++) pow2[i] = pow2[i-1]*base;
}

void solve() {
    cin >> n >> m; 
    V<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c; cin >> c; a[i][j] = c-'0';
    }

    map<pair<int, u64>, int> cnt;
    for (int j = 0; j < m; j++) {
        pair<int, u64> hash;
        for (int i = 0; i < n; i++) {
            hash.f += 1LL*pow1[i]*a[i][j]%mod;
            if (hash.f >= mod) hash.f -= mod;
            hash.s += pow2[i]*a[i][j];
        }
        for (int i = 0; i < n; i++) {
            auto h = hash;
            int coef = a[i][j] == 1 ? -1 : 1;
            h.f += (1LL*pow1[i]*coef+mod) % mod;
            if (h.f >= mod) h.f -= mod; 
            h.s += pow2[i]*coef;
            cnt[h]++;
        }
    }

    pair<int, u64> U;
    int V = 0;
    for (auto [u, v] : cnt) if (ckmax(V, v)) U = u;
    cout << V << '\n';
    for (int j = 0; j < m; j++) {
        pair<int, u64> hash;
        for (int i = 0; i < n; i++) {
            hash.f += 1LL*pow1[i]*a[i][j]%mod;
            if (hash.f >= mod) hash.f -= mod;
            hash.s += pow2[i]*a[i][j];
        }
        for (int i = 0; i < n; i++) {
            auto h = hash;
            int coef = a[i][j] == 1 ? -1 : 1;
            h.f += (1LL*pow1[i]*coef+mod) % mod;
            if (h.f >= mod) h.f -= mod; 
            h.s += pow2[i]*coef;
            if (h == U) {
                for (int k = 0; k < n; k++) cout << (a[k][j] ^ (k == i));
                cout << '\n';
                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int t; cin >> t; while (t--) solve();
    return 0;
}
