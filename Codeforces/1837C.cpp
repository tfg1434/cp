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
    
    int T; cin >> T; while (T--) {
        string s; cin >> s;
        ll n = s.size();
        string ans = "";
        for (ll i = 0; i < n; i++) {
            if (s[i] != '?') {
                ans += s[i];
                gg(ans, i);
                continue;
            }

            ll j;
            for (j = i; s[j+1]=='?' && j < n-1; j++) ;

            if (i == 0 && j == n-1) {
                ans += string(j-i+1,'0');
            } else if (i == 0) {
            gg(ans, j);
                ans += string(j-i+1,s[j+1]);
            gg(ans);
            } else { //if (j == n-1) {
                ans += string(j-i+1,s[i-1]);
            } 

            i = j+1-1;//-1 bc loop ++
        }
        // for (ll i = 0; i < n; i++) {
            // char c = s[i];
            // if (i > 0 && s[i] == '?') {
                // c = s[i-1];
            // }
            // if (c != '?') {
                // ans += c;
                // s[i] = c;
            // }
        // }
        // for (ll i = n-1; i > 0; i--) {
            // char c = s[i];
            // if (s[i] == '?' && i < n-1) {
                // c = s[i+1];
            // }
            // ans = c + ans; 
        // }
        cout << ans << endl;
    } 
    
    return 0;
}
