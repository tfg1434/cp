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
vector<ll> a;
struct node {
    node *l, *r;
    ll v;
    node(node* tl, node* tr) {
        l = tl;
        r = tr;
        v = max(tl->v, tr->v);
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
    return max(r1, r2);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; while (cin >> n >> m) {
        a.resize(m);
        for (auto &x : a) cin >> x;

        node* t = build(0, m);
        ll q; cin >> q;
        // cout << query(t, 0, m, 0, 6) << '\n';
        for (ll i = 0; i < q; i++) {
            ll xs, ys, xf, yf, k; cin >> ys >> xs >> yf >> xf >> k;
            xs--; ys--; xf--; yf--;
            if (ys %k != yf%k || xs %k != xf%k) {
                cout << "NO" << endl;
                continue;
            }
            if (xs > xf) swap(xs, xf);

            ll mx = (n - ys - 1) /k*k + ys;
            // cout << mx << ' ' << query(t, 0, m, xs, xf) << ' ' << xs << ' ' << xf << '\n';
            cout << (query(t, 0, m, xs, xf) <= mx ? "YES" : "NO") << endl;

            // if (xs > xf) swap(xs, xf);
            // if (ys > yf) swap(ys, yf);
            // ll mx = query(t, 0, m, xs, xf);
            // //mx is 1-indexed
            // if (mx >= n-(yf % k)) {
                // cout << "NO" << endl;
            // } else {
                // cout << "YES" << endl;
            // }
        }
    }        
    
    return 0;
}

