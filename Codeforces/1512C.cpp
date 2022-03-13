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


void solve() {
    int a, b; cin >> a >> b;
    int n = a + b;
    string s; cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = s[n-1-i];
    }
    a -= count(all(s), '0');
    b -= count(all(s), '1');

    for (int i = 0; i <= n/2; i++) {
        if (i != n-i-1 && s[i] == '?') {
            if (a > 1) s[i] = s[n-i-1] = '0', a -= 2;
            else if (b > 1) s[i] = s[n-i-1] = '1', b -= 2;

        //unset middle char
        } else if (s[i] == '?') {
            if (a % 2 == 1) s[i] = '0', a--;
            else s[i] = '1', b--;
        }
    }

    string copy = s;
    reverse(all(copy));
    if (s == copy && a == 0 && b == 0) {
        cout << s << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();
    }    
    
    return 0;
}

