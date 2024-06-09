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

using u64 = unsigned long long;
struct polyhash {
    static const int mod = 1e9+123;
    static const int base = 1e9+7;
    static vi pow1;
    static V<u64> pow2;
    vi pre1;
    V<u64> pre2;
    polyhash(const string& s) : pre1(s.size()+1), pre2(s.size()+1) {
        while (pow1.size() <= s.size()) {
            pow2.pb(pow2.back()*base);
            pow1.pb(1LL*pow1.back()*base%mod);
        }
        for (int i = 0; i < s.size(); i++) {
            pre2[i+1] = pre2[i]+pow2[i]*s[i];
            pre1[i+1] = pre1[i]+1ll*pow1[i]*s[i]%mod;
            if (pre1[i+1] >= mod) pre1[i+1] -= mod;
        }
    }
    pair<int, u64> operator()(int l, int r, int max_pow) {
        u64 hash2 = pre2[r]-pre2[l];
        int hash1 = pre1[r]-pre1[l];
        if (hash1 < 0) hash1 += mod;
        hash2 *= pow2[max_pow-r];
        hash1 = 1LL*hash1*pow1[max_pow-r]%mod;
        return {hash1, hash2};
    }
};

vi polyhash::pow1{1};
V<u64> polyhash::pow2{1};

int gauss(int n) { return n*(n+1)/2; }

int f(int k, int X, int Y) {
    if (k <= X) return gauss(k+1);
    if (X < k && k <= Y) return (k+1)*(X+1) - gauss(X);
    int res = (Y+1)*(X+1);
    if (k-X < Y) res -= gauss(Y-(k-X));
    return res;
}

void solve() {
    string s; cin >> s; int n = s.size();
    auto S = polyhash(s);
    int i;
    for (i = 0; i < n && s[i] == 'a'; i++) ;
    if (i == n) {
        cout << n-1 << '\n';
        return;
    }

    int ans = 0;
    for (int j = i+1; j <= n; j++) if (s[j-1] != 'a') {
        auto hash = S(i, j, n);

        int len = j-i;
        int k = j;
        bool bad = false;
        vi matches {i};
        while (true) {
            while (k < n && s[k] == 'a') k++;
            if (k == n) {
                break;
            }
            if (k+len > n || S(k, k+len, n) != hash) {
                bad = true;
                break;
            }
            matches.pb(k);
            k += len;
        }
        // ps(matches);
        if (bad || !matches.size()) continue;

        int X = matches[0];
        int Y = n-(matches.back()+len);
        if (X > Y) swap(X, Y);
        int K = n;
        for (int ii = 0; ii+1 < matches.size(); ii++) {
            ckmin(K, matches[ii+1] - (matches[ii]+len));
        }

        ans += f(K, X, Y);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

