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
        //m days, n friends
        int n, m; cin >> n >> m;
        vector<vector<int>> a(m+1);
        vector<int> ans(m+1, 0);
        vector<pii> last;
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                a[i+1].push_back(x);
            }
            last.push_back({ k, i+1 });
        }

        //sort by # of available friends in non-decreasing order
        sort(all(last));
        map<int, int> mp;
        for (int i = 0; i < last.size(); i++) {
            for (int j = 0; j < a[last[i].second].size(); j++) {
                if (mp[a[last[i].second][j]] < (m+1) / 2) {
                    ans[last[i].second] = a[last[i].second][j];
                    mp[a[last[i].second][j]]++;
                    break;
                }
            }
        }
        
        bool ok = true;
        for (int i = 1; i <= m; i++)
            if (ans[i] == 0) {
                ok = false;
                break;
            }

        if (!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= m; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }    
    
    return 0;
}

