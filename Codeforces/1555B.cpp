#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int W, H; cin >> W >> H;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int w, h; cin >> w >> h;

        int ans = INT_MAX;
        if (w + x2 - x1 <= W) {
            ans = min(ans, max(0, w - x1));
            ans = min(ans, max(0, x2 - (W - w)));
        }

        if (h + y2 - y1 <= H) {
            ans = min(ans, max(0, h - y1));
            ans = min(ans, max(0, y2 - (H - h)));
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }    
    
    return 0;
}

