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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 2e5+5;
ll a[N];
struct node {
    node *l, *r;
    ll v;
    node(node* tl, node* tr) {
        l = tl;
        r = tr;
        v = gcd(tl->v, tr->v);
    }
    node(ll x) {
        l = r = nullptr;
        v = x;
    }
};
node* build(ll tl, ll tr) {
    if (tl == tr - 1) return new node(a[tl]);
    else {
        ll tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm, tr));
    }
};
ll query(node* t, ll tl, ll tr, ll l, ll r) {
    if (l >= r) return 0;
    if (tl == l && tr == r) return t->v;
    ll tm = (tl + tr) / 2;
    ll r1 = query(t->l, tl, tm, l, min(r, tm));
    ll r2 = query(t->r, tm, tr, max(l, tm), r);
    return gcd(r1, r2);
}

inline int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

inline int lcm(int a, int b) { return a / gcd(a, b) * b; }



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; while (cin >> n) {
        for (ll i = 0; i < n; i++) cin >> a[i];
        node *t = build(0, n);
        vector<vector<ll>> segs(n);

        for (ll i = 0; i < n; i++) {
            ll l = i+1, r = n+1;
            ll res = i;
            while (l < r) {
                ll m = (l + r) / 2;
                if (query(t, 0, n, i, m) >= m - i) {
                    res = m;
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            if (query(t, 0, n, i, res) == res - i) {
                segs[res-1].push_back(i);
            }
        }

        ll ans = 0, last = -1;
        for (ll i = 0; i < n; i++) {
            for (auto x : segs[i]) {
                if (x > last) {
                    ans++;
                    last = i;
                }
            }
            cout << ans << ' ';
        }
        cout << endl;
    }    
    
    return 0;
}

