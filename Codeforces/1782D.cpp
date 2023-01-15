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


// bool isSquare(ll n) {
    // return ceil((double)sqrt(n)) == floor((double)sqrt(n));
// }
inline bool pp(ll x)
{
    int r = sqrt(x);
    return (1ll * (r-1)*(r-1) == x || 1ll * r * r == x || 1ll * (r+1) * (r+1) == x);
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> v(n);
        for (auto& x : v) cin >> x;

        // if (n == 1) {
            // cout << "1\n";
            // continue;
        // }

        ll ans = 1;
        for (ll i = 0; i < n; i++) {
            for (ll j = i+1; j < n; j++) {
                ll a = v[i], b = v[j];
                if (a < b) swap(a, b);
                //a-b = (x+k)^2 - x^2
                //x = (a-b-k^2)/2k
                // bool found = false;
                ll x;
                for (ll k = 1; k * k <= a-b; k++) {
                    x = (a-b - k*k) / (2*k);
                    if (((a-b-k*k) % (2*k) != 0)/*|| (a-b-k*k < 0)*/) {
                        // found = false;
                        continue;
                    }
                    // if (a-b == (x+k)*(x+k) - x*x) {
                        // found = true;
                        // break;
                    // }
                    if (x*x >= v[i]) {
                        ll curr = 0;
                        for (ll k = 0; k < n; k++) {
                            if (pp(v[k]+(x*x - v[i]))) curr++;
                        }
                        ans = max(ans, curr);
                    }
                }
            }
        }
        // ll curr = 0;
        // for (ll k = 0; k < n; k++) {
            // if (isSquare(v[k])) curr++;
        // }
        // ans = max(ans, curr);

        cout << ans << endl;
    } 
    
    return 0;
}
