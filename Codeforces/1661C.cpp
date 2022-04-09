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
ll n;


ll solve(ll mx, ll n, const vector<ll>& a) {
    ll ones = 0, twos = 0;

    for (int i = 0; i < n; i++) {
        ll diff = mx - a[i];
        twos += diff / 2;
        ones += diff % 2;
    }

    ll ans = 0, pairs = min(ones, twos);
    ans = 2*pairs;
    ones -= pairs, twos -= pairs;
    ans += 4 * (twos / 3);
    
    ll rem = twos % 3;
    if (rem == 1) ans += 2;
    else if (rem == 2) ans += 3;

    if (ones > 0) ans += 2*ones-1;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<ll> h(n);
        for (auto& x : h) {
            cin >> x;
        }
        ll mx = *max_element(all(h));

        ll ans = INFF;
        ans = min({ ans, solve(mx, n, h), solve(mx+1, n, h) });

        cout << ans << '\n';
    }    
    
    return 0;
}

