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
        int n, l, r; cin >> n >> l >> r;
        vector<int> c(n), cl(n, 0), cr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            c[i]--;
            if (i < 1) cl[c[i]]++;
            else cr[c[i]]++;
        }

        int remL = 0, remR = 0;
        for (int i = 0; i < n; i++) {
            int mn = min(cl[i], cr[i]);
            cl[i] -= mn; cr[i] -= mn;
            l -= mn; r -= mn;
            remL += cl[i] / 2; remR += cr[i] / 2;
        }

        //don't need to colour remL/remR
        cout << (l+r)/2 + max({0, (l-r)/2 - remL, (r-l)/2 - remR}) << '\n';
    }    
    
    return 0;
}

