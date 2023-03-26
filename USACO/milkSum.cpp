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
constexpr ll mod = 1e9+7;
constexpr ll mod2 = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; cin >> n;
    vector<pll> a(n+1);
    vector<ll> b(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = { b[i], i };
    }
    sort(all(a));
    vector<ll> c(n+1);
    for (ll i = 1; i <= n; i++) {
        c[i] = a[i].first;
    }
    //given the index j in b, find the index idx in a
    vector<ll> p(n+1);
    for (ll i = 1; i <= n; i++) {
        p[a[i].second] = i;
    }
    vector<ll> pre(n+2, 0);
    for (ll i = 1; i <= n; i++) {
        pre[i+1] = pre[i] + a[i].first;
    }

    ll t = 0;
    for (ll i = 1; i <= n; i++) {
        t += i*(a[i].first);
    }

    ll q; cin >> q;
    for (ll i = 0; i < q; i++) {
        ll j, x; cin >> j >> x;
        ll orig = b[j];
        ll tt = t;
        ll l = upper_bound(all(c), x) - c.begin();

        //T will be less
        if (orig > x) {
            tt -= orig*p[j];
            tt += l*x;
            tt += pre[p[j]] - pre[l];
        } else if (orig < x) {
            tt -= p[j] * orig;
            gg(tt);
            tt += (l-1)*x;
            gg(tt);
            gg(l, p[j]);
            tt -= pre[l] - pre[p[j]+1];
        }

        cout << tt << endl;
    }
    
    return 0;
}
