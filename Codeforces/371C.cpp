#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


ll cost(ll x, ll cb, ll nb, ll pb, ll cs, ll ns, ll ps, ll cc, ll nc, ll pc) {
    return max(0ll, cb*x - nb)*pb + max(0ll, cs*x - ns)*ps + max(0ll, cc*x - nc)*pc;
}

void solve() {
    string s; cin >> s;
    ll nb, ns, nc; cin >> nb >> ns >> nc;
    ll pb, ps, pc; cin >> pb >> ps >> pc;
    ll rubles; cin >> rubles;
    ll cb = count(all(s), 'B'), cs = count(all(s), 'S'), cc = count(all(s), 'C');

    ll ans = 0;
    ll l = 0, r = 1e14;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (cost(m, cb, nb, pb, cs, ns, ps, cc, nc, pc) <= rubles) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();    
    
    return 0;
}

