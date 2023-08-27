#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
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
template <typename Iter, typename Cont>
bool is_last(Iter iter, const Cont& cont) {
    return (iter != cont.end()) && (next(iter) == cont.end());
}

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;
constexpr int MAX_SIEVE = 1e7+5;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    // vector<bool> isPrime(MAX_SIEVE, true);
    // for (ll i = 2; i*i <= MAX_SIEVE; i++) {
        // if (isPrime[i])         
            // for (ll j = i*i; j <= MAX_SIEVE; j += i)
                // isPrime[j] = false;
    // }
    int T; cin >> T; while (T--) {
        ll x; cin >> x;
        multiset<ll> p;
        ll last = 2;
        ll y = x;
        while (x > 1) {
            if (x % last == 0) {
                x /= last;
                p.insert(last);
            } else {
                if (last > (ll) sqrt(x) + 1) {
                    p.insert(x);
                    break;
                }
                last++;
            }
        }

        vi ans;
        ans.pb(y);
        while (!p.empty()) {
            ll mx = *prev(p.end()); 
            p.erase(prev(p.end()));
            ll z = mx - 1;
            ll div = 2;
            while (z > 1) {
                if (z % div == 0) {
                    z /= div;
                    p.insert(div);
                } else {
                    if (div > (ll) sqrt(z) + 1) {
                        p.insert(z);
                        break;
                    }
                    div++;
                }
            }
            y /= mx;
            y *= (mx - 1);
            ans.pb(y);
        }

        cout << ans.size() << endl;
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    } 
    
    return 0;
}
