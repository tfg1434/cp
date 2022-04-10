#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        for (auto& x: a) cin >> x;
        sort(all(a));
        
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++) 
            pre[i + 1] = pre[i] + a[i];

        set<pll> done;
        set<ll> sums;
        y_combinator([&](auto recurse, ll start, ll end) -> void {
            if (start >= end) return;
            if (!done.emplace(start, end).second) return;

            sums.insert(pre[end] - pre[start]);
            ll mn = a[start], mx = a[end-1], mid = (mn + mx) / 2;
            //upper_bound, right starts with thing greather than mid
            ll split = (ll) (upper_bound(all(a), mid) - a.begin());
            recurse(start, split);
            recurse(split, end);
        })(0, n);

        for (int i = 0; i < q; i++) {
            ll x; cin >> x;
            if (sums.count(x)) cout << "Yes\n";
            else cout << "No\n";
        }
    }    
    
    return 0;
}

