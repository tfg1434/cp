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


void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    a.push_back('0'); b.push_back('0');
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] == '1') - (a[i] == '0');
        if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();

        //TLE
        //{zeros, ones}
        // vector<pii> pre(n); pre[0] = {a[0] == '0', a[0] == '1'};
        // for (int i = 1; i < n; i++)
            // pre[i] = { pre[i-1].first + (a[i] == '0'), pre[i-1].second + (a[i] == '1') };
        
        // bool ok = true;
        // for (int i = n-1; i >= 0; i--) {
            // if (a[i] == b[i]) continue;

            // if (pre[i].first != pre[i].second) {
                // ok = false;
                // break;
            // } else {
                // for (int j = 0; j <= i; j++)
                    // a[j] = a[j] == '0' ? '1' : '0';
            // }
        // }

        // cout << (ok ? "YES" : "NO") << '\n';
    }    
    
    return 0;
}

