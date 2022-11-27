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
#define mod2(a, n) ((a%n)+n)%n


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<vector<ll>> b(n, vector<ll>());
    for (ll i = 0; i < n; i++) {
        ll k; cin >> k;
        for (ll j = 0; j < k; j++) {
            ll x; cin >> x;
            b[i].push_back(x);
        }
        sort(all(b[i]));
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        // cout << b[i] << endl;
        for (ll j = 0; j < b[i].size()-1; j++) {
            ll lo = b[i][j], hi = b[i][j+1];
            ll left = mod2(i-1, n), right = mod2(i+1, n);
            ll cLeft = lower_bound(all(b[left]), lo) - lower_bound(all(b[left]), hi);
            // all(b[left]) ==> b[left].left, b[left].right
            ll cRight = lower_bound(all(b[right]), lo) - lower_bound(all(b[right]), hi);
            
            // cout << lo << ' ' << hi << '|'<< cLeft << ' ' << cRight << endl;
            if (cLeft != cRight) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
