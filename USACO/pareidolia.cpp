#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
    string bessie = "bessie";
    
    string s; while (cin >> s) {
        ll n = s.size();
        map<char, vector<ll>> prev;
        for (char c : bessie) {
            prev[c] = vector<ll>(n, -1);
        }
        
        map<char, ll> last;
        for (char c : bessie) {
            last[c] = -1;
        }
        for (ll i = 0; i < n; i++) {
            for (char c : bessie) {
                prev[c][i] = last[c];
            }
            last[s[i]] = i;
        }
        gg(s);
        for (char c : bessie) {
            gg(prev[c]);
        }
        
        vector<ll> dp(n);
        for (ll i = 5; i < n; i++) {
            dp[i] = dp[i-1];
            if (s[i] != 'e') continue;
            
            ll x = i, idxB = -1;
            for (ll j = 4; j >= 0; j--) {
                gg(bessie[j], x);
                x = prev[bessie[j]][x];
                if (x == -1) {
                    break;
                }
                if (j == 0) {
                    idxB = x;
                }
            }
            
            dp[i] = dp[max(idxB-1, 0ll)]+idxB+1;
        }
        
        gg(dp);
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += dp[i];
        }
        
        cout << ans << endl;
    }
    
    return 0;
}


