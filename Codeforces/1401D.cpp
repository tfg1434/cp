#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll mod = 1e9+7;
constexpr ll mod2 = 998244353;

template <ll MOD>
class Modular {
// using ModInt = Modular<1'000'000'007>;
public:
    Modular(ll v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(ll a, ll b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (ll)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, ll e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend std::istream& operator>>(std::istream &is, Modular& a) {
        is >> a.value;
        a.value %= MOD;
        if (a.value < 0)
            a.value += MOD;
        return is;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    friend Modular& operator++(Modular& a, int) {
        return a += 1;
    }

    friend Modular operator++(Modular const& a, int) {
        return Modular(a)++;
    }

    friend Modular& operator--(Modular& a, int) {
        return a -= 1;
    }

    friend Modular operator--(Modular const& a, int) {
        return Modular(a)--;
    }

    int value;
    static const int MOD_value = MOD;
};

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> adj(n+1);
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        ll m; cin >> m;
        vector<ll> p(m); for (auto& x : p) cin >> x;
        sort(all(p), greater<ll>());

        vector<ll> w;
        y_combinator([&](auto rec, ll u, ll par) -> ll {
            ll cnt = 1;
            for (auto v : adj[u]) {
                if (v == par) continue;

                cnt += rec(v, u);
            }
            if (par != 0) w.push_back(cnt * (n-cnt));
            return cnt;
        })(1, 0);
        
        sort(all(w), greater<ll>());
        while (p.size() < n-1) p.push_back(1);
        // gg(p, w);
        // Modular<mod> ans = 0;
        ll ans = 0;
        if (m <= n-1) {
            for (ll i = 0; i < m; i++) {
                ans = (ans + p[i]*w[i])%mod;
            }
            for (ll i = m; i < n-1; i++) {
                ans = (ans+w[i])%mod;
            }
        } else {
            ll x = m-n+2; ll s = 1;
            for (ll i = 0; i < x; i++) {
                s = s*p[i]%mod;
            }
            ans = s * w[0] % mod;
            for (ll i = 1, j = x; i < n-1; i++, j++) {
                ans = (ans + w[i] * p[j]) % mod;
            }
            // ll x = m-n;
            // for (ll i = 0; i < x; i++) {
                // ans = ans*p[i]%mod;
            // }
            // ans = ans*w[0]%mod;
            // for (ll i = 1; i < n; i++) {
                // ans = (ans + w[i] * p[x+i]) % mod;
                // gg(w[i], p[x+i]);
            // }
        }
        cout << ans << endl;
    } 
    
    return 0;
}
