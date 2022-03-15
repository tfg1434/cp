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
        for (int& x : a) cin >> x;
        map<int, pii> m1, m2; //[odd, even]
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) m1[a[i]].first++;
            else m1[a[i]].second++;
        }
        sort(all(a));
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) m2[a[i]].first++;
            else m2[a[i]].second++;
        }

        if (m1 == m2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }    
    
    return 0;
}

