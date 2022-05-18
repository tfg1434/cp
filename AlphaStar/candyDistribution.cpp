#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A & A <= C)
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
ll R[55][55];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k; cin >> n >> k;
    
    for (ll i = 0; i < k; i++) {
        char t; cin >> t;
        ll aa, b; cin >> aa >> b;
        
        ll val;
        if (t == 'D') val = 2;
        else val = 1;
        R[aa][b] = R[b][aa] = val;
    }
    
    vector<ll> a(n+1);
    auto check = [&](ll idx) {
        for (ll i = 0; i < idx; i++) {
            
            if (a[i] == a[idx] && R[i][idx] == 2) return false;
            
            if (a[i] != a[idx] && R[i][idx] == 1) return false;
        }
        return true;
    };

    ll ans = 0;
    y_combinator([&](auto rec, ll i) -> void {
        if (i > n) {
//            cout << a << endl;
            ans++;
            return;
        } 
        
        for (ll j = 1; j <= 3; j++) {
            a[i] = j;
            if (check(i)) rec(i+1);
        }
    })(1);
    
    cout << ans << endl;
    
    return 0;
}
