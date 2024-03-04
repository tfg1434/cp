#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using pl = pair<ll,ll>;
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
using vl = V<ll>;
using vpl = V<pl>;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define ins insert 
#define pb push_back
#define ft front()
#define bk back()

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
} 

map<ll, ll> xaxis, yaxis;
ll n, m;
ll d4x[4] = {0, 1, 0, -1};
ll d4y[4] = {1, 0, -1, 0};

void solve() {
    cin >> n >> m;

    V<vl> add(m);
    vl dir(n), xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        ll x, y, t; cin >> x >> y >> t;
        xs[i] = x;
        ys[i] = y;
        add[t].pb(i);
    }
    vl acv(n);

    auto move_player = [&](ll i, ll dx, ll dy) {
        auto& x = xs[i];
        auto& y = ys[i];
        xaxis[x]--; yaxis[y]--;
        x += dx; y += dy;
        xaxis[x]++; yaxis[y]++;
    };

    for (int t = 0; t < m; t++) {
        for (auto p : add[t]) {
            acv[p] = 1;
            xaxis[xs[p]]++;
            yaxis[ys[p]]++;
        }

        for (int i = 0; i < n; i++) if (acv[i]) {
            ll x = xs[i];
            ll y = ys[i];
            ll d = dir[i];
            // cout << i+1 << " is at " << x << ' ' << y << " and has direction " << "NESW"[d]<< endl;

            if (((d == 0 || d==2) && (yaxis[y]-1)%2 == 1) || ((d == 1 ||d==3) && (xaxis[x]-1)%2 == 1)) {
                dir[i] = (dir[i]+1)%4;
                d = dir[i];
            } 

            move_player(i, d4x[d], d4y[d]);
        }
    }    

    for (int i = 0; i < n; i++) {
        cout << xs[i] << ' ' << ys[i] << '\n';
    }
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}

