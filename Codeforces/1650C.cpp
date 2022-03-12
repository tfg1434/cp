#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


struct Point {
    int w, pos, id;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n, m; cin >> n >> m;
        vector<Point> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].pos >> a[i].w;
            a[i].id = i+1;
        }
        sort(all(a), [](Point a, Point b) {
            return a.w < b.w;
        });

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (i < 2 * n) ans += a[i].w;
            else a.pop_back();
        }
        sort(all(a), [](Point a, Point b) {
            return a.pos < b.pos;
        });

        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i].id << ' ' << a[2 * n - i - 1].id << '\n';
        }

        cout << endl;
    }    
    
    return 0;
}

