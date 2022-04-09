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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ll init = abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]);
            ll swp = abs(a[i-1] - b[i]) + abs(b[i-1] - a[i]);
            if (swp < init) {
                swap(a[i], b[i]);
            }
            ans += abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

