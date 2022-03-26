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

        if (n <= 2) {
            cout << "0\n";
            continue;
        }
        // if (!all_of(all(a), [&](int x) { return x == a[0]; })) {
            // cout << 0 << endl;
            // continue;
        // }
        // for (int i = 1; i < n; ++i)
            // if (a[i] == a[i - 1]) {
                // cout << -1 << endl;
                // continue;
            // }
        set<int> st;
        int mx = a[0];
        for (int i = 1; i < n; i++) {
            mx = max(mx, a[i]);
            st.insert(a[i] - a[i - 1]);
        }
        if (st.size() > 2) {
            cout << -1 << endl;
            continue;
        }
        if (st.size() == 1) {
            cout << 0 << endl;
            continue;
        }

        int a1 = *st.begin();
        st.erase(st.begin());
        int a2 = *st.begin();
        if ((a1 >= 0 && a2 >= 0) || (a1 <= 0 && a2 <= 0)) {
            cout << -1 << endl;
            continue;
        }
        if (a1 < a2) swap(a1, a2);
        //mx > m (a_{i} > m)
        if (mx > a1 - a2) {
            cout << -1 << endl;
            continue;
        }

        cout << a1 - a2 << ' ' << a1 << endl;
    }

    
    return 0;
}

