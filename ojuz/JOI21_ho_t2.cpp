#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define f first
#define s second
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
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, q; while (cin >> n >> q) {
        vi pos(n);
        vi lo(n), hi(n);
        vi a(n);
        f0(i, n) {
            cin >> a[i];
            lo[i] = hi[i] = pos[i] = a[i];
        }

        vi ans(n);
        f0(i, q) {
            ll t; cin >> t;
            f0(j, n) {
                pos[j] += t;
                if (t > 0) {
                    if (j < n-1 && pos[j] > lo[j+1]) {
                        hi[j] = lo[j+1];
                    } else {
                        hi[j] = max(hi[j], pos[j]);
                    }
                } else {
                    if (j > 0 && pos[j] < hi[j-1]) {
                        lo[j] = hi[j-1];
                    } else {
                        lo[j] = min(lo[j], pos[j]);
                    }
                }
            }
            // if (t > 0) {
                // f0(j, n) {
                    // ans[j] += max(0ll, pos[j]+t - hi[j]);
                    // pos[j] += t;
                    // hi[j] = max(hi[j], pos[j] + t);
                // }
            // } else {
                // for (ll j = n-1; j >= 0; j--) {
                    // // ans[j] += max(0ll, -(pos[j]+t - lo[j]));
                    // if (pos[j]+t < lo[j]) {
                        // if (j == 0 || pos[j]+t >= hi[j-1]) {
                            // ans[j] += -(pos[j]+t - lo[j]);
                        // } else {
                            // gg(hi[j-1], lo[j]);
                            // ans[j] += hi[j-1] - lo[j];
                        // }
                    // }
                    // pos[j] += t;
                    // lo[j] = min(lo[j], pos[j]+t);
                // }
            // }
            // gg(ans);
        }

        f0(i, n) cout << hi[i]-lo[i] << endl;
    } 
    
    return 0;
}
