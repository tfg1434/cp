#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> p(n);
        for (auto& x : p) cin >> x;

        auto good = [&](ll x) {
            //all cf_j <= k/100
            //equivalent to all p_j * 100 <= k * (x + p_0 + ... + p_j-1)
            //(increase must not exceed k*all before)
            // for (int j = 2; j < n; j++) {
                // ll sum = 0;
                // for (int i = 0; i < j; i++) sum += p[i];
                // if (p[j] * 100ll > k * (x + sum)) return false;
            // }
            // return true;
            p[0] += x;
            ll sum = p[0];
            for (int i = 1; i < n; i++) {
                if (p[i] * 100ll > k * sum) {
                    p[0] -= x;
                    return false;
                }
                sum += p[i];
            }
            p[0] -= x;
            return true;
        };

        ll l = -1, r = 100*1e9;
        while (r - l > 1) {
            ll m = (l + r) / 2ll;
            if (good(m)) r = m;
            else l = m;
        }

        cout << l+1 << '\n';
    }    
    
    return 0;
}

