#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            if (k >= i) cout << 2 << ' ', k -= i;
            else if (k) cout << -2*(i-k)+1 << ' ', k=0;
            else  cout << "-1000 ";
        }
        cout << endl;

        //idiot no 0 sum array :c
        // ll m = 1;
        // while (m*(m+1)/2 < k) {
            // m++;
        // }
        // m--;

        // for (ll i = 0; i < m; i++) {
            // cout << 1 << ' ';
        // }

        // if (k == 0) cout << -1000 << ' ';
        // else if (m*(m+1)/2 == k) cout << 1 << ' ';
        // else cout << -m + (k-m*(m+1)/2) << ' ';
        // for (ll i = m+1; i < n; i++) {
            // cout << -1000 << ' ';
        // }
        // cout << endl;
    } 
    
    return 0;
}
