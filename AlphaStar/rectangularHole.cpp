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
    
    ll n, b; while (cin >> n >> b) {
        vector<ll> h(n);
        for (auto& x : h) cin >> x;

        ll ans = INFF;
        vector<ll> comb;
        for (ll bales = 1; bales <= n; bales++) {
            y_combinator([&](auto rec, ll off, ll k) -> void {
                if (k == 0) {
                    // cout << comb << endl;
                    ll sum = 0;
                    for (auto x : comb) sum += x;
                    if (sum >= b) ans = min(ans, abs(b - sum));

                    return;
                }

                for (ll i = off; i <= n - k; i++) {
                    comb.push_back(h[i]);
                    rec(i+1, k-1);
                    comb.pop_back();
                }
            })(0, bales);
        }

        cout << ans << endl;
    }
    
    return 0;
}

