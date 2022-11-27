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
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            char c; cin >> c;
            a[i] = c-'0';
        }
        for (ll i = 0; i < n; i++) {
            char c; cin >> c;
            b[i] = c-'0';
        }

        bool ok = true;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                ok = false;
                break;
            }
        }
        ok = ok || (a == b);
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<pll> ans;
        //arbitrary 0
        if (a[0] != b[0]) {
            ans.push_back({1,n});
            a=b;//we care abt b
        }

        vector<ll> cnt(n);
        for (ll i = 0; i < n; i++) {
            if (a[i]==1) {
                if (i == 0) {
                    ans.push_back({1,n});
                    ans.push_back({2,n});
                } else {
                    cnt[i]++;
                    cnt[i-1]++;
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            if (cnt[i] % 2 == 1){
                ans.push_back({1,i});
            }
        } 

        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << endl;
        }
    } 
    
    return 0;
}
