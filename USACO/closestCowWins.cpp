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

// Thinking
// Didn't think to partition based on enemies, it reduces it to few cases
// Realized two cows vs one cow

// Implementation
// Didn't know how to implement sliding window in O(nlogn) with multiset
// Didn't think to combine two arrays, then sort initially
// Recognized only care about truncated sliding window size
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll k, m, n; while (cin >> k >> m >> n) {
        vector<pll> a(k+m);
        f0(i, k) {
            cin >> a[i].f >> a[i].s;
        }
        f0(i, m) {
            cin >> a[i+k].f;
            a[i+k].s = -1;
        }
        sort(all(a));

        vector<ll> d;
        ll sum = 0;
        ll lastEnemy = -1;
        for (ll i = 0; i < k+m; i++) {
            if (a[i].s != -1) {
                sum += a[i].s;
                continue;
            } 
            if (lastEnemy == -1) {
                d.pb(sum);
            } else {
                ll mx = 0;
                ll windowSum = 0;
                for (ll j = lastEnemy+1, r = lastEnemy; j < i; j++) {
                    while (r+1 < i && (a[r+1].f - a[j].f)*2 < a[i].f - a[lastEnemy].f) {
                        windowSum += a[++r].s;
                    }
                    mx = max(mx, windowSum); 
                    windowSum -= a[j].s;
                }

                assert(2*mx >= sum);
                d.pb(mx);
                d.pb(sum - mx);
                gg(mx, sum);
            }

            lastEnemy = i;
            sum = 0;
        }
        d.pb(sum);

        sort(rall(d));
        ll ans = 0;
        f0(i, n) {
            ans += d[i];
        }
        cout << ans << endl;
    } 
    
    return 0;
}
