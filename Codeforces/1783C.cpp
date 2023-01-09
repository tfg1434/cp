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
constexpr ll MAXN = 5e5+1;
ll vis[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        memset(vis, 0, sizeof vis);
        ll n, m; cin >> n >> m;
        priority_queue<pll, vector<pll> , greater<pll>> pq;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            pq.push({ a[i], i }) ;
        }

        ll ans = 0;
        ll mx = 0;
        while (pq.size() > 0 && m >= pq.top().first) {
            m -= pq.top().first;
            mx = max(mx, pq.top().first);
            ans++;
            vis[pq.top().second] = 1;
            pq.pop();
        }

        if (ans < n && (vis[ans] || m + mx - a[ans] >= 0)) ans++;
        cout << n - ans + 1 << endl;
    } 
    
    return 0;
}
