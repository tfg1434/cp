#include <bits/stdc++.h>
using namespace std;
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
        int n, m, x; cin >> n >> m >> x;
        set<pair<int, int>> st; //(height, idx)
        for (int i = 1; i <= m; i++) st.insert({0, i});

        cout << "YES\n";
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pair<int, int> p = *st.begin();
            st.erase(p);
            cout << p.second << ' ';
            st.insert({p.first + a[i], p.second});
        }
        cout << '\n';
    }    
    
    return 0;
}

