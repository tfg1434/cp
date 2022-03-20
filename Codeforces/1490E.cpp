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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<int> b = a;
        sort(all(a));

        auto canWin = [&](int idx) {
            ll toks = a[idx];
            for (int i = 0; i < n; i++) {
                if (i == idx) continue;
                if (a[i] > toks) return false;
                toks += a[i];
            }
            return true;
        };

        int l = 0, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (canWin(mid)) r = mid;
            else l = mid;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (b[i] >= a[r]) ans.push_back(i + 1);

        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }    
    
    return 0;
}

