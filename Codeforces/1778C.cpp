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


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;

        set<ll> st;
        string a, b; cin >> a >> b;
        for(auto c : a)st.emplace(c);
        ll t = st.size();
        k = min(k, t);
        // vector<ll> cs(all(st));
        map<char, ll> id;
        ll p = 0;
        for (auto c : st) {
            id[c] = p++;
        }

        ll ans = 0;
        for (ll i = 0; i < (1 << t); i++) {
            if (__builtin_popcount(i) != k) continue;

            ll sum = 0, curr = 0;
            for (ll j = 0; j < n; j++) {
                if (a[j] == b[j] || i & (1 << id[a[j]])) {
                    curr++; sum += curr;
                } else {
                    curr = 0;
                }
            }
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }
    
    return 0;
}
