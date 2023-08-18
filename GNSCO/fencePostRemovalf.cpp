#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define f first
#define s second
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
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m; while (cin >> n >> m) {
        vi h(n), c(n), d(n-1);
        for (auto&x : h) cin >> x;
        for (auto&x : c) cin >> x;
        //cost to add elements i and i+1 of d = cost to remove i+1 in h.
        f0(i, n-1) {
            d[i] = h[i+1] - h[i];
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        ll ans = INFF;
        ll lo = 0, hi = 1e7;
        while (lo < hi) {
            ll k = (lo+hi)/2;
            vector<vi> dp(n-1, vi(2));
            if (abs(d[0]) > k) {
                dp[0][true] = c[1];
                dp[0][false] = c[0];
            } else {
                dp[0][true] = dp[0][false] = 0;
            }
            f1(i, n-1) {
                ll mn = INFF;
                ll sum = 0;
                for (ll j = i-1; j >= 0; j--) {
                    sum += c[j+2];
                    mn = min(mn, dp[j][false] + sum);
                }
                dp[i][true] = min(dp[i-1][true]+c[i+1], mn);

                ll j = i;
                ll curr = d[i];
                ll cost = 0;
                while (abs(curr) > k && j >= 0) {
                    // gg(cost, curr);
                    cost += c[j];
                    if (j > 0) curr += d[--j];
                    else break;
                }
                // gg(cost, i, j);
                dp[i][false] = dp[j][false] + cost;
            }

            ll res = min(dp[n-2][true], dp[n-2][false]);
            // gg(dp, lo, hi);
            if (res > m) {
                lo = k+1;
            } else {
                hi = k;
            }
        }

        cout << lo << endl;
    } 
    
    return 0;
}

