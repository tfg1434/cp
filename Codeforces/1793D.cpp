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
 
 
constexpr int MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
 
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);

    ll n; while (cin>> n) {
        vector<ll> p(n+1), q(n+1);
        vector<ll> c1(n+1), c2(n+1);
        for (ll i = 1; i <= n; i++) {
            cin >> p[i];
            c1[p[i]] = i;
        }
        for (ll i = 1; i <= n; i++) {
            cin >> q[i];
            c2[q[i]] = i;
        }
        
        ll lx1 = n, lx2 = n, rx1 = 1, rx2 = 1, ans = 0;
        for (ll i = 1; i < n; i++) {
            lx1 = min(lx1, c1[i]); lx2 = min(lx2, c2[i]);
            rx1 = max(rx1, c1[i]); rx2 = max(rx2, c2[i]); 

            ll minL1, maxR1, minL2, maxR2;
            if (c1[i+1] < lx1) {
                minL1 = c1[i+1]+1;
                maxR1 = n;
            } else if (c1[i+1] > rx1) {
                minL1 = 1;
                maxR1 = c1[i+1]-1;
            } 
            if (c2[i+1] < lx2) {
                minL2 = c2[i+1]+1;
                maxR2 = n;
            } else if (c2[i+1] > rx2) {
                minL2 = 1;
                maxR2 = c2[i+1]-1;
            } 

            ans += max(min(lx1, lx2) - max(minL1, minL2) + 1, 0ll) * max(min(maxR1, maxR2) - max(rx1, rx2)+1, 0ll);
        }

        ans += min(c1[1], c2[1]) * (min(c1[1], c2[1]) - 1) / 2;
        ans += (n - max(c1[1], c2[1])) * (n - max(c1[1], c2[1]) + 1) / 2;
        ans += abs(c1[1] - c2[1]) * (abs(c1[1] - c2[1]) - 1) / 2;
        ans++;
        cout << ans << endl;
    }
    
    return 0;
}
