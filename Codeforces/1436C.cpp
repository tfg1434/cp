#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}

ll C(ll n, ll k, const vector<ll> &fact, const vector<ll> &inv) {
    if (k > n) return 0;
    ll res = (fact[n] * inv[k]) % MOD;
    res = (res * inv[n - k]) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    ll n, x, pos;
    while (cin >> n >> x >> pos) {
        vector<ll> fact(n+1, 1LL);
        vector<ll> invfact(n+1, 1LL);
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i-1] * i) % MOD;
            invfact[i] = binpow(fact[i], MOD-2);
        }

        ll l = 0, r = n;
        ll cl = 0, cg = 0;
        while (l < r) {
            ll m = (l + r) / 2;
            if (pos >= m) {
                if (pos != m) cl++;
                l = m + 1;
            } else if (pos < m) {
                cg++;
                r = m;
            }
        }

        ll other = n - cl - cg - 1;
        ll canG = n - x, canL = x - 1;
        ll CL = C(canL, cl, fact, invfact);
        //order matters
        CL = (CL * fact[cg]) % MOD;
        ll CG = C(canG, cg, fact, invfact);
        CG = (CG * fact[cl]) % MOD;

        ll ans = (CG * CL) % MOD;
        ans = (ans * fact[other]) % MOD;

        cout << ans << '\n';
    }
    
    return 0;
}

