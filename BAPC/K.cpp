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

// THIS PROBLEM WAS A NIGHTMARE
// i mutated the xaxis/yaxis array which silently fucked up the other calculations...
// next time i will zero in on the testcase. sometimes it's faster to debug code, but
// only if it's a large code or large testcase. for simple code and simple tc, better
// to look at testcase
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

    for (int t = 0; t < m; t++) {
        for (auto p : add[t]) {
            acv[p] = 1;
            xaxis[xs[p]]++;
            yaxis[ys[p]]++;
        }

        for (int i = 0; i < n; i++) if (acv[i]) {

            if (((dir[i] % 2 == 0) && yaxis[ys[i]]%2 == 0) ||
                    ((dir[i] % 2 == 1) && xaxis[xs[i]]%2 == 0)) {
                dir[i] = (dir[i]+1)%4;
            } 

            // cout << i+1 << " is at " << xs[i] << ' ' << ys[i] << " and has direction " << "NESW"[dir[i]]<< endl;
        }

        for (int i = 0; i < n; i++) if (acv[i]) {
            xaxis[xs[i]]--;
            yaxis[ys[i]]--;
            xs[i] += d4x[dir[i]];
            ys[i] += d4y[dir[i]];
            xaxis[xs[i]]++;
            yaxis[ys[i]]++;
        }

        // cout << "After time " << t << " dir is: ";
        // for (int i = 0; i < n; i++) cout << dir[i] << " \n"[i==n-1];
        // cout << "After time " << t << " acv is: ";
        // for (int i = 0; i < n; i++) cout << acv[i] << " \n"[i==n-1];
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

