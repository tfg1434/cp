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

constexpr ll N=1e9+5;
struct BIT {
    int a[N],t[N];

    // ll sum(ll r) {
        // ll res = 0;
        // for (; r >= 0; r = (r & (r+1)) - 1) res += a[r];
        // return res;
    // }
    ll pointSum(ll idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += a[idx];
        return res;
    }
    void add(ll idx, ll d) {
        for (++idx; idx < N; idx += idx & -idx)
            a[idx] += d;
    }
    void rangeAdd(ll l, ll r, ll d) {
        add(l, d);
        add(r+1, -d);
    }
};

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> h(n), l(n);
        for (auto& x : h) cin >> x;
        for (auto& x : l) cin >> x;
        BIT a;
        fill(a.a, a.a+N, 0);

        for (ll i = 0; i < n; i++) {
            a.rangeAdd(l[i], h[i]-1, 1);
        }
        // for (ll i = 1; i < 10; i++) {
            // cout << "DEBUG: " <<  a.pointSum(i) << endl;
        // }
        // FENWICK OK
        
        ll sum = 0;
        unordered_map<ll, ll> mp;//cumsum, last ocurrence
        ll x1, x2;
        bool found = false;
        for (ll i = 1; i < N; i++) {
            // cout << sum << endl;
            if (mp.find(sum-k) != mp.end()) {
                // cout << i << endl;
                // cout << sum << endl;
                found = true;
                x1 = mp[sum-k];
                x2 = i;
                break;
            }
            mp[sum] = i;
            sum += a.pointSum(i);
        }
        if (!found) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << x1 << ' ' << x2 << endl;
        // cout << a.pointSum(1) << endl;
        // cout << a.pointSum(2) << endl;
        // cout << a.pointSum(3) << endl;
        // cout << a.pointSum(4) << endl;
    } 
    
    return 0;
}
