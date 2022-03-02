#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
int a[200001];
pair<ll, ll> b[200001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = {a[i], i};
        }

        sort(b + 1, b + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                ll mult = b[i].first * b[j].first;
                if (mult == b[i].second + b[j].second) ans++;

                if (mult > 2 * n) break;
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

