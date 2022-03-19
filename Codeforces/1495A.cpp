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
        vector<int> ms, ds;
        for (int i = 0; i < 2*n; i++) {
            int x, y; cin >> x >> y;
            
            if (x == 0) ms.push_back(abs(y));
            else ds.push_back(abs(x));
        }
        assert(ms.size() == ds.size());

        sort(all(ms)); sort(all(ds));
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(pow(ds[i], 2) + pow(ms[i], 2));
        }

        //print answer with absolute or relative error less than 1e-9
        cout << fixed << setprecision(9) << ans << endl;
        // cout << fixed << setprecision(10) << ans << '\n';
        // cout << ans << '\n';
    }    
    
    return 0;
}

