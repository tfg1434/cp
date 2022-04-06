#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IU(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int IUF = 1e9;
constexpr ll IUFF = 1e18;
string s;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> s;

        set<pii> st;
        int x = 0, y = 0;
        for (char c : s) {
            if (c == 'U') y++;
            if (c == 'D') y--;
            if (c == 'R') x++;
            if (c == 'L') x--;
            st.insert({x, y});
        }

        bool found = false;
        int ansX, ansY;
        for (auto [ox, oy] : st) {
            // cout << ox << " " << oy << endl;
            x = 0, y = 0;
            for (char c : s) {
                if (c == 'U' && !(x == ox && y == oy-1)) y++;
                if (c == 'D' && !(x == ox && y == oy+1)) y--;
                if (c == 'R' && !(y == oy && x == ox-1)) x++;
                if (c == 'L' && !(y == oy && x == ox+1)) x--;
            }
            if (x == 0 && y == 0) {
                found = true;
                ansX = ox, ansY = oy;
                break;
            }
        }

        if (found) cout << ansX << ' ' << ansY << '\n';
        else cout << "0 0\n";
    }    

    
    return 0;
}

