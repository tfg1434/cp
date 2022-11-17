#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
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


constexpr int MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


vector<ll> getPrimes(ll m) {
    ll d = 2;
    vector<ll> res;
    while (d*d <= m) {
        bool seen = false;
        while (m % d == 0) {
            m /= d;
            seen = true;
        }
        if (seen) res.push_back(d);
        d++;
    }
    if (m > 1) res.push_back(m);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n); for (auto& x : a) cin >> x;

        //verify it is possible
        bool ok = true;
        for (ll i = 1; i < n; i++) {
            if (a[i-1] % a[i] != 0) ok = false;
        }
        if (!ok) {
            cout << 0 << endl;
            continue;
        }

        vector<ll> primes = getPrimes(a[0]);
        // cout << primes << endl;
        map<pll, ll> calc;
        for (ll i = 1; i < n; i++) {
            calc[{ a[i-1], a[i] }] = 0;
        }

        for (auto p : calc) {
            ll arg1 = p.first.first / p.first.second; //a_{i-1}/a_i
            ll till = m / p.first.second; // m/a_i ( k <= m/a_i )

            vector<ll> arg1Primes;
            for (auto x : primes) {
                if (arg1 % x == 0) arg1Primes.push_back(x);
            }
            ll sz = arg1Primes.size(); //< 20
            ll ans = 0;
            // cout << arg1Primes << endl;

            for (ll mask = 0; mask < (1 << sz); mask++) {
                ll prod = 1;
                ll cnt = 0;
                for (ll j = 0; j < sz; j++) {
                    if (mask & (1 << j)) {
                        prod *= arg1Primes[j];
                        cnt++;
                    }
                }

                if (cnt%2 == 0) ans += till / prod;
                else ans -= till / prod;
            }

            calc[p.first] = ans;
            // cout << "DEBUG " << ans << endl;
        }

        ll ANS = 1;
        for (ll i = 1; i < n; i++) {
            ANS *= calc[{a[i-1], a[i]}];
            ANS %= MOD;
        }

        cout << ANS << endl;
    }    
    
    return 0;
}
