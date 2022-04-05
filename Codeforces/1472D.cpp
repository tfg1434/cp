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
int n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(rall(a));

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            //alice
            if (i % 2 == 0) {
                if (a[i] % 2 == 0) ans += a[i];
            //bob
            } else {
                if (a[i] % 2 == 1) ans -= a[i];
            }
        }

        if (ans < 0) cout << "Bob" << endl;
        else if (ans > 0) cout << "Alice" << endl;
        else cout << "Tie" << endl;
    }    
    
    return 0;
}

