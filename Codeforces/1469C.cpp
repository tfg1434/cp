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
int n, k;


void solve() {
    cin >> n >> k;
    vector<int> h(n);
    for (auto& x : h) cin >> x;

    vector<pii> inr(n);
    inr[0] = { h[0], h[0]  };
    for (int i = 1; i < n; i++) {
        inr[i].first = max(h[i], inr[i-1].first-(k-1));
        inr[i].second = min(inr[i-1].second+(k-1), h[i]+(k-1));
        // cout << inr[i].first << " " << inr[i].second << endl;
        if (inr[i].second - inr[i].first < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    if (inr[n-1].first != h[n-1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();
    }    
    
    return 0;
}

