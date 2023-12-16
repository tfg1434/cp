#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FOR(i, a, b) for(ll (i) = (a); i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b+1)
#define tcT template<class T
#define mp make_pair
tcT> using V = vector<T>;
using vl = V<ll>;
#define pb push_back
#define eb emplace_back
#define sz(a) a.size()
#define all(a) begin(a), end(a)

ll logB(ll a, ll b) {
    return ceil(log(a)/log(b));
}

const ll N = 1e5+2;

void solve() {
    ll n, k; cin >> n >> k;

    ll T = logB(n, k);
    cout << T << '\n';
    ll m = n;
    vl a(n+1); iota(all(a), 0);
    FOR(i, 1, T+1) {
        cout << k << '\n';

        V<vl> v(k);
        F1R(i, n) {
            v[a[i]%k].eb(i);
            a[i] /= k;
        } 
        m /= k;

        F0R(i, k) {
            cout << sz(v[i]) << ' ';
            for (auto x : v[i]) cout << x << ' ';
            cout << '\n';
        }
    }
}

int main() {
    freopen("copii.in", "r" ,stdin);
    freopen("copii.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    solve();

    return 0;
}
