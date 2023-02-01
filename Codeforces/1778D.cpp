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

inline int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
 
    return x;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        gg(a,b);

        vector<ll> f(n+1);
        f[n] = 1;
        for (ll i = n-1; i >= 1; i--) {
            f[i] = (n + ((n - i)*f[i+1] % MOD))%MOD;
            f[i] = (f[i]*modInverse(i, MOD)) % MOD;
        }

        ll k = 0, ans = 0;
        for (ll i = 0; i < n; i++) if (a[i] != b[i]) k++;
        //BRUH. -1.5hr of life
        // for (ll i = k; k >= 1; k--) {
        for (ll i = k; i >= 1; i--) {
            ans += f[i];
            // gg(ans);
            ans = (ans + MOD)%MOD;
            gg(ans, i, f[i]);
        }

        cout << ans << endl;
    } 
    
    return 0;
}
