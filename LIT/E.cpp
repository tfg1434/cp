#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
    
    ll n, m, k; while (cin >> n >> m >> k) {
        vector<ll> a(n); for(auto&x:a)cin >> x;
        vector<ll> b(m); for(auto&x:b)cin >> x;
        if (n > m) {
            swap(n, m);
            swap(a, b);
        }
        sort(all(a)); sort(rall(b));
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < n; i++) {
            s1 += a[i];
            s2 += b[i];
        }
        vector<ll> prea(n+1);
        partial_sum(all(a), prea.begin()+1);
        vector<ll> preb(m+1);
        partial_sum(all(b), preb.begin()+1);

        gg(prea, preb);
        // ll t1 = s1, t2 = s2;
        double ans = 0;
        for (ll i = 1; i <= k; i++) {
            ll x = preb[i+1];
            ll y = prea[k-i+1];
            //A, B
            ll da = i-(k-i);
            double res = ((double)(s1 + x-y) / (double)(n+da)) + (double)((s2 + y - x) / (double)(m-da));
            res /= 2;
            if (res > ans) {
                gg(x, y, da);
            }
        }

        cout << setprecision(6) << ans << endl;
    } 
    
    return 0;
}
