#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
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
const ll N = 2e5+5;
ll two[N];
// constexpr ll P = 998244353;

void put(ll x) {
    cout << "+ " << x << endl;
    ll code; cin >> code;
    if (code == -2) {
        exit(3);
    }
}

ll ask(ll x, ll y) {
    cout << "? " << x << ' ' <<  y << endl;
    ll res; cin >> res;
    return res;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> ans(n+1);
        put(n); put(n+1);
        ll u = (n+1)/2, idx;
        vector<ll> adv(n);
        adv[0] = u;
        for (ll i = 1; i < n; i++) {
            if ((n-i)%2==1) {
                adv[i] = adv[i-1]+i;
            } else {
                adv[i] = adv[i-1]-i;
            }
        }
        // cout << adv << endl;
        for (ll i = 1; i <= n; i++) {
            if (ask(i, i)!=-1) {
                idx = i;
                break;
            }
        }
        for (ll i = 1; i <= n; i++) {
            ll dist;
            if (idx == i){
                dist = 0;
            } else {
                dist = ask(idx, i);
            }
            ans[i] = adv[dist];
        }
        
        cout << '!';
        for (ll i = 1; i <= n; i++) {
            cout << ' ' << ans[i];
        }
        for (ll i = 1; i <= n; i++) {
            cout << ' ' << i;
        }
        cout << endl;
        
        ll code; cin >> code;
        if (code == -2) {
            exit(3);
        }
    }
    
    return 0;
}

