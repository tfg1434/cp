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

        ll sOdd = 0, sEven = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sEven += a[i];
            else sOdd += a[i];
        }

        if (sOdd <= sEven) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) cout << a[i] << " ";
                else cout << "1 ";
            }

        } else {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) cout << "1 ";
                else cout << a[i] << " ";
            }
        }

        cout << endl;
    }    
    
    return 0;
}

