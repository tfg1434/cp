#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

// struct Diff {
    // int idx, curr, target;
// };
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr int NM = 100005;
int a[NM], b[NM], c[NM], ans[NM];
vector<vector<int>> v(NM); //target col, idx


void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i]) v[b[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) cin >> c[i];

    int last = -1;
    //b_{x} = c_{m} exists and must be changed
    if ((int) v[c[m-1]].size() > 0) {
        last = v[c[m-1]].back();
        v[c[m-1]].pop_back();

    } else {
        //b_{x} = c_{m} exists but is already correct
        for (int i = 0; i < n; i++) {
            if (b[i] == c[m-1]) {
                last = i;
                break;
            }
        }
    }

    if (last == -1) {
        cout << "NO" << endl;
        return;
    }

    ans[m-1] = last;
    for (int i = 0; i < m - 1; i++) {
        if ((int) v[c[i]].size() == 0) {
            ans[i] = last;
        } else {
            ans[i] = v[c[i]].back();
            v[c[i]].pop_back();
        }
    }

    //validate the solution
    for (int i = 1; i <= n; i++) {
        if ((int) v[i].size() > 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();

        // int n, m; cin >> n >> m;
        // vector<int> a(n); for (auto& x : a) cin >> x;
        // vector<int> b(n); for (auto& x : b) cin >> x;
        // vector<int> c(m); for (auto& x : c) cin >> x;
        
        // // vector<Diff> ds(n);
        // // for (int i = 0; i < n; i++) {
            // // if (a[i] != b[i]) ds.push_back({i, a[i], b[i]});
        // // }
        // map<int, vector<int>> mp;
        // for (int i = 0; i < n; i++) {
            // if (b[i] != a[i]) mp[b[i]].push_back(i);
        // }
        // vector<int> ans(m);
        
        // for (int i = 0; i < m; i++) {
            // int col = c[i];
            // if (!mp.count(col)) {
                // ans[i] = -1;
				// continue;
            // }

            // ans[i] = mp[col].back(); mp[col].pop_back();
        // }

        // for (int i = n-2; i >= 0; i--) {
            // if (a[i] == -1 && a[i+1] != -1) {
                // a[i] = a[i+1];
            // }
        // }

        // bool ok = true;
        // for (auto [k, v] : mp) {
            // if (!v.empty()) {
                // ok = false;
                // break;
            // }
        // }
        // if (!ok) {
            // cout << "NO" << endl;
            // continue;
        // } else {
            // cout << "YES" << endl;
            // for (auto x : ans) cout << x + 1 << " ";
            // cout << endl;
        // }
    }    
    
    return 0;
}

