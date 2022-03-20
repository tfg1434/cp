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
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }
        map<int, int> byCnt; //num occurences of each C
        for (auto [k, v] : m) {
            byCnt[v]++; 
        }

        int ans = n;
        int l = 0, r = n, rCnt = int(m.size());
        for (auto [k, v] : byCnt) {
            //k = C, v = num occurences of C
            ans = min(ans, l + r - rCnt * k);
            l += k * v;
            r -= k * v;
            rCnt -= v;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

