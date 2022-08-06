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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        // cout << "HEKKOI" << endl;

        vector<ll> ans(n, 0);
        ll nxt = (floor(sqrt(n))+1)*(floor(sqrt(n))+1);
        if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
            nxt = n;
        }
        y_combinator([&](auto rec, ll r, ll m) -> void {
            // cout << r << 'e' << m << endl;
            if (r == 0) return;

            for (ll i = m - (r); i <= r; i++) {
                ans[i] = m - i;
                if (ans[i] == 1) return;
            }
            ll last = m -r-1;
            ll nxt2 = (floor(sqrt(last))+1)*(floor(sqrt(last))+1);
            if (ceil((double)sqrt(last)) == floor((double)sqrt(last))) {
                nxt2 = last;
            }
            // cout << last << endl;
            // cout << nxt2 << endl;
            // cout << ans << endl;

            rec(m-r-1, nxt2);

        })(n-1, nxt);

        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << endl;
    }    
    
    return 0;
}

