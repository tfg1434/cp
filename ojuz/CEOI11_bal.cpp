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

// Thinking
// if i_r < b_r and i_x < b_x then we never need to check i ever again.
// O(n) b/c each time we check an element i-2 we must pop i-1.

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<pair<ll, double>> stk; 
        vector<double> ans(n); 
        auto f = [&](pair<ll, double> a, ll bx) -> double {
            return pow(bx-a.f, 2) / (4.0*a.s);
        };
        f0(i, n) {
            ll x, r; cin >> x >> r;
            double mx = r;
            while (!stk.empty()) {
                auto last = stk.back();
                mx = min(mx, f(last, x));
                //if the new radius is larger, we don't care about the
                //previous most limiting
                if (mx >= last.s) {
                    stk.pop_back(); continue;
                } else break;
            }
            stk.pb({ x, mx });
            ans[i] = mx;

            // ans[i] = min(1.0*r[i], f(stk.back(), i));
            // if (i < n-1) {
                // if (f(stk.back(), i+1) > f(i, i+1)) stk.pb(i);
                // // while (f(stk.back(), i+1) > f(i, i+1)) {

                // // }
            // }
        }

        for (auto x : ans) {
            cout << fixed << setprecision(3) << x << endl;
        }
    } 
    
    return 0;
}
