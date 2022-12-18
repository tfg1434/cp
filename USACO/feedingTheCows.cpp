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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll ans = 0;
        string sa(n, '.');

        auto check = [&](ll l, char gh) -> void {
            if (s[l] != gh) return;
            ans++;
            sa[l+k] = gh;
            for (ll i = l; i <= l + 2*k; i++) {
                if (s[i] == gh) s[i] = '*';
            }
        };
        //sliding window of 2k+1
        for (ll i = 0; i <= n-2*k; i++) {
            check(i, 'G');
            check(i, 'H');
        }

        if (2*k <= n){
            bool mas = false;
            char cleared = s[n-2*k];
            for (ll i = n-2*k+1; i < n; i++) {
                if (s[i] != cleared) mas = true;
            }
            if (mas) {
                ans++;
                sa[n-2*k+1 + k] = (cleared == 'H' ? 'G' : 'H');
            }
        } else {
            bool hasG = false, hasH = false;
            for (ll i = 0; i < n; i++) {
                if (s[i] == 'G') hasG = true;
                if (s[i] == 'H') hasH = true;
            }
            if (hasG) sa[n/2] = 'G', ans++;
            if (hasH) sa[n/2+1] = 'H', ans++;
        }

        cout << ans << endl << sa << endl;
    }  
    
    return 0;
}
