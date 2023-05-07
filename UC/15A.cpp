#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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

ll ask(ll x) {
    cout << "? " << x << endl;
    ll res; cin >> res;
    return res;
}

int main() {
    ll n; cin >> n;
    ll lo = 0, hi = n+1;
    ll ans = -1, d = 0;
    while (hi-lo > 2) {
        ll m1 = (lo+hi)/2, m2 = hi-1;
        ll x = ask(m1);
        ll y = ask(m2);

        //found the light is m1
        if (x-d == 0) {
            hi = lo = m1;
            break;
        //found the light is m2
        } else if (x==y) {
            hi = lo = m2;
            break;
        }

        if (y-d == 0) {
            lo = m1, hi = m2;
        } else {
            hi = m1;
        }
        d = y;
    }
    ans = (hi+lo)/2;

    cout << "! " << ans << endl;

    // ll lo = 0, hi = n+1;
    // ll ans = -1, d = 0;
    // while (hi-lo>=6) {
        // ll m1 = (2*lo+hi)/3, m2 = (lo+2*hi)/3;
        // ll x = ask(m1), y = ask(m2), z = ask(m1+1);

        // //found the light is m1
        // if (x-d == 0) {
            // ans = m1;
            // break;
        // //found the light is m2
        // } else if (x==y) {
            // ans = m2;
            // break;
        // }
        // //m1<x<m2
        // if (y-d == 0) {
            // lo = m1, hi = m2;
        // } else {
            // //x<m1
            // if (z-d == 3) {
                // hi = m1;
            // } else {
                // lo = m2;
            // }
        // }

        // d = z;
    // }
    // for (ll i = lo+1; i <= hi; i++) {
        // ll x = ask(i);
        // if (x == d) {
            // ans = i;
            // break;
        // }
        // d = x;
    // }

    // cout << "! " << ans << endl;
    
    return 0;
}
