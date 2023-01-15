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
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll MAXP = 2e3 + 5;
ll vis[MAXP];
ll p[MAXP][MAXP];
ll k[MAXP];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        bool ok = false;
        memset(vis, 0, sizeof vis);
        for (ll i = 0; i < n; i++) {
            cin >> k[i];
            for (ll j = 0; j < k[i]; j++) {
                cin >> p[i][j];
                vis[p[i][j]]++;
            }
        }
        for (ll i = 0; i < n; i++) {
            bool all = true;
            for (ll j = 0; j < k[i]; j++) {
                if (vis[p[i][j]] < 2) {
                    all = false;
                    break;
                }
            }

            ok |= all;
        }

        // set<ll> vis;
        // bool ok = false;
        // for (ll i = 0; i < n; i++) {
            // ll k; cin >> k;
            // set<ll> st;
            // for (ll j = 0; j < k; j++) {
                // ll x; cin >> x;
                // st.insert(x);
            // }
            // // cout << st << endl;
            // if (includes(all(vis), all(st))) {
                // ok = true;
                // gg(vis, st);
                // // break;
            // }

            // // vis.insert(all(st));
            // vis.merge(st);
        // }

        cout << (ok ? "YES":"NO") << endl;
    }
    
    return 0;
}
