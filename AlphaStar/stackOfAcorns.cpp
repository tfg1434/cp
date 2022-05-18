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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<pll> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    sort(all(a));

    vector<ll> dp(n);
    dp[0] = 1;
    for (ll i = 1; i < n; i++) {
        dp[i] = 1;

        for (ll j = 0; j < i; j++) {
            if (a[i].second > a[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout << *max_element(all(dp)) << '\n';

    // vector<ll> w(n), l(n), a(n);
    // for (ll i = 0; i < n; i++) cin >> w[i] >> l[i];

    // auto check = [&](ll i) {
        // ll topw = w[a[i]];
        // ll topl = l[a[i]];

        // ll prevw = w[a[i-1]];
        // ll prevl = l[a[i-1]];

        // return topw < prevw && topl < prevl;
    // };

    // ll ans = 0;
    // y_combinator([&](auto rec, ll i) -> void {
            // ans = max(ans, i-1);
            // if (i >= n) return;

            // for (ll j = 0; j < n; j++) {
                // a[i] = j;
                // if (check(i)) rec(i+1);
            // }
    // })(0);

    // cout << ans << endl;
    
    return 0;
}

