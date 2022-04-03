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

int gcd(int a, int b) { if (a == 0) return b; else return gcd (b % a, a); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //a little less than O(n^2) because we use a window
    //+k or -k to choose j
    int T; cin >> T; while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt = count(all(s), '1');
        if (cnt == 0) {
            cout << "0/1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != '1') continue;
            cnt += 2 * count(s.begin() + i + 1, s.begin() + i + k + 1, '1');
        }

        // int x = gcd(cnt, n*n);
        // cout << cnt / x << '/' << n*n / x << '\n';
    }    
    
    return 0;
}

