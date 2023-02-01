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


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, m, d; cin >> n >> m >> d;
        vector<ll> pos(n+1);
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            pos[x] = i;
        }
        vector<ll> a(m);
        for(auto& x : a) cin >> x;

        ll ans = INFF;
        bool zero = false;
        for (ll i = 0; i < m-1; i++) {
            if (pos[a[i]] >= pos[a[i+1]] || pos[a[i+1]] > pos[a[i]]+d) {
                cout << "0\n";
                zero = true;
                break;
            }
            // gg(d+1, pos[a[i+1]]-pos[a[i]]);
            ans = min({ ans,  pos[a[i+1]]-pos[a[i]]});
            if (n > d+1) {
                ans = min(ans, d+1 - (pos[a[i+1]] - pos[a[i]]));
            }
        }
        if(zero) continue;

        cout << ans << endl;
    } 
    
    return 0;
}
