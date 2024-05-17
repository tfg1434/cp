#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

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

vi polyhash::pow1 {1};
V<u64> polyhash::pow2 {1};

const int mod = 1e9+7;
const int max_n = 2000;
int dp[max_n+1];
int n;
string a;

void solve() {
    cin >> a; n = a.size();
    reverse(all(a));
    auto rev_hash = polyhash(a);
    reverse(all(a));
    auto hash = polyhash(a);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            if ((j-i)%2 == 0) {
                int m = (i+j)/2;
                if (hash(i, m, n) == rev_hash(n-1-(j-1), n-1-(m-1), n)) {
                    dp[j] += dp[i];
                    if (dp[j] >= mod) dp[j] -= mod;
                }
            } else {
                int m = (i+j)/2;
                if (hash(i, m, n) == rev_hash(n-1-(j-1), n-1-(m), n)) {
                    dp[j] += dp[i];
                    if (dp[j] >= mod) dp[j] -= mod;
                }
            }
        }
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
