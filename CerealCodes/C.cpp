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
ll LOG2(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
bool isPow2(ll n) {
    return n && ((n & (n-1)) == 0);
}
ll LOG2C(ll x) {
    if (isPow2(x)) return LOG2(x);
    return LOG2(x)+1;
}

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }

    return res;
}

//i assume if t_i has no cereal, don't go to t_i, even if it's shorter
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, d; while (cin >> n >> d) {
        ll sum = 0;
        for (ll i = 2; i <= n; i *= 2) {
            sum += 1 | i;
        }
        for (ll i = 2; i <= n; i++) {
            if (isPow2(i)) continue;
            sum += i;
        }
        f0(i, d) {
            ll t; cin >> t;

            if (isPow2(t)){
                // if (n >> (LOG2(t)+1) >= 1+t) {
                    // cout << sum << endl;
                // } else {
                cout << sum - min(t+1, (t + 1) + (n >> (LOG2(t)+1))) << endl;
                // }
            } else {
                cout << sum - (t | 1) << endl;
            }
        }
    } 
    
    return 0;
}
