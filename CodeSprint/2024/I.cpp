#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

int n, m, k;
V<array<int, 2>> a;
const int max_m = 2e5;
vi hats[max_m];
int step[max_m], mx[max_m], init_beauty;

void solve() {
    cin >> n >> m >> k; 
    for (int i = 0; i < m; i++) {
        cin >> step[i] >> mx[i];
    }
    for (int i = 0; i < n; i++) {
        int tp, x; cin >> tp >> x; tp--;
        hats[tp].pb(x);
        init_beauty += x;
    }
    for (int i = 0; i < max_m; i++) {
        sort(all(hats[i]));

        while (hats[i].size()) {
            if (hats[i].back() + step[i] > mx[i]) {
                int delta = 0;
                while (hats[i].size() && hats[i].back()+step[i] > mx[i]) {
                    delta += mx[i]-hats[i].back();
                    hats[i].pop_back();
                }
                delta += step[i]*hats[i].size();

                a.pb({delta, 1});
                mx[i] -= step[i];
            } else {
                int times = (mx[i]-hats[i].back())/step[i];
                a.pb({(int)hats[i].size()*step[i], times});
                mx[i] -= step[i]*times;
            }
        }
    }
    sort(all(a));
    int ans = 0;
    while (k > 0 && a.size()) {
        int cnt = min(k, a.back()[1]); k -= cnt;
        ans += cnt*a.back()[0];
        a.pop_back(); 
    }

    cout << init_beauty + ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
