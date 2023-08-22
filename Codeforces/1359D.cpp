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
constexpr ll Y = 61;

//The maximum value of dp(j, y) on y = 1..i 
//dp(i, y) = max score with 1..i cards and max val y
//dp(i, y) is the maximum of the following
//dp(i, y) = max dp(i-1, m <= a_i) if a_i is new max
//dp(i, y) = max dp(i-1, m > a_i) + a_i if a_i is not max
//60n states, O(1) transitions?
//
// Thinking
// Threw dp at it and it worked, maybe a bit sketchy
// The transitions are O(1) here because we need a contiguous subarray
// (Didn't think of contiguous subarray initially)
//
// Implementation
// Made a stupid mistake taking dp[i][j] instead of dp[i][a[i]]
// Rubber ducky, and if it doesn't work, rewrite again from memory
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vi a(n); for(auto&x : a) cin >> x;
        vector<vi> dp(n, vi(Y, -INFF));
        dp[0][a[0]+30] = 0;
        f1(i, n) {
            a[i] += 30;
            dp[i][a[i]] = 0;
            f0(j, a[i]+1) {
                dp[i][a[i]] = max(dp[i][a[i]], dp[i-1][j] + j - 30);
            }
            for (ll j = a[i]+1; j < Y; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i] - 30);
            }
        }

        ll ans = 0;
        f0(i, n) {
            f0(j, Y) {
                ans = max(ans, dp[i][j]);
            }
        }

        cout << ans << endl;
    } 
    
    return 0;
}
