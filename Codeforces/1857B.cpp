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
        s = '0' + s;
        ll n = s.size();
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = s[i]-'0';
        }

        vector<ll> b = a;
        ll lastRoundPos = n-1;
        for (ll i = n-2; i >= 0; i--) {
            if (a[i+1] < 5) continue;
            lastRoundPos = i;
            if (a[i] < 9) {
                a[i]++;
                b[i] = a[i];
            } else {
                // a[i] = 0;
                for (ll j = i; j >= 0; j--) {
                    if (a[j] < 9) {
                        a[j]++;
                        b[j] = a[j];
                        lastRoundPos = j;
                        break;
                    } else {
                        a[j] = 0;
                    }
                }
            }
        }

        vector<ll> ans;
        ll i = (b[0] == 0) ? 1 : 0;
        // gg(s, b);

        for (; i <= lastRoundPos; i++) {
            cout << b[i];
        }
        for (ll i = lastRoundPos+1; i < n; i++) {
            cout << '0';
        }
        cout << endl;
    } 
    
    return 0;
}

